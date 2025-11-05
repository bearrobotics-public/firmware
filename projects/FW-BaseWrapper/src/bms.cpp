#include "example_node/bms.h"
#include "example_node/BmsReport.h"
#include "example_node/bms_packets.h"

namespace bear {
namespace example_node {

BMS::BMS(ros::NodeHandle &nh, std::string pc_ip, int bms_port_rx)
    : Base(nh, pc_ip, bms_port_rx, sizeof(BMS_PACKET),
           std::bind(&BMS::messageReceivedCallback, this, std::placeholders::_1,
                     std::placeholders::_2)) {
  ROS_INFO("BMS constructor");
  bms_report_pub_ = nh_.advertise<::example_node::BmsReport>("bms_report", 10);
  bms_report_pub_ready_ = true;
}

BMS::~BMS() { ROS_INFO("BMS destructor"); }

std::shared_ptr<BMS_PACKET>
BMS::NetworkToHost(std::shared_ptr<BMS_PACKET> network_packet, int size) {
  if (size != sizeof(BMS_PACKET)) {
    ROS_ERROR("BMS message received with incorrect size");
    return nullptr;
  }

  std::shared_ptr<BMS_PACKET> host_packet = std::make_shared<BMS_PACKET>();
  host_packet->header.sec =
      static_cast<int32_t>(ntohl(network_packet->header.sec));
  host_packet->header.nsec =
      static_cast<int32_t>(ntohl(network_packet->header.sec));

  host_packet->valid_data_bit = ntohl(network_packet->valid_data_bit);
  host_packet->version = ntohs(network_packet->version);
  host_packet->number_of_cells = ntohs(network_packet->number_of_cells);
  host_packet->temperature = ntohs(network_packet->temperature);
  host_packet->total_voltage = ntohs(network_packet->total_voltage);
  host_packet->current = static_cast<int32_t>(ntohs(network_packet->current));
  host_packet->relative_state_of_charge =
      ntohs(network_packet->relative_state_of_charge);
  host_packet->remaining_capacity = ntohs(network_packet->remaining_capacity);
  host_packet->full_charge_capacity =
      ntohs(network_packet->full_charge_capacity);
  host_packet->charging_current = ntohs(network_packet->charging_current);
  host_packet->charging_voltage = ntohs(network_packet->charging_voltage);
  host_packet->battery_status = ntohs(network_packet->battery_status);
  host_packet->control_flag_status = ntohs(network_packet->control_flag_status);
  host_packet->relative_state_of_health =
      ntohs(network_packet->relative_state_of_health);

  constexpr size_t kMaxCellNum = 7;
  for (size_t cell_num = 0; cell_num < kMaxCellNum; ++cell_num) {
    host_packet->voltage_of_cell[cell_num] =
        ntohs(network_packet->voltage_of_cell[cell_num]);
  }

  host_packet->write_lock_flag_status =
      ntohs(network_packet->write_lock_flag_status);
  host_packet->operation_status = ntohs(network_packet->operation_status);
  host_packet->total_cell_voltage = ntohs(network_packet->total_cell_voltage);
  host_packet->pack_voltage = ntohs(network_packet->pack_voltage);
  host_packet->pack_status = ntohs(network_packet->pack_status);
  host_packet->cell_balancing_status =
      ntohs(network_packet->cell_balancing_status);
  host_packet->fault_status = ntohs(network_packet->fault_status);
  host_packet->checksum_of_fw = ntohs(network_packet->checksum_of_fw);
  host_packet->checksum_of_fixed_data =
      ntohs(network_packet->checksum_of_fixed_data);

  return host_packet;
}

void BMS::messageReceivedCallback(std::shared_ptr<void> packet, int size) {
  std::shared_ptr<BMS_PACKET> bms_packet =
      NetworkToHost(std::static_pointer_cast<BMS_PACKET>(packet), size);
  if (bms_packet == nullptr) {
    return;
  }

  if (!bms_report_pub_ready_) {
    ROS_ERROR("BMS report publisher not ready, dropping message");
    return;
  }

  ROS_DEBUG("BMS message received with size: %d", size);

  ::example_node::BmsReport bms_msg;
  bms_msg.header.stamp = ros::Time::now();

  constexpr double kMilliPerBase = 1000.0;
  constexpr double kCentiPerBase = 100.0;
  constexpr double kKelvinToCelsiusOffset = -273.15;

  bms_msg.temperature = (static_cast<double>(bms_packet->temperature) / 10.0) +
                        kKelvinToCelsiusOffset;
  bms_msg.total_voltage =
      static_cast<double>(bms_packet->total_voltage) / kMilliPerBase;
  bms_msg.current = static_cast<double>(bms_packet->current) / kMilliPerBase;

  bms_msg.relative_state_of_charge =
      static_cast<double>(bms_packet->relative_state_of_charge) / kCentiPerBase;
  bms_msg.remaining_capacity =
      static_cast<double>(bms_packet->remaining_capacity) / kMilliPerBase;
  bms_msg.full_charge_capacity =
      static_cast<double>(bms_packet->full_charge_capacity) / kMilliPerBase;
  bms_msg.charging_current =
      static_cast<double>(bms_packet->charging_current) / kMilliPerBase;
  bms_msg.charging_voltage =
      static_cast<double>(bms_packet->charging_voltage) / kMilliPerBase;

  bms_msg.relative_state_of_health =
      static_cast<double>(bms_packet->relative_state_of_health) /
      pow(kCentiPerBase, 2);
  bms_msg.cell_voltages.resize(bms_packet->number_of_cells);
  for (uint16_t i = 0; i < bms_packet->number_of_cells; i++) {
    bms_msg.cell_voltages[i] =
        static_cast<double>(bms_packet->voltage_of_cell[i]) / kMilliPerBase;
  }
  bms_msg.total_cell_voltage =
      static_cast<double>(bms_packet->total_cell_voltage) / kMilliPerBase;
  bms_msg.pack_voltage =
      static_cast<double>(bms_packet->pack_voltage) / kMilliPerBase;

  bms_msg.operation_status =
      static_cast<uint16_t>(bms_packet->operation_status);
  bms_report_pub_.publish(bms_msg);
}

} // namespace example_node
} // namespace bear
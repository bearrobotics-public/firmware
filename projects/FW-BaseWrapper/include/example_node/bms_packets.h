#ifndef EXAMPLE_NODE_BMS_PACKETS_H
#define EXAMPLE_NODE_BMS_PACKETS_H

#include "example_node/packet_headers.h"
#include <cstdint>

namespace bear {
namespace example_node {

typedef packed_arm struct BMS_PACKET_t {
  TSNetPacketHeader header;
  uint32_t valid_data_bit; // mask of which fields were successfully updated
  uint16_t version;        // firmware version
  uint16_t number_of_cells;
  uint16_t temperature;              // 0.1K
  uint16_t total_voltage;            // mV
  int16_t current;                   // mA
  uint16_t relative_state_of_charge; //%
  uint16_t remaining_capacity;       // mAh
  uint16_t full_charge_capacity;     // mAh
  uint16_t charging_current;         // mA
  uint16_t charging_voltage;         // mV
  uint16_t battery_status;
  uint16_t control_flag_status;
  uint16_t relative_state_of_health; // Milli%
  uint16_t voltage_of_cell[7];       // mV
  uint16_t write_lock_flag_status;
  uint16_t operation_status;
  uint16_t total_cell_voltage; // mV
  uint16_t pack_voltage;       // mV
  uint16_t pack_status;
  uint16_t cell_balancing_status;
  uint16_t fault_status;
  uint16_t checksum_of_fw;         // checksum of bms firmware
  uint16_t checksum_of_fixed_data; // checksum of bms chip configuration
} packed_gcc BMS_PACKET;
} // namespace example_node
} // namespace bear
#endif // EXAMPLE_NODE_BMS_PACKETS_H

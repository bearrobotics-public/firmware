#include "example_node/motor.h"

#include "example_node/MotorCommand.h"
#include "example_node/MotorReport.h"
#include "example_node/network_utils.h"

#include <ros/ros.h>
#include <std_srvs/SetBool.h>
#include <cmath>

namespace bear {
namespace example_node {

#define RPM_THRESHOLD 0.0001f

Motor::Motor(ros::NodeHandle &nh, std::string pc_ip, std::string baseboard_ip,
             int motor_cmd_port_tx, int motor_resp_port_rx)
    : Base(nh, pc_ip, baseboard_ip, motor_cmd_port_tx, motor_resp_port_rx,
           sizeof(NetSendMotorPacketV2),
           std::bind(&Motor::messageReceivedCallback, this,
                     std::placeholders::_1, std::placeholders::_2)) {
  ROS_INFO("Motor constructor");

  enable_motor_srv_ =
      nh_.advertiseService("set_enable_motor", &Motor::setEnableMotor, this);
  motor_speed_sub_ =
      nh_.subscribe("motor_speed", 10, &Motor::setMotorSpeed, this);
  motor_report_pub_ =
      nh_.advertise<::example_node::MotorReport>("motor_report", 10);
  motor_report_pub_ready_ = true;

  timer_ =
      nh_.createTimer(ros::Duration(1.0 / rate_), &Motor::sendMotorSpeed, this);
}

Motor::~Motor() {
  ROS_INFO("Motor destructor");
  enable_motor_srv_.shutdown();
}

bool Motor::sendEnableMotor(bool enable) {
  NetMotorPacketV2 packet;
  packet.header.seq_num = seq_num_++;
  packet.param = static_cast<MOTOR_PARAM>(htonl(MOTOR_PARAM_ENABLE_MOTOR));
  packet.arg1.f32 = enable ? htonf(1.0f) : htonf(0.0f);
  packet.arg2.f32 = enable ? htonf(1.0f) : htonf(0.0f);
  return sendPacket(packet) == sizeof(NetMotorPacketV2);
}

bool Motor::setEnableMotor(std_srvs::SetBool::Request &req,
                           std_srvs::SetBool::Response &res) {

  res.success = sendEnableMotor(req.data);
  res.message =
      std::string("Motor enable set to ") + (req.data ? "true" : "false");
  return true;
}

void Motor::sendMotorSpeed(const ros::TimerEvent &event) {
  NetMotorPacketV2 packet;
  packet.header.seq_num = seq_num_++;
  packet.param = static_cast<MOTOR_PARAM>(htonl(MOTOR_PARAM_SPEED_KRPM));
  packet.arg1.f32 = htonf(RPM_L_);
  packet.arg2.f32 = htonf(RPM_R_);
  if (sendPacket(packet) != sizeof(NetMotorPacketV2)) {
    ROS_ERROR("Failed to send motor speed packet");
  }
}

void Motor::setMotorSpeed(const ::example_node::MotorCommand &command) {
  RPM_L_ = command.RPM_L;
  RPM_R_ = command.RPM_R;
}

int Motor::sendPacket(NetMotorPacketV2 &packet) {
  return Base::sendPacket(static_cast<void *>(&packet),
                          sizeof(NetMotorPacketV2));
}

void Motor::messageReceivedCallback(std::shared_ptr<void> packet, int size) {
  ROS_DEBUG("Motor message received with size: %d", size);
  if (size != sizeof(NetSendMotorPacketV2)) {
    ROS_ERROR("Motor message received with incorrect size");
    return;
  }
  std::shared_ptr<NetSendMotorPacketV2> motor_packet =
      std::static_pointer_cast<NetSendMotorPacketV2>(packet);

  auto motor_param = static_cast<MOTOR_PARAM>(ntohl(motor_packet->param));
  ROS_DEBUG("Motor message received: %d", motor_param);

  switch (motor_param) {
  case MOTOR_PARAM_ENCODER_VEL: { // current speed in RPM
    if (!motor_report_pub_ready_) {
      ROS_ERROR("Motor report publisher not ready, dropping message");
      return;
    }

    ::example_node::MotorReport report;

    report.RPM_L = ntohf(motor_packet->arg1.f32);
    if (std::abs(report.RPM_L) < RPM_THRESHOLD) {
      report.RPM_L = 0.0f;
    }
    report.RPM_R = ntohf(motor_packet->arg2.f32);
    if (std::abs(report.RPM_R) < RPM_THRESHOLD) {
      report.RPM_R = 0.0f;
    }
    report.status_L = ntohl(motor_packet->arg3.u32);
    report.status_R = ntohl(motor_packet->arg4.u32);
    motor_report_pub_.publish(report);
    break;
  }
  default:
    ROS_ERROR("Motor message received with unknown parameter: %d", motor_param);
    break;
  }
}
} // namespace example_node
} // namespace bear

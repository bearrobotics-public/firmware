#ifndef EXAMPLE_NODE_MOTOR_H
#define EXAMPLE_NODE_MOTOR_H

#include "example_node/MotorCommand.h"
#include "example_node/motor_packets.h"

#include "example_node/base.h"
#include <ros/ros.h>
#include <ros/rate.h>
#include <ros/timer.h>
#include <std_srvs/SetBool.h>

namespace bear {
namespace example_node {
class Motor : public Base {

public:
  explicit Motor(ros::NodeHandle &nh, std::string pc_ip,
                 std::string baseboard_ip, int motor_cmd_port_tx,
                 int motor_resp_port_rx);
  bool sendEnableMotor(bool enable);
  bool setEnableMotor(std_srvs::SetBool::Request &req,
                      std_srvs::SetBool::Response &res);
  void sendMotorSpeed(const ros::TimerEvent &event);
  void setMotorSpeed(const ::example_node::MotorCommand &command);
  ~Motor();

private:
  int sendPacket(NetMotorPacketV2 &packet);
  void messageReceivedCallback(std::shared_ptr<void> packet, int size);

  bool motor_report_pub_ready_{false};
  ros::ServiceServer enable_motor_srv_;
  ros::Subscriber motor_speed_sub_;
  ros::Publisher motor_report_pub_;

  std::atomic<float> RPM_L_{0.0f};
  std::atomic<float> RPM_R_{0.0f};

  float rate_{100.0}; // Hz
  ros::Timer timer_;
};

} // namespace example_node
} // namespace bear
#endif // EXAMPLE_NODE_MOTOR_H

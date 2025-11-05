#include "example_node/bms.h"
#include "example_node/motor.h"
#include <ros/ros.h>
#include <string>

int main(int argc, char **argv) {
  ros::init(argc, argv, "example_node");
  ros::NodeHandle nh("~");

  std::string pc_ip;
  std::string baseboard_ip;
  int motor_cmd_port_tx = 0;
  int motor_resp_port_rx = 0;
  int bms_port_rx = 0;

  if (!nh.getParam("pc_ip", pc_ip)) {
    ROS_FATAL("Missing required parameter: pc_ip");
    return 1;
  }
  ROS_INFO("pc_ip: %s", pc_ip.c_str());

  if (!nh.getParam("baseboard_ip", baseboard_ip)) {
    ROS_FATAL("Missing required parameter: baseboard_ip");
    return 1;
  }
  ROS_INFO("baseboard_ip: %s", baseboard_ip.c_str());

  if (!nh.getParam("motor_cmd_port_tx", motor_cmd_port_tx)) {
    ROS_FATAL("Missing required parameter: motor_cmd_port_rx");
    return 1;
  }
  ROS_INFO("motor_cmd_port_tx: %d", motor_cmd_port_tx);

  if (!nh.getParam("motor_resp_port_rx", motor_resp_port_rx)) {
    ROS_FATAL("Missing required parameter: motor_resp_port_rx");
    return 1;
  }
  ROS_INFO("motor_resp_port_rx: %d", motor_resp_port_rx);

  if (!nh.getParam("bms_port_rx", bms_port_rx)) {
    ROS_FATAL("Missing required parameter: bms_port_rx");
    return 1;
  }
  ROS_INFO("bms_port_rx: %d", bms_port_rx);

  bear::example_node::Motor motor(nh, pc_ip, baseboard_ip, motor_cmd_port_tx,
                                  motor_resp_port_rx);
  bear::example_node::BMS bms(nh, pc_ip, bms_port_rx);

  ros::spin();
  return 0;
}

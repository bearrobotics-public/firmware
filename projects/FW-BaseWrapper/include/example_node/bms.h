#ifndef EXAMPLE_NODE_BMS_H
#define EXAMPLE_NODE_BMS_H

#include "example_node/base.h"
#include "example_node/bms_packets.h"

namespace bear {
namespace example_node {
class BMS : public Base {

public:
  explicit BMS(ros::NodeHandle &nh, std::string pc_ip, int bms_port_rx);
  ~BMS();

private:
  std::shared_ptr<BMS_PACKET>
  NetworkToHost(std::shared_ptr<BMS_PACKET> network_packet, int size);
  void messageReceivedCallback(std::shared_ptr<void> packet, int size);

  bool bms_report_pub_ready_{false};
  ros::Publisher bms_report_pub_;
};

} // namespace example_node
} // namespace bear
#endif // EXAMPLE_NODE_BMS_H

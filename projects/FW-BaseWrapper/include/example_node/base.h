#ifndef EXAMPLE_NODE_BASE_H
#define EXAMPLE_NODE_BASE_H

#include <atomic>
#include <cstdint>
#include <functional>
#include <memory>
#include <netinet/in.h>
#include <ros/ros.h>
#include <thread>

namespace bear {
namespace example_node {

class Base {
public:
  explicit Base(
      ros::NodeHandle &nh, std::string pc_ip, int rx_port,
      size_t rx_buffer_size,
      std::function<void(std::shared_ptr<void>, int)> message_publisher);
  explicit Base(
      ros::NodeHandle &nh, std::string pc_ip, std::string baseboard_ip, int tx_port, int rx_port,
      size_t rx_buffer_size,
      std::function<void(std::shared_ptr<void>, int)> message_publisher);

  ~Base();

protected:
  ros::NodeHandle &nh_;
  int sendPacket(void *packet, int packet_size);
  uint32_t seq_num_{0};

private:
  bool init_rx_socket(std::string pc_ip, int rx_port);
  bool init_tx_socket(std::string baseboard_ip, int tx_port);
  bool init_rx_thread();

  int recvPacket(void *packet, int packet_size);
  void rxThread();

  bool initialized_{false};
  const size_t rx_buffer_size_;

  std::function<void(std::shared_ptr<void>, int)> message_publisher_;

  std::atomic<bool> running_{true};
  std::thread rx_thread_;

  sockaddr_in tx_addr_{0};
  sockaddr_in rx_addr_{0};

  int tx_socket_fd_{-1};
  int rx_socket_fd_{-1};
};

} // namespace example_node
} // namespace bear
#endif // EXAMPLE_NODE_BASE_H

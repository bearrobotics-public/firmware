#include "example_node/base.h"

#include <arpa/inet.h>
#include <cstring>

namespace bear {
namespace example_node {
Base::Base(ros::NodeHandle &nh, std::string pc_ip, int rx_port,
           size_t rx_buffer_size,
           std::function<void(std::shared_ptr<void>, int)> message_publisher)
    : nh_(nh), rx_buffer_size_(rx_buffer_size),
      message_publisher_(std::move(message_publisher)) {
  ROS_INFO("Base constructor");

  if (!init_rx_socket(pc_ip, rx_port)) {
    ROS_ERROR("Failed to initialize rx socket");
    return;
  }

  if (!init_rx_thread()) {
    ROS_ERROR("Failed to initialize rx thread");
    return;
  }

  initialized_ = true;
  ROS_INFO("Base initialized");
}

Base::Base(ros::NodeHandle &nh, std::string pc_ip, std::string baseboard_ip,
           int tx_port, int rx_port, size_t rx_buffer_size,
           std::function<void(std::shared_ptr<void>, int)> message_publisher)
    : nh_(nh), rx_buffer_size_(rx_buffer_size),
      message_publisher_(std::move(message_publisher)) {
  ROS_INFO("Base constructor");

  if (!init_tx_socket(baseboard_ip, tx_port)) {
    ROS_ERROR("Failed to initialize tx socket");
    return;
  }

  if (!init_rx_socket(pc_ip, rx_port)) {
    ROS_ERROR("Failed to initialize rx socket");
    return;
  }

  if (!init_rx_thread()) {
    ROS_ERROR("Failed to initialize rx thread");
    return;
  }

  initialized_ = true;
  ROS_INFO("Base initialized");
}

Base::~Base() {
  ROS_INFO("Base destructor");
  if (initialized_) {
    running_ = false;
    if (rx_thread_.joinable()) {
      rx_thread_.join();
    }
    if (rx_socket_fd_ >= 0) {
      close(rx_socket_fd_);
      rx_socket_fd_ = -1;
    }
    if (tx_socket_fd_ >= 0) {
      close(tx_socket_fd_);
      tx_socket_fd_ = -1;
    }
  }
  initialized_ = false;
}

bool Base::init_rx_socket(std::string pc_ip, int rx_port) {
  // Create a POSIX UDP socket for receiving
  rx_socket_fd_ = socket(AF_INET, SOCK_DGRAM, 0);
  if (rx_socket_fd_ < 0) {
    ROS_ERROR("Failed to create rx_socket: %s", strerror(errno));
    return false;
  }

  memset(&rx_addr_, 0, sizeof(rx_addr_));
  rx_addr_.sin_family = AF_INET;
  rx_addr_.sin_port = htons(rx_port);
  if (inet_aton(pc_ip.c_str(), &rx_addr_.sin_addr) == 0) {
    fprintf(stderr,
            "%s:%d: ERROR: Failed to resolve "
            "IP Address: %s and Port: %d with error: %s\n",
            __FUNCTION__, __LINE__, pc_ip.c_str(), rx_port, strerror(errno));
    close(rx_socket_fd_);
    rx_socket_fd_ = -1;
    return false;
  }

  if (bind(rx_socket_fd_, (struct sockaddr *)&rx_addr_, sizeof(rx_addr_)) < 0) {
    ROS_ERROR("Failed to bind rx_socket: %s", strerror(errno));
    close(rx_socket_fd_);
    rx_socket_fd_ = -1;
    return false;
  }
  return true;
}

bool Base::init_tx_socket(std::string baseboard_ip, int tx_port) {
  // Create a POSIX UDP socket for transmitting
  tx_socket_fd_ = socket(AF_INET, SOCK_DGRAM, 0);
  if (tx_socket_fd_ < 0) {
    ROS_ERROR("Failed to create tx_socket: %s", strerror(errno));
    return false;
  }

  memset(&tx_addr_, 0, sizeof(tx_addr_));
  tx_addr_.sin_family = AF_INET;
  tx_addr_.sin_port = htons(tx_port);
  if (inet_aton(baseboard_ip.c_str(), &tx_addr_.sin_addr) == 0) {
    fprintf(stderr,
            "%s:%d: ERROR: Failed to resolve "
            "IP Address: %s and Port: %d with error: %s\n",
            __FUNCTION__, __LINE__, baseboard_ip.c_str(), tx_port,
            strerror(errno));
    close(tx_socket_fd_);
    tx_socket_fd_ = -1;
    return false;
  }

  return true;
}

bool Base::init_rx_thread() {
  rx_thread_ = std::thread(&Base::rxThread, this);
  return true;
}

int Base::sendPacket(void *packet, int packet_size) {
  if (!initialized_) {
    ROS_ERROR("Base not initialized, cannot send packet");
    return -1;
  }
  if (tx_socket_fd_ < 0) {
    ROS_ERROR("Failed to send packet: tx socket not initialized");
    return -1;
  }
  return sendto(tx_socket_fd_, packet, packet_size, 0,
                (struct sockaddr *)&tx_addr_, sizeof(tx_addr_));
}

int Base::recvPacket(void *packet, int packet_size) {
  if (!initialized_) {
    ROS_ERROR("Base not initialized, cannot receive packet");
    return -1;
  }
  if (rx_socket_fd_ < 0) {
    ROS_ERROR("Failed to receive packet: rx socket not initialized");
    return -1;
  }
  socklen_t addr_len = sizeof(rx_addr_);
  return recvfrom(rx_socket_fd_, packet, packet_size, 0,
                  (struct sockaddr *)&rx_addr_, &addr_len);
}

void Base::rxThread() {
  while (running_) {
    std::shared_ptr<char> buffer(new char[rx_buffer_size_],
                                 std::default_delete<char[]>());
    int bytes_received = recvPacket(buffer.get(), rx_buffer_size_);
    message_publisher_(std::static_pointer_cast<void>(buffer), bytes_received);
  }
}

} // namespace example_node
} // namespace bear

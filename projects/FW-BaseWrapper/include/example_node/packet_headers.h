#ifndef EXAMPLE_NODE_PACKET_HEADERS_H
#define EXAMPLE_NODE_PACKET_HEADERS_H

#include <cstdint>

#if defined(__CC_ARM)
#define packed_arm __packed
#define packed_gcc
#else
#define packed_arm
#define packed_gcc __attribute__((packed))

#endif
typedef packed_arm struct net_packet_header_t {
  uint8_t seq_num;   ///< 8 bit sequence number
  uint8_t checksum;  ///< 8-bit checksum
  uint8_t reserved2; ///< pad byte
  uint8_t reserved3; ///< pad byte

} packed_gcc NetPacketHeader;

/// Network packet header with timstamps, used in some network packets
typedef packed_arm struct ts_net_packet_header_t {
  uint8_t seq_num;   ///< 8-bit sequence number
  uint8_t checksum;  ///< pad byte
  uint8_t reserved2; ///< pad byte
  uint8_t reserved3; ///< pad byte
  int32_t sec;       ///< timestamp seconds
  int32_t nsec;      ///< timestamp nano seconds
} packed_gcc TSNetPacketHeader;

#endif // EXAMPLE_NODE_PACKET_HEADERS_H

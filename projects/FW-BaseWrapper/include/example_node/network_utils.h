#ifndef _NETWORK_UTILS_H_
#define _NETWORK_UTILS_H_

#include <arpa/inet.h>
#include <cstdint>

/// convert a float32 from network to host byte order
inline float ntohf(float f) {
  uint32_t val = ntohl(*reinterpret_cast<uint32_t*>(&f));
  return *(reinterpret_cast<float*>(&val));
}

/// convert a float32 from host to network byte order
inline float htonf(float f) {
  uint32_t val = htonl(*reinterpret_cast<uint32_t*>(&f));
  return *(reinterpret_cast<float*>(&val));
}

#endif  // _NETWORK_UTILS_H_

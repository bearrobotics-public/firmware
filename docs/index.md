## Introduction

This document describes the **BaseBoard API**, which defines the low-level communication protocol between the robot's firmware and the ROS driver. The BaseBoard API enables the ROS driver to:

1. **Send control commands** to the firmware (e.g., motor control, system commands, power management)
2. **Receive sensor data and status updates** from the firmware (e.g., IMU data, battery status, motor feedback)
3. **Monitor system status** and handle logging information from the firmware

This API operates at the firmware level and uses UDP-based binary packet communication. For detailed packet specifications and field layouts, please navigate through the **API Reference** section.

## Overview

### Communication Method

Communication between the firmware and the ROS driver is established over **UDP (User Datagram Protocol)**. The firmware is configured with a static IP address (**10.2.98.200**), and each packet type is assigned a different UDP port. All packets defined in this document are exchanged through these dedicated ports.

### Communication Direction

The BaseBoard API supports bidirectional communication:

**Firmware → ROS driver** (Sensor data reports):  

- Motor feedback (current speed, status)  
- IMU (Inertial Measurement Unit) data (acceleration, gyroscope, compass, quaternion)  
- MainComs status reports (power switch status, E-stop state, version information)  
- CAN bus data from Top Controller  
- BMS (Battery Management System) data (voltage, current, temperature, state of charge)  
- ChargerManager status (charging state information)  
- Log messages (encoded in Protocol Buffers)
  
**ROS driver → Firmware** (Control commands):  

- Motor control commands (target speed, tuning parameters)  
- MainComs commands (shutdown, emergency stop, power switch control, version queries)  
- CAN bus commands (to control Top Controller devices)  
- BaseLedCommand (LED control for robot base)  

Some packet types (Motor and MainComs) support **bidirectional communication**, where the packet structure differs depending on the communication direction.

### Packet Structure

All packets use one of two header types:

- **Timestamp Header**: Contains a relative timestamp indicating elapsed time since firmware boot. Used for sensor data packets that require temporal correlation (e.g., IMU, Motor feedback, BMS).
- **Non-Timestamp Header**: Used for command packets or data where timing information is not critical (e.g., MainComs commands, BaseLedCommand).

Each packet header includes:

- **Sequence Number** (0-255): Independently maintained per packet type, incremented with every transmission. Used for duplicate detection and packet ordering.
- **Checksum**: Reserved for future use (currently always 0).

### Packet Reliability Considerations

Since the BaseBoard API uses UDP, which provides **best-effort delivery**:

- **No delivery guarantees**: Packets may be lost, duplicated, or arrive out of order.
- **Sequence numbers**: Use sequence numbers for duplicate detection within each packet type.
- **No explicit acknowledgments**: Most commands do not generate acknowledgment packets. Command execution status is typically reported through periodic status packets.
- **Timeout handling**: Clients should implement appropriate timeout mechanisms for critical operations.
- **Periodic reports**: The firmware periodically transmits status and sensor data at fixed intervals (varies by packet type: 10ms for IMU, 100ms for ChargerManager, 500ms for BMS, etc.).

For detailed packet specifications, field layouts, port numbers, and usage guidelines, please refer to the individual packet documentation in the **API Reference** section.
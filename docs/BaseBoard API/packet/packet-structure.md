# Packet Structure

## Overview
Generally, packets from the firmware are used to report sensor data and the status of the firmware system.  
On the other hand, packets from the ROS driver are command packets that provide control instructions to the firmware.  
Therefore, some packets may share the same name, but their structures differ depending on the communication direction.  

Packets sent from the firmware to the ROS driver  

- The following packet types are transmitted from the firmware to the ROS driver:  
    - Motor  
    - IMU  
    - MainComs  
    - CAN  
    - BMS  
    - ChargerManager  
    - Logging  

Packets sent from the ROS driver to the firmware  

- The following packet types are transmitted from the ROS driver to the firmware:  
    - Motor  
    - MainComs  
    - CAN  
    - BaseLedCommand  

## Common Headers  
There are two types of header structures used in the packets.

### Timestamp Header

- This header contains a timestamp field.  
- The timestamp field does not represent an absolute synchronized time (e.g., SNTP, PTP or NTP).  
- Instead, it indicates the elapsed time since the firmware boot.  
- This relative time is mainly used for ordering packets and correlating sensor data within the same firmware runtime.  

#### Field Layout

| Byte Offset | Field Name | Type | Size (Bytes) | Description |
|--------------|-------------|------|---------------|--------------|
| 0 | Sequence Number | unsigned char | 1 | Packet sequence number.</br> Each packet type maintains its own independent sequence number, which is incremented with every packet transmission. (Range: 0-255) |
| 1 | Checksum | unsigned char | 1 | This field is reserved for future use.</br> In the current version, the checksum is not used, and the value is always fixed to 0. |
| 2 | Reserved1 | unsigned char | 1 | Reserved field. |
| 3 | Reserved2 | unsigned char | 1 | Reserved field. |
| 4–7 | Seconds | signed int | 4 | Seconds value of the timestamp. Represents the number of seconds elapsed since firmware boot. Byte order: MSB |
| 8–11 | Nano Seconds | signed int | 4 |Nanoseconds remainder of the timestamp, for sub-second precision.</br> Byte order: MSB |

---

### Non-Timestamp Header
- Does not contain a timestamp field.  
- Used for packets where timing information is not critical, or for command packets from the ROS driver.

#### Field Layout

| Byte Offset | Field Name | Type | Size (Bytes) | Description |
|--------------|-------------|------|---------------|--------------|
| 0 | Sequence Number | unsigned char | 1 | Packet sequence number.</br> Each packet type maintains its own independent sequence number, which is incremented with every packet transmission. (Range: 0-255) |
| 1 | Checksum | unsigned char | 1 | This field is reserved for future use.</br> In the current version, the checksum is not used, and the value is always fixed to 0. |
| 2 | Reserved1 | unsigned char | 1 | Reserved field. |
| 3 | Reserved2 | unsigned char | 1 | Reserved field. |

---
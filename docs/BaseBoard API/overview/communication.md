# BaseBoard API Overview

*This document describes the packets exchanged between the firmware and the robot software’s ROS driver.*

## Communication Method
Communication between the firmware and the ROS driver is established over **UDP**.  
The firmware is configured with a static IP address (**10.2.98.200**).  
Each packet type is assigned a different UDP port, and all packets defined in this document are exchanged through these ports.  

# BaseBoard Boot-up & Network Watchdog

##  Boot-up Sequence & Timings
Defines the hardware initialization of BaseBoard and the FreeRTOS thread startup sequence, specifying the golden time when the PC can start UDP communication.

###  Initialization Flow
1.  **Entry Point**: `main()` → FreeRTOS scheduler starts → `app_main()` thread creation
2.  **System Init thread**: Actual I/O and network stack(lwIP) initialization proceeds sequentially in a separate `system_init` thread
3.  **Boot Done**: When all initialization succeeds, it switches to `bootDone = true` and periodic data publishing begins

###  Key Wait Times and Availability Points
* Initialization wait times vary depending on the board revision.
* **PC communication start condition**: Even if the UDP socket(`T_SOCKET`) is open, the firmware can only confirm the counterpart's IP address and send a response after receiving at least one packet from the PC.

| Stage | Main Tasks | Accumulated Wait Time(min) | Remarks |
| :--- | :--- | :--- | :--- |
| **T0** | Power On and Kernel Start | 0s | Run LED fast blinking |
| **T1** | HW Initialization and Stabilization | Approximately 6~10s | I2C, SPI, IMU, Audio Initialization  |
| **T2** | Ethernet PHY Reset/Stabilization | Approximately 12~16s | Includes fixed 6s wait  |
| **T_SOCKET** | **Open UDP Receive Socket** | **Approximately 15~20s** | **PING reception possible from this point**  |
| **T_BOOT** | **Initialization Complete(Boot Done)** | **Approximately 20~30s** | **Start periodic Topic publishing**  |

###  Available Functions by FW Status Section
* Command processing is possible between `T_SOCKET` and `T_BOOT`, but periodic Publish is not yet available.
* **Recommended PC-side behavior**: Immediately after power-on, PING may be dropped for up to 20 seconds. Implement a retry logic and keep trying until the first ECHO response is received.

| Section | UDP Reception | Command Processing(PING/SHUTDOWN/ESTOP etc.) | Periodic Publish(IVT/GenericStatus etc.) |
| :--- | :---: | :---: | :---: |
| **T0 ~ T_SOCKET** | X (packet drop) | X | X  |
| **T_SOCKET ~ T_BOOT** | ✓ | ✓ | X  |
| **After T_BOOT** | ✓ | ✓ | ✓  |

---

##  UDP Port & Packet

###  Port Map
All ports are based on the offset from `PORT_BASE = 49152`. **IN/OUT** is based on the BaseBoard.

| Name | Value | Direction | Usage |
| :--- | :--- | :--- | :--- |
| **MAIN_COMS_IN_PORT** | 49158(`PORT_BASE + 6`) | PC → FW | Command Reception (`COMS_CMD_*`) |
| **MAIN_COMS_OUT_PORT** | 49157(`PORT_BASE + 5`) | FW → PC | Status Packet / PING ECHO  |

###  PING/ECHO Packet Structure 

| Direction | Type | Size | Payload |
| :--- | :--- | :--- | :--- |
| **PC → FW** | `MAIN_COMS_PACKET` | 12 B | NetPacketHeader(4) + `COMS_CMD` cmd(4) + `COMS_ARG` arg(4)  |
| **FW → PC** | `PING_ECHO_PACKET` | 12 B | `MAIN_COMS_PACKET_HEADER`(8) + `uint32_t` seq_num(4)  |

* **PC → FW**
    - `cmd` = `COMS_CMD_PING`
    - `arg` = sequence number.

* **FW → PC**
    - `type` = `MC_PACKET_TYPE_PING_ECHO`
    - `seq_num` reflects the `arg` exactly as received.

### Peer Discovery
The FW has no fixed target IP and undergoes the following dynamic learning process:

1.  **First reception**: Immediately upon receiving the first packet sent by the PC(e.g., PING), it learns the counterpart's IP.
2.  **Target confirmation**: Subsequently, the destination address of all Out-Stream(IMU, BMS, etc.) is uniformly updated to that IP.
3.  **WOL(Wake On Lan) preparation**: Stores the counterpart's MAC address through ARP(Address Resolution Protocol) query.

---

## Heartbeat(Ping) & Network Watchdog
A mechanism that mutually monitors connection status(heartbeat) and performs self-recovery (watchdog) in case of failure.

###  Heartbeat Mechanism 
* **PC → FW**: Periodically send `COMS_CMD_PING` packets(recommended interval: 1Hz, maximum less than 2.5s).
* **FW → PC**: Immediately respond with `MC_PACKET_TYPE_PING_ECHO`. At the same time, call internal `NetworkWatchdog::Feed()` to reset the watchdog timer.

###  Network Watchdog Configuration

| Constant | Value | Meaning |
| :--- | :--- | :--- |
| `kProbeIntervalMs` | 2500 ms | Time of PING no response detection = ICMP probe start reference  |
| `kRetryIntervalMs` | 1000 ms | Retry interval on ICMP failure  |
| `kMaxProbeFails` | 2 | Allowed number of consecutive ICMP failures(initial probe + 2 retries = total 3 times)  |
| `kMaxRecoveries` | 5 | Maximum number of PHY resets |
| `kPhyResetLeadTimeMs` | 6000 ms | Stabilization wait after PHY reset  |
| `PING_RCV_TIMEO` | 500 ms | lwIP ping receive timeout  |

### Recovery Scenario 

| Situation | Action and Judgment | Measure |
| :--- | :--- | :--- |
| **Normal PING** | Received within 2.5 seconds | Watchdog Feed → Timer Reset  |
| **No PING Response** | No response exceeding 2.5 seconds | FW directly sends ICMP Echo(Ping) to PC  |
| **ICMP Success** | PC response confirmed | Judged as connection maintained(Log: "Probe success") → Timer restart  |
| **ICMP Failure** | Retry every 1 second(initial + 2 retries = total 3 attempts) | If all fail, enter hardware recovery stage |
| **Network Recovery** | After 3 consecutive failures, Ethernet PHY hardware reset then wait 6 seconds → retry | Up to 5 attempts for reset  |
| **Recovery Abandonment** | PHY reset failed 5 times | Probe permanently stopped(`PauseUntilFeed`). Automatically restarts with `Feed()` when PC sends PING again  |

---

## Graceful Shutdown(Shutdown Logic) 
When the user presses the power button to attempt shutdown, the FW does not just cut the power but checks the PC's shutdown status.

1.  If `main_coms.IsConnected()` is true(meaning there has been communication with the PC at least once before), replace the Watchdog handler with `GracefulShutdownHandler`.
2.  Send ICMP probes at 1-second intervals.
3.  If there is no response for 10 consecutive times(10 seconds), consider the PC fully shut down and cut the baseboard power.
4.  If the PC responds before that or sends `COMS_CMD_SHUTDOWN`, immediately proceed with the shutdown routine.
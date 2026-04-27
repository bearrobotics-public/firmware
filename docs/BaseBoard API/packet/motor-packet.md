# Motor Packet (Bi-Directional)

Motor-related communication uses two distinct packet formats depending on the communication direction.

---

## Common Data Types

-  MotorArg
```c
typedef union {
  float f32_value;
  uint32_t u32_value;
} MotorArg;
```
The `MotorArg`is a union type that allows a motor argument to be represented either as a 32-bit floating-point value(f32_value) or as a 32-bit unsigned integer(u32_value).

    - f32_value: Used when the motor parameter requires a floating-point argument.
    - u32_value: Used when the motor parameter requires an unsigned integer argument.
    - Which member of the union is used depends on the associated MOTOR_PARAM described in the next section.

- MOTOR_PARAM  
The `MOTOR_PARAM` field is represented as a 32-bit integer value in the range 0x00000000 to 0x7FFFFFFF.

| Value      | Name                          | Argument Type | Description                 |
| ---------- | ----------------------------- | ------------- | --------------------------- |
| 0x00000000 | MOTOR_PARAM_NONE              | N/A           | Do not use this param for packet.  |
| 0x00000001 | MOTOR_PARAM_TARGET_SPEED      | f32_value     | Target speed in [rad/s].  |
| 0x00000002 | MOTOR_PARAM_TUNING_P_GAIN     | f32_value     | Value for the **Proportional** gain. </br> Use this parameter if additional tuning of the motor is required.           |
| 0x00000003 | MOTOR_PARAM_TUNING_I_GAIN     | f32_value     | Value for the **Integral** gain. </br> Use this parameter if additional tuning of the motor is required.  |
| 0x00000004 | MOTOR_PARAM_TUNING_D_GAIN     | f32_value     | Value for the **Derivative** gain.</br> Use this parameter if additional tuning of the motor is required.  |
| 0x00000005 | MOTOR_PARAM_TUNING_FF_GAIN    | f32_value     | Value for the **Feed-Forward** gain.</br> Use this parameter if additional tuning of the motor is required.  |
| 0x00000006 | MOTOR_PARAM_TUNING_DN_GAIN    | f32_value     | 	Value for the **Derivative Noise** filter.</br> *Use this parameter if additional tuning of the motor is required.*  |
| 0x00000007 | MOTOR_PARAM_CURRENT_SPEED     | f32_value     | Current speed in [rad/s]    |
| 0x00000008 | MOTOR_PARAM_VERSION           | u32_value     | This parameter is used to query the firmware version of the motor driver.  |
| 0x00000009 | MOTOR_PARAM_STATUS            | u32_value     | This parameter is used to query the current status of the motors.        |
| 0x0000000A | MOTOR_PARAM_FAULT_RESET       | u32_value     | This parameter is used to reset fault state of the motors.    |
| 0x0000000B | MOTOR_PARAM_ENABLE_MOTOR      | u32_value     | This parameter is used to enable or disable the motors. </br> Motors are locked when this parameter is enabled, and unlocked when it is disabled. |
| 0x0000000C | MOTOR_PARAM_ALERT             | u32_value     | Currently not in use. |
| 0x0000000D | MOTOR_PARAM_TUNING_OUT_GAIN   | f32_value     | Value for the **Output** gain. </br> *Use this parameter if additional tuning of the motor is required.* |
| 0x0000000E | MOTOR_PARAM_HARDWARE_REVISION | u32_value     | This parameter is used to query the hw revision of the motor driver.   |


## Detailed Packet Specifications

### Sent From The ROS driver
This packet must be sent from the ROS driver to the firmware through `UDP` port number 
**49152**.

#### Transmission Rate
- **Target Rate**: 100Hz(10ms interval).

#### Field Layout
| Byte Offset | Field Name | Type | Size (Bytes) | Description |
|--------------|-------------|------|---------------|--------------|
| 0 - 3   | Header    | Non-Timestamp Header | 4 | Please refer to [Non-Timestamp Header](packet-structure.md#non-timestamp-header) |
| 4 - 7   | Parameter | MOTOR_PARAM          | 4 | Please refer to [MOTOR_PARAM](#common-data-types) |
| 8 - 11  | Argument1 | MotorArg             | 4 | The type of the argument varies depending on the associated `MOTOR_PARAM`. </br> Please refer to [Usage](#usage) for more detail |
| 12 - 15 | Argument2 | MotorArg             | 4 | The type of the argument varies depending on the associated `MOTOR_PARAM`. Please refer to [Usage](#usage) for more detail |

#### Usage
*Note: Packets transmitted from the ROS driver do not use the `MOTOR_PARAM_CURRENT_SPEED`.  This parameter is reserved for packets sent by the firmware to report the current speed.*

- MOTOR_PARAM_TUNING_XXX_GAINs:   
   MOTOR_PARAM_TUNING_P_GAIN  
   MOTOR_PARAM_TUNING_I_GAIN  
   MOTOR_PARAM_TUNING_D_GAIN  
   MOTOR_PARAM_TUNING_FF_GAIN  
   MOTOR_PARAM_TUNING_DN_GAIN  
   MOTOR_PARAM_TUNING_OUT_GAIN
    - Purpose  
      These parameters are used to tune the motor speed control loop.
    - Argument Usage  
      Argument1 (MotorArg.f32_value): Gain(or Filter) value for the specified parameter.
      Argument2 (MotorArg.f32_value): Not used, set to 0.
    - Firmware Response  
      The firmware responds with the same parameter and value provided by ROS driver, reflecting the value applied to the system.  
      Please refer to [Sent From The Firmware](#sent-from-the-firmware) section for details. 

- MOTOR_PARAM_TARGET_SPEED
    - Purpose  
     Sets the target motor speed in [rad/s].
    - Argument Usage  
     Argument1 (MotorArg.f32_value): Target speed for the left motor  
     Argument2 (MotorArg.f32_value): Target speed for the right motor
    - Firmware Response  
     The firmware responds with the current speed value using`MOTOR_PARAM_CURRENT_SPEED`.  
     Please refer to [Sent From The Firmware](#sent-from-the-firmware) section for details.
- MOTOR_PARAM_VERSION
    - Purpose  
     Query the firmware version of the motor driver.  
    - Argument Usage  
     Argument1 (MotorArg.u32_value): Not used, set to 0.  
     Argument2 (MotorArg.u32_value): Not used, set to 0.
    - Firmware Response  
     The firmware responds with the firmware version of the motor driver using the same parameter.  
     Please refer to [Sent From The Firmware](#sent-from-the-firmware) section for details.
- MOTOR_PARAM_STATUS
    - Purpose  
     Get the current status of the motor.  
    - Argument Usage  
     Argument1 (MotorArg.u32_value): Not used, set to 0.  
     Argument2 (MotorArg.u32_value): Not used, set to 0.
    - Firmware Response  
     The firmware responds with the current motor status using the same parameter.
- MOTOR_PARAM_FAULT_RESET
    - Purpose  
     Clear the fault state of the motors.  
    - Argument Usage  
     Argument1 (MotorArg.u32_value): Not used, set to 0.  
     Argument2 (MotorArg.u32_value): Not used, set to 0.
    - Firmware Response  
     The firmware does not generate a direct response packet for this parameter.  
     Instead, the error code field within the motor status (`MOTOR_PARAM_STATUS`) is cleared.
- MOTOR_PARAM_ENABLE_MOTOR
    - Purpose  
     This parameter enables or disables motor control in the motor driver.  
     When enabled, the motor driver accepts and executes the `MOTOR_PARAM_TARGET_SPEED` 
     When disabled, the motor driver ignores `MOTOR_PARAM_TARGET_SPEED`.  
     In this state, the user can physically push the robot and move it.
    - Argument Usage  
     Both `Argument1(MotorArg.u32_value)` and `Argument2(MotorArg.u32_value)` must be transmitted as either 1 (enable) or 0 (disable).
    - Firmware Response  
     The firmware does not generate a response packet for this parameter.
- MOTOR_PARAM_HARDWARE_REVISION
    - Purpose  
     Query the hardware revision of the motor driver
    - Argument Usage  
     Argument1 (MotorArg.u32_value): Not used, set to 0.  
     Argument2 (MotorArg.u32_value): Not used, set to 0.
    - Firmware Response  
     The firmware responds with the hardware revision of the motor driver using the same parameter.  
     Please refer to [Sent From The Firmware](#sent-from-the-firmware) section for details.

### Sent From The Firmware
This packet must be sent from the firmware through UDP port number **49153**.

#### Transmission Rate
- **Normal Operation:** 100 Hz (10ms interval). The firmware transmits this packet **typically** in response to a packet received from the ROS driver.
- **Idle/Fallback Mode:** 40 Hz (25ms interval). If no command packet is received from the ROS driver within 25 ms, the firmware **automatically polls** and transmits a report packet to synchronize the speed and status of the motors.

#### Field Layout
| Byte Offset | Field Name | Type | Size (Bytes) | Description |
|--------------|-------------|------|---------------|--------------|
| 0 - 11   | Header    | Timestamp Header | 12 | Please refer to [Timestamp Header](packet-structure.md#timestamp-header) |
| 4 - 7   | Parameter | MOTOR_PARAM          | 4 | Please refer to [MOTOR_PARAM](#common-data-types) |
| 8 - 11  | Argument1 | MotorArg             | 4 | The type of the argument varies depending on the associated `MOTOR_PARAM`. </br> Please refer to [Usage](#usage_1) for more detail |
| 12 - 15 | Argument2 | MotorArg             | 4 | The type of the argument varies depending on the associated `MOTOR_PARAM`. </br> Please refer to [Usage](#usage_1) for more detail |
| 16 - 19 | Argument3 | MotorArg             | 4 | The type of the argument varies depending on the associated `MOTOR_PARAM`. </br> Please refer to [Usage](#usage_1) for more detail |
| 20 - 23 | Argument4 | MotorArg             | 4 | The type of the argument varies depending on the associated `MOTOR_PARAM`. </br> Please refer to [Usage](#usage_1) for more detail |

#### Usage
*Note: Packets transmitted from the ROS driver do not use the `MOTOR_PARAM_CURRENT_SPEED`.   This parameter is reserved for packets sent by the ROS driver to set the target speed.*

- MOTOR_PARAM_TUNING_XXX_GAINs:  
   MOTOR_PARAM_TUNING_P_GAIN  
   MOTOR_PARAM_TUNING_I_GAIN  
   MOTOR_PARAM_TUNING_D_GAIN  
   MOTOR_PARAM_TUNING_FF_GAIN  
   MOTOR_PARAM_TUNING_DN_GAIN  
   MOTOR_PARAM_TUNING_OUT_GAIN
    - Purpose  
      These parameters are used to respond with the tuning values set by the ROS driver packets. 
    - Argument Usage  
      Argument1 (MotorArg.f32_value): Configured gain(or filter) value for the right motor.
      Argument2 (MotorArg.f32_value): Configured gain(or filter) value for the left motor.
      Argument3 (MotorArg.u32_value): Not used, set to 0.  
      Argument4 (MotorArg.u32_value): Not used, set to 0.
    - Tuning Parameter Response Behavior  
      Packets utilizing these parameters, when transmitted from the firmware, serve as response packets to the corresponding parameters sent by the ROS driver.  
      In such cases, the ROS driver transmits the configuration value in `Argument1`, while `Argument2` is set to `0`. This value is applied symmetrically, configuring the same gain or filter setting for both the right and left motors.
- MOTOR_PARAM_CURRENT_SPEED
    - Purpose  
      This parameter is used by the firmware to respond with the current motor speed in [rad/s].
    - Argument Usage  
      Argument1 (MotorArg.f32_value): Current right motor speed in [rad/s].  
      Argument2 (MotorArg.f32_value): Current left motor speed in [rad/s].  
      Argument3 (MotorArg.u32_value): Current right motor status.  
      Argument4 (MotorArg.u32_value): Current left motor status.  
    - Motor Speed Response Behavior  
      Generally, the firmware transmits this packet in response to the `MOTOR_PARAM_TARGET_SPEED` packet sent from the ROS driver.
      However, if no target speed packet is received within 25 ms, the firmware transmits this packet as a report to synchronize the speed and status of the motors.  
      Please refer to Motor Status Field Layout for more detailed information on the motor status.
- MOTOR_PARAM_VERSION
    - Purpose  
        Respond the firmware version information to the ROS driver.
    - Argument Usage  
      Argument1 (MotorArg.u32_value): Contains both `Major` and `Minor` version numbers.  
      Argument2 (MotorArg.u32_value): Contains both `Revision` and `Build` numbers.
    - Motor Driver Firmware Response Behavior  
      This packet is generated by the firmware as a response to the `MOTOR_PARAM_VERSION` request received from the ROS driver.  
      The motor firmware version is represented in the format {**Major.Minor.Revision.Build**}  
      For example, if Argument1 = 0x0002 0001 / Argument2 = 0x0005 0x0032  
      then the firmware version is 1.2.5.50
- MOTOR_PARAM_STATUS
    - Purpose  
      Reports the current status of both right and left motors, including motor error codes and the motor driver’s gate driver status.
    - Argument Usage  
      Argument1 (MotorArg.u32_value): Status field for the right motor.  
      Argument2 (MotorArg.u32_value): Status field for the left motor.
    - Status Field Layout  
      Bits 31-22: Motor error  
      Bits 21-0: Status for the gate driver  

    | **Bit** | **Description** |
    |----------|-----------------|
    | 31 | Emergency stop activated |
    | 30 | Communication timeout |
    | 29 | Encoder phase angle error |
    | 28 | Hall sensor phase angle error |
    | 27 | Current (iq) PID controller wind-up error |
    | 26 | Current (id) PID controller wind-up error |
    | 25 | Speed PID controller wind-up error |
    | 24 | Gate driver error |
    | 23 | Invalid hall sensor reading |
    | 22 | Stall condition detected |
    | 21 | General fault |
    | 20 | Over-current protection |
    | 19 | Gate driver fault |
    | 18 | Under voltage lockout |
    | 17 | Over-temperature shutdown |
    | 16 | High-side phase A drain-source voltage fault |
    | 15 | Low-side phase A drain-source voltage fault |
    | 14 | High-side phase B drain-source voltage fault |
    | 13 | Low-side phase B drain-source voltage fault |
    | 12 | High-side phase C drain-source voltage fault |
    | 11 | Low-side phase C drain-source voltage fault |
    | 10 | Phase A over-current |
    | 9  | Phase B over-current |
    | 8  | Phase C over-current |
    | 7  | Over-temperature warning |
    | 6  | CPU under voltage |
    | 5  | High-side phase A gate-source fault |
    | 4  | Low-side phase A gate-source fault |
    | 3  | High-side phase B gate-source fault |
    | 2  | Low-side phase B gate-source fault |
    | 1  | High-side phase C gate-source fault |
    | 0  | Low-side phase C gate-source fault |

- MOTOR_PARAM_HARDWARE_REVISION
    - Purpose  
      Respond the hardware revision information of the motor driver to the ROS driver
    - Argument Usage  
      Argument1 (MotorArg.u32_value): Hardware revision of the motor driver.  
      Argument2 (MotorArg.u32_value): Not used, set to 0.
    - Motor Driver Hardware Revision Response Behavior  
      This packet is generated by the firmware as a response to the `MOTOR_PARAM_HARDWARE_REVISION` request received from the ROS driver.  
      The hardware revision information is encoded in the lower 4 bits of `Argument1`.
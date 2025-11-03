# BaseLedCommand Packet (Single-Direction, ROS driver → Firmware)

This command is used to set the state of the Base LED (located on the bottom of the robot).  
It must be sent from the ROS driver, and the firmware does not generate a response for this command.

---
## Parameters

This section provides the parameter definitions for the BaseLedCommand.

### COMMAND_TYPE 
The `COMMAND_TYPE`is 32-bit signed integer value.

| Value (Hex) | Name    | Description |
|-------------|---------|-------------|
| 0x00000000  | INVALID | Reserved. Do not use this value.|
| 0x00000001  | SOLID   | Displays a solid single-color illumination. |
| 0x00000002  | BLINK   | Displays a smooth dimming single-color animation |
| 0x00000003  | ROTATE  | Displays a rotating single-color animation |
| 0x00000004  | RAINBOW | Displays a rainbow multi-color streaming animation |

### SPEED_LEVEL  
The `SPEED_LEVEL`is 32-bit signed integer value.

| Value (Hex) | Name | Description |
|-------------|------|-------------|
| 0x00000000  | NONE | Shall be used only when `COMMAND_TYPE` is set to `SOLID`. |
| 0x00000001  | SLOW | Specifies that the animation is displayed at a slow speed (≈ 30 fps). |
| 0x00000002  | MEDIUM | Specifies that the animation is displayed at a medium speed (≈ 60 fps). |
| 0x00000003  | FAST | Specifies that the animation is displayed at a fast speed (≈ 90 fps). |

---

## Field Layout

| Byte Offset | Field Name | Type | Size (Bytes) | Description |
|--------------|-------------|------|---------------|--------------|
| 0 - 3   | Header    | Non-Timestamp Header | 4 | Please refer to [Non-Timestamp Header](packet-structure.md#non-timestamp-header) |
| 4 - 7   | Color     | 32-bit unsigned integer | 4 | **Color code (WRGB).** </br>- Bits 31–24: White </br> - Bits 23–16: Red </br>- Bits 15–8: Green </br> - Bits 7–0: Blue</br>  This field shall be ignored when `COMMAND_TYPE` is set to `RAINBOW`. |
| 8 - 11  | Reserved1 | 32-bit unsigned integer | 4 | Reserved. Set to 0. |
| 12 - 15 | Speed     | SPEED_LEVEL | 4 | Refer to [SPEED_LEVEL](#speed_level) |
| 16      | Reserved2 | unsigned char | 1 | Reserved. Set to 0. |
| 17 - 20 | Command   | COMMAND_TYPE | 4 | Refer to [COMMAND_TYPE](#command_type) |

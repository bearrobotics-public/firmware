# Log Packet (Single-Direction, Firmware → ROS driver)

The Log message is used by the firmware to transmit runtime log information to the ROS driver for debugging and monitoring.  
It is encoded using Protocol Buffers (nanopb) and transmitted asynchronously via UDP port **49164**.
Each message may contain one or more log entries wrapped in `Message` containing one or more `LogChain` objects.

---

## Message Definition 
This is the `log.proto`  

```protobuf
syntax = "proto3";

message SourceLocation {
  string file_name = 1;
  string function_name = 2;
  uint32 line = 3;
}

message Timestamp {
  int64 seconds = 1;
  int32 nanos = 2;
}

message SoftwareVersion {
  uint32 major = 1;
  uint32 minor = 2;
  uint32 revision = 3;
}

message Version {
  uint32 board_version = 1;
  SoftwareVersion sw_version = 2;
}

message Uint32Array{
  repeated uint32 vals = 1 [packed=true];
}

message LogParam {
  string label = 1;
  oneof value {
    int32 int32_val = 2;
    string string_val = 3;
    Version version_val = 4;
    float float_val = 5;
    bool boolean_val = 6;
    Timestamp ts_val = 7;
    uint32 uint32_val = 8;
    Uint32Array uint32_array = 9;
  }
}

message Log {
  uint32 code = 1;
  enum LogType {
    UNDEFINED = 0;
    INFO = 1;
    WARNING = 3;
    ERROR = 4;
    CRITICAL = 5;
    PERF = 6;
    RAW_DATA = 7;
  }
  LogType type = 2;
  SourceLocation location = 3;
  Timestamp timestamp = 4;
  string description = 5;
  repeated LogParam parameters = 6;
}

message LogChain {
  repeated Log logs = 1;
}

message Message {
  repeated LogChain logs = 1;
}
```

---

## Usage
The ROS driver compiles the `log.proto` definition to generate decoding files and uses them to parse the payload transmitted from the firmware. he decoded log entries are stored in log files within the robot system or directly output by the ROS driver, allowing engineers to monitor and review firmware-related logs generated during robot operation.  
The `LogChain` represents a causal chain of log entries. In the case of errors, each element indicates a log that was caused by the subsequent element in the chain. For normal informational or measurement logs, the chain typically contains only a single element.

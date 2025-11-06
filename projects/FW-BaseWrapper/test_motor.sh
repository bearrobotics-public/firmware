#!/bin/bash
source /catkin_ws/devel/setup.bash || exit 1

rosservice call /example_node/set_enable_motor "data: true"
rostopic pub -1 /example_node/motor_speed example_node/MotorCommand '{RPM_L: 10.0, RPM_R: -10.0}'
sleep 3
rostopic pub -1 /example_node/motor_speed example_node/MotorCommand '{RPM_L: 0.0, RPM_R: 0.0}'
rosservice call /example_node/set_enable_motor "data: false"

sleep 1

rosservice call /example_node/set_enable_motor "data: true"
rostopic pub -1 /example_node/motor_speed example_node/MotorCommand '{RPM_L: -10.0, RPM_R: 10.0}'
sleep 3
rostopic pub -1 /example_node/motor_speed example_node/MotorCommand '{RPM_L: 0.0, RPM_R: 0.0}'
rosservice call /example_node/set_enable_motor "data: false"

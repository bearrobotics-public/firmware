#!/bin/bash

# Wrapper script to run the motor test Python script inside the Docker container
# This allows you to execute the test from outside the container
#
# Usage:
#   ./run_test_motor.sh [max_speed] [ramp_time] [hold_time]
#   
# Arguments:
#   max_speed  - Maximum speed in RPM (default: 2.0, max: 10.0)
#   ramp_time  - Time in seconds to accelerate/decelerate (default: 5.0)
#   hold_time  - Time in seconds to hold at max speed (default: 3.0)
#
# Examples:
#   ./run_test_motor.sh                    # Use defaults: 3.0 RPM, 5s ramp, 3s hold
#   ./run_test_motor.sh 8.0 3.0 2.0        # 8.0 RPM, 3s ramp, 2s hold
#   ./run_test_motor.sh 10.0 10.0 5.0      # 10.0 RPM, 10s ramp, 5s hold

# Container name - adjust this to match your actual container name
CONTAINER_NAME="example_node_container"

# Path to the script inside the container
SCRIPT_PATH="/catkin_ws/src/example_node/test_motor.py"

# Parse command line arguments
MAX_SPEED=${1:-2.0}
RAMP_TIME=${2:-5.0}
HOLD_TIME=${3:-3.0}

# Check if the container is running
if ! docker ps --format '{{.Names}}' | grep -q "^${CONTAINER_NAME}$"; then
    echo "Error: Container '${CONTAINER_NAME}' is not running."
    echo "Available running containers:"
    docker ps --format "  - {{.Names}}"
    exit 1
fi

echo "Running motor test in container: ${CONTAINER_NAME}"
echo "Parameters:"
echo "  - Max Speed: ${MAX_SPEED} RPM"
echo "  - Ramp Time: ${RAMP_TIME} seconds"
echo "  - Hold Time: ${HOLD_TIME} seconds"
echo "=========================================="

# Execute the Python script inside the container with arguments
docker exec -it ${CONTAINER_NAME} bash -c "
    source /catkin_ws/devel/setup.bash && \
    python3 ${SCRIPT_PATH} --max-speed ${MAX_SPEED} --ramp-time ${RAMP_TIME} --hold-time ${HOLD_TIME}
"

exit_code=$?

if [ $exit_code -eq 0 ]; then
    echo "=========================================="
    echo "Motor test completed successfully!"
else
    echo "=========================================="
    echo "Motor test failed with exit code: $exit_code"
fi

exit $exit_code


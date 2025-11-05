# example_node

A minimal ROS containerized node with host networking.

## Prerequisites
- **Linux host interface at static IP 10.2.98.200**
  - Ensure the host has a network interface configured with `10.2.98.200/24` (or your required netmask) and it is up.
- **Docker installed on the host**
  - Install Docker following the official guide: [Install Docker Engine](https://docs.docker.com/engine/install/).
  - If your user is not in the `docker` group, prefix commands with `sudo`.

## Get the code
```bash
git clone <REPO_URL>
cd example_node
```

## Build and run
Build the image and start the container (host networking is used):
```bash
./start.sh
```
- Image tag: `example_node:latest`
- Container name: `example_node_container`
- The container runs with `--network host` and `--rm`. Stop it with Ctrl+C.

## Optional: Run motor test
With the container running in another terminal, execute the test sequence:
```bash
./test.sh
```
This will `docker exec` into the running container and call `/catkin_ws/src/example_node/test_motor.sh`, which:
- Enables motors
- Publishes sample `example_node/MotorCommand` messages to `/example_node/motor_speed`
- Stops and disables motors

## Notes
- Host networking requires the host interface at `10.2.98.200` to be reachable for your hardware/network.
- If you rebuild often, Docker layer cache will speed subsequent `./start.sh` runs.
- For troubleshooting, you can get a shell in the running container:
```bash
docker exec -it example_node_container bash
```

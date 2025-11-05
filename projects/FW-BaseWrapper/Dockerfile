FROM ros:noetic-ros-base

# Use bash for RUN to allow `source`
SHELL ["/bin/bash", "-c"]

ENV DEBIAN_FRONTEND=noninteractive \
    ROS_WS=/catkin_ws

# Base tooling for building and dependency resolution
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    git \
    python3-rosdep \
    python3-rosinstall \
    python3-rosinstall-generator \
    python3-wstool \
  && rm -rf /var/lib/apt/lists/*

# Initialize rosdep (safe if re-run)
RUN rosdep init || true && rosdep update

# Create workspace and copy package
RUN mkdir -p ${ROS_WS}/src
WORKDIR ${ROS_WS}
COPY . ${ROS_WS}/src/example_node

# Install package dependencies (from package.xml) and build
RUN source /opt/ros/noetic/setup.sh \
  && rosdep install --from-paths src --ignore-src -r -y \
  && catkin_make

# Make environment available for interactive shells
RUN echo "source /opt/ros/noetic/setup.bash" >> /root/.bashrc \
  && echo "source ${ROS_WS}/devel/setup.bash" >> /root/.bashrc

# Default: launch the node
CMD ["bash", "-lc", "source /opt/ros/noetic/setup.bash && source /catkin_ws/devel/setup.bash && roslaunch example_node main.launch"]



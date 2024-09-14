FROM ros:humble

ENV DEBIAN_FRONTEND=noninteractive

# update the dependencies
RUN apt update
RUN apt upgrade -y

# create a repository for a workspace
RUN mkdir -p /ros2_ws/src
WORKDIR /ros2_ws/src/my_package

# copy the package to the container workspace
COPY . .
WORKDIR /ros2_ws

# build the package
RUN /bin/bash -c "source /opt/ros/humble/setup.bash && colcon build --symlink-install --parallel-workers 4"


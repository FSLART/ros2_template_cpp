# ROS2 Template C++

Template repository for a ROS2 package with a publisher and a subscriber node.

## Features
- Template Docker file for portability;
- DevContainer configuration for streamlined development in containers.

## First Steps / Adapting

This repository contains two nodes:
- **talker**: Publishes the "Hello World" string message every second;
- **listener**: Subscribes the string message published by the publisher and logs the value.

These are the main steps for you to start developing:
1. In ```package.xml```, change the name, description and maintainer.
```xml
<name>my_package</name>
<description>TODO: Package description</description>
<maintainer email="root@todo.todo">root</maintainer>
```
2. If you want to create a new node, you can one of the existing as base. These are the steps:
    1. Create a header file in ```include``` declaring the node constructor, member variables and methods. In this header file, be aware to use Doxygen-compatible comments for automatic documentation generation and autocomplete hints.
    2. Create a source file in ```src``` with the implementation of the constructor and member methods. This file also contains the ```main``` function, which starts the node.
    3. Add the node compilation declaration to ```CMakeLists.txt```
    ```cmake
    add_executable(my_node src/node.cpp)
    ament_target_dependencies(my_node rclcpp std_msgs)
    ```

## Developing

If you want to develop barebones (with ROS and everything installed on your computer) you just need to create a ROS workspace and put this package in it in the ```src``` directory.

If you want to develop using Docker, which does not require installing ROS and may be faster to run, you have two ways:
1. Build the Dockerfile using ```docker build -t my_package .``` and be on your own.
2. Use the DevContainer.

The main advantage of using the DevContainer is that VSCode provides a streamlined experience which seems like you are just developing locally with everything installed on your own computer.

To start the DevContainer do the following:
1. Open the repository in VSCode;
    - Make sure you have the \"Dev Containers\" extension installed (the official from Microsoft).
2. Press the ```F1``` key;
3. Select the option \"Dev Containers: Build and Open in Container\";
4. After waiting for a while, you should be inside the DevContainer in a VSCode environment which resembles a native one.

If you are willing to use the Dev Container, eventually you will need to configure it (adding/removing directory binds, adding/removing VSCode extensions, etc.). You will do that in the ```.devcontainer/devcontainer.json``` file.

/*
MIT License

Copyright (c) 2024 Associação Académica de Desportos Motorizados de Leiria (AADML)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "my_package/listener.h"

Listener::Listener() : Node("listener") {

    // create the subscriber for string messages on the topic "topic"
    this->subscriber_ = this->create_subscription<std_msgs::msg::String>("topic", 10, std::bind(&Listener::topic_callback, this, std::placeholders::_1));
}

void Listener::topic_callback(const std_msgs::msg::String::SharedPtr message) const {

    // log the message
    RCLCPP_INFO(this->get_logger(), "I heard: '%s'", message->data.c_str());
}

int main(int argc, char *argv[]) {

    // initialize ROS2
    rclcpp::init(argc, argv);

    // create a node instance and spin
    rclcpp::spin(std::make_shared<Listener>());

    // shutdown ROS after the node is destroyed
    rclcpp::shutdown();

    return 0;
}

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
#ifndef MY_PACKAGE_LISTENER_H_
#define MY_PACKAGE_LISTENER_H_

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

/*! \brief Simple subscriber class. Subscribes a string message. */
class Listener : public rclcpp::Node {

    public:
        /*! \brief Constructor of the Subscriber class. */
        Listener();

    private:
        /*! \brief Subscriber for the string message. */
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;

        /*! \brief Callback function for the subscriber. Called every time a message arrives and logs the message. */
        void topic_callback(const std_msgs::msg::String::SharedPtr message) const;

};

#endif // MY_PACKAGE_LISTENER_H_

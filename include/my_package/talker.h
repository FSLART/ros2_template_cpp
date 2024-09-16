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
#ifndef MY_PACKAGE_TALKER_H_
#define MY_PACKAGE_TALKER_H_

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

/*! \brief Simple publisher class. Publishes a string message at a fixed time interval. */
class Talker : public rclcpp::Node {

    public:
        /*! \brief Constructor of the Talker class. */
        Talker();

    private:
        /*! \brief Timer for booting the message callback. */
        rclcpp::TimerBase::SharedPtr timer_;

        /*! \brief Publisher for the string message. */
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;

        /*! \brief Callback function for the timer. Uses the publisher to publish a string. */
        void timer_callback();

};


#endif // MY_PACKAGE_TALKER_H_

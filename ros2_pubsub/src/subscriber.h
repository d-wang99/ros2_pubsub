//
// Created by Dafan Wang on 2023/4/4.
//

#pragma once

#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "message_interfaces/msg/node_msg.hpp"

class Subscriber : public rclcpp::Node {
public:
    Subscriber();

private:
    void topic_callback(const message_interfaces::msg::NodeMsg::SharedPtr);

    rclcpp::Subscription<message_interfaces::msg::NodeMsg>::SharedPtr subscription_;
};
//
// Created by Dafan Wang on 2023/4/3.
//
#pragma once

#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "message_interfaces/msg/node_msg.hpp"
#include "message_interfaces/srv/start_talker.hpp"

class Publisher : public rclcpp::Node {
public:
    Publisher();

    void start(const std::shared_ptr<message_interfaces::srv::StartTalker::Request>&,
               const std::shared_ptr<message_interfaces::srv::StartTalker::Response>&);

private:
    size_t count_;
    rclcpp::TimerBase::SharedPtr timer_;
    message_interfaces::msg::NodeMsg message_;
    rclcpp::Publisher<message_interfaces::msg::NodeMsg>::SharedPtr publisher_;
};

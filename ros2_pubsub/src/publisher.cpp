//
// Created by Dafan Wang on 2023/4/3.
//
#include "publisher.h"

#include <chrono>

Publisher::Publisher() : Node("publisher"), count_(0) {
    // create a publisher which publishes to topic my_topic
    publisher_ = this->create_publisher<message_interfaces::msg::NodeMsg>("my_topic", 10);
}

void Publisher::start(const std::shared_ptr<message_interfaces::srv::StartTalker::Request>& request,
                      const std::shared_ptr<message_interfaces::srv::StartTalker::Response>& response) {
    message_.msg = request->msg;
    message_.number = request->number;

    auto interval = std::chrono::milliseconds(request->rate);

    // callback function, publish message at fixed rate (configurable)
    auto timer_callback = [&]() {
        ++this->count_;
        RCLCPP_DEBUG(this->get_logger(), "Publishing message: {msg: '%s', number: %f}", message_.msg.c_str(),
                     message_.number);
        publisher_->publish(message_);
    };

    // create timer
    timer_ = this->create_wall_timer(interval, timer_callback);

    RCLCPP_INFO(this->get_logger(), "Publishing message: {msg: '%s', number: %f} at interval %dms",
                message_.msg.c_str(), message_.number, request->rate);

    response->is_ok = true;
    response->msg = "publisher started";
}

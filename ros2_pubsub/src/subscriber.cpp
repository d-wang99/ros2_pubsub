//
// Created by Dafan Wang on 2023/4/4.
//

#include "subscriber.h"

Subscriber::Subscriber() : Node("subscriber") {
    subscription_ = this->create_subscription<message_interfaces::msg::NodeMsg>(
            "my_topic", 10, std::bind(&Subscriber::topic_callback, this, std::placeholders::_1));
}

void Subscriber::topic_callback(const message_interfaces::msg::NodeMsg::SharedPtr ptr) {
    RCLCPP_INFO(this->get_logger(), "Got: {msg: '%s', number: %f}", ptr->msg.c_str(), ptr->number);
}

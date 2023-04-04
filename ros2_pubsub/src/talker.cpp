//
// Created by Dafan Wang on 2023/4/3.
//
#include "publisher.h"

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    auto publisher = std::make_shared<Publisher>();

    auto service = publisher->create_service<message_interfaces::srv::StartTalker>(
            "start",
            std::bind(&Publisher::start, publisher, std::placeholders::_1, std::placeholders::_2)
    );

    RCLCPP_INFO(publisher->get_logger(), "start services registered");

    rclcpp::spin(publisher);
    rclcpp::shutdown();
    return 0;
}

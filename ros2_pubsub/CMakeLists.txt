cmake_minimum_required(VERSION 3.8)
project(ros2_pubsub)

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif ()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
find_package(rclcpp REQUIRED)
find_package(message_interfaces REQUIRED)

if (BUILD_TESTING)
    find_package(ament_lint_auto REQUIRED)
    # the following line skips the linter which checks for copyrights
    # comment the line when a copyright and license is added to all source files
    set(ament_cmake_copyright_FOUND TRUE)
    # the following line skips cpplint (only works in a git repo)
    # comment the line when this package is in a git repo and when
    # a copyright and license is added to all source files
    set(ament_cmake_cpplint_FOUND TRUE)
    ament_lint_auto_find_test_dependencies()
endif ()

add_executable(talker src/publisher.cpp src/talker.cpp)
ament_target_dependencies(talker rclcpp message_interfaces)

add_executable(listener src/subscriber.cpp src/listener.cpp)
ament_target_dependencies(talker rclcpp message_interfaces)
ament_target_dependencies(listener rclcpp message_interfaces)

install(TARGETS talker listener DESTINATION lib/${PROJECT_NAME}/)
ament_package()

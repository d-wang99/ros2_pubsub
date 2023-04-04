# ROS2 pubsub example

ROS2 simple pub-sub node with a customized message type.

## Requirements

1. Ubuntu 22.04.2 LTS
2. ROS2 humble
3. rosbridge websocket

## Usage

### Start publisher

```ros2 run ros2_pubsub talker```

### Start subscriber

```ros2 run ros2_pubsub listener```

### Trigger publisher

open webui/trigger.html, connect to rosbridge websocket server, then use the slider to set the message publishing
interval and fill in the message body.

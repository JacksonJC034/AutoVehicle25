cmake_minimum_required(VERSION 3.8)
project(open_loop)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclpy REQUIRED)

# Install Python files
install(PROGRAMS
  scripts/controller.py
  DESTINATION lib/${PROJECT_NAME}
)

# Install launch files
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

# Install model files
install(DIRECTORY
  models
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
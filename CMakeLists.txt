cmake_minimum_required(VERSION 3.23)
project(notification_center_mac_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(notification_center_mac_cpp main.cpp)
target_link_libraries(notification_center_mac_cpp  PUBLIC stdc++ "-framework CoreFoundation")
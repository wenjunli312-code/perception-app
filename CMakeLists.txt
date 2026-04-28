cmake_minimum_required(VERSION 3.16)
project(perception-app VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(perception-core REQUIRED)
find_package(vehicle-bridge REQUIRED)

add_executable(perception_app src/main.cpp)

target_link_libraries(perception_app
    PRIVATE
        perception_core::perception_core
        vehicle_bridge::vehicle_bridge
)

install(TARGETS perception_app
    RUNTIME DESTINATION bin
)

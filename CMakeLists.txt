cmake_minimum_required(VERSION 3.16)
project(perception-app VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(perception-core REQUIRED)
find_package(vehicle-bridge REQUIRED)
find_package(common-utils REQUIRED)

# nlohmann_json is a header-only third-party library
# Found via CMAKE_PREFIX_PATH pointing to third_party/{platform}/nlohmann_json/
find_package(nlohmann_json CONFIG REQUIRED)

add_executable(perception_app src/main.cpp)

target_link_libraries(perception_app
    PRIVATE
        perception_core::perception_core
        vehicle_bridge::vehicle_bridge
        common_utils::common_utils
        nlohmann_json
)

install(TARGETS perception_app
    RUNTIME DESTINATION bin
)
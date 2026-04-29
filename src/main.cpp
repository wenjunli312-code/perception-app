#include <iostream>
#include <perception_core/detector.h>
#include <perception_core/lane_detector.h>
#include <perception_core/point_pillars.h>
#include <perception_core/object_fusion.h>
#include <vehicle_bridge/vehicle_controller.h>
#include <vehicle_bridge/vehicle_state.h>

int main() {
    std::cout << "=== perception-app demo ===" << std::endl;

    // Initialize perception modules
    perception_core::YoloDetector detector;
    perception_core::LaneDetector lane_detector;
    perception_core::PointPillarsDetector point_pillars;
    perception_core::ObjectFusion fusion;

    std::cout << "All perception modules initialised." << std::endl;

    // Initialise vehicle controller
    vehicle_bridge::VehicleController controller;
    controller.send_command(0.0f, 0.0f, 0.0f);

    std::cout << "=== demo complete ===" << std::endl;
    return 0;
}
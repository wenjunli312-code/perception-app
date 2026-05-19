#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <perception_core/detector.h>
#include <perception_core/lane_detector.h>
#include <perception_core/point_pillars.h>
#include <perception_core/object_fusion.h>
#include <vehicle_bridge/vehicle_controller.h>
#include <vehicle_bridge/vehicle_state.h>
#include <common_utils/config.h>

using json = nlohmann::json;

int main() {
    std::cout << "=== perception-app demo ===" << std::endl;

    // Load config using common_utils (which uses nlohmann_json internally)
    common_utils::Config cfg("config/app.json");
    std::cout << "Config loaded: app.name=" << cfg.get<std::string>("app.name") << std::endl;
    std::cout << "Config loaded: detection.confidence_threshold="
              << cfg.get<double>("detection.confidence_threshold") << std::endl;

    // Also verify nlohmann_json is accessible directly
    json direct_json = json::parse(R"({"status":"ok","detections":3})");
    std::cout << "Direct nlohmann_json parse: " << direct_json.dump() << std::endl;

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
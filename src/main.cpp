#include <iostream>
#include <perception_core/camera.h>
#include <perception_core/lidar.h>
#include <perception_core/detector.h>
#include <vehicle_bridge/controller.h>

int main() {
    std::cout << "perception-app running" << std::endl;

    // Initialize sensors
    perception_core::Camera camera("config/camera.yaml");
    perception_core::Lidar lidar("config/lidar.yaml");

    // Run detection
    perception_core::Detector detector;
    detector.addSensor(&camera);
    detector.addSensor(&lidar);
    auto detections = detector.run();

    std::cout << "Detected " << detections.size() << " objects" << std::endl;

    // Send to vehicle controller
    vehicle_bridge::Controller controller("config/app.json");
    controller.send(detections);

    return 0;
}

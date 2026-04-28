# perception-app

A C++ perception application that serves as the final integration layer for the OpenBuilder demo project.

## Overview

`perception-app` ties together the `perception-core` and `vehicle-bridge` libraries to demonstrate a complete autonomous perception pipeline:

- Initializes Camera and Lidar sensor objects
- Runs object detection via `perception-core`
- Sends control commands via `vehicle-bridge`

## Dependencies

- `perception-core` — sensor abstraction and detection algorithms
- `vehicle-bridge` — vehicle communication and control interface

## Build

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
cmake --install build --prefix install
```

## Run

```bash
./bin/perception_app
```

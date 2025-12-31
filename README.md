# CAD to Simulation Asset Orchestrator

Utility: With the exploding demand for simulation assets and digital twins in robotics training (RL, sim2real) and validation, file conversion to suitable simulation friendly format is a critical bottleneck. 
This simple tool converts CAD-based STEP files into URDF for ROS 2, Isaac Sim, and manufacturing pipelines — parsing 9-link arms in 2 seconds using pure C++17 STL.

Modular architecture: Allows easy expansion to SDF (Gazebo), USD (Omniverse), OBJ meshes, and beyond.

## Project Structure & Workflow
robot-converter/
├── CMakeLists.txt
├── src/
│ ├── core/
│ │ └── robot_link.h
│ ├── parser/
│ │ ├── step_parser.h
│ │ └── step_parser.cpp
│ ├── exporter/
│ │ ├── urdf_exporter.h
│ │ └── urdf_exporter.cpp
│ └── main.cpp
├── test_data/
│ └── industrial_arm.step
├── build/ # Generated
└── README.md



## Pipeline ##
STEP ──[parser]──> RobotLinks ──[exporter]──> URDF


## Build & Test ##
mkdir build && cd build && cmake .. && cmake --build . && ./converter ../test_data/industrial_arm.step robot_arm
_Input:  ../test_data/industrial_arm.step  (9-link CAD)_
_Output: robot_arm.urdf                    (ROS digital twin)_




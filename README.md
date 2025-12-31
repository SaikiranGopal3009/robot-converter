# CAD to Simulation Asset Orchestrator

Utility: With the exploding demand for simulation assets and digital twins in robotics training (RL, sim2real) and validation, file conversion to suitable simulation friendly format is a critical bottleneck. 
This simple tool converts CAD-based STEP files into URDF for ROS 2, Isaac Sim, and manufacturing pipelines - parsing 9-link arms in 2 seconds using pure C++17 STL.

Modular architecture: Allows easy expansion to SDF (Gazebo), USD (Omniverse), OBJ meshes, and beyond.

## Project Structure & Workflow
```
├── CMakeLists.txt
├── src/
│   ├── core/robot_link.h
│   ├── parser/
│   │   ├── step_parser.h
│   │   └── step_parser.cpp
│   ├── exporter/
│   │   ├── urdf_exporter.h
│   │   └── urdf_exporter.cpp
│   └── main.cpp
├── test_data/
│   └── industrial_arm.step
└── README.md
```


## Pipeline ##
STEP ──[parser]──> RobotLinks ──[exporter]──> URDF

## Usage ##

**1. Clone & Build**
git clone https://github.com/YOURNAME/robot-converter.git
cd robot-converter
mkdir build && cd build
cmake ..
cmake --build .


**2. Convert STEP to URDF:**
./converter ../test_data/industrial_arm.step robot_arm

_Input:  ../test_data/industrial_arm.step  (9-link CAD)_
_Output: robot_arm.urdf                    (ROS digital twin)_



**3. Verify Output:**
cat robot_arm.urdf | grep joint_1
_Expected Output: <joint name="joint_1" type="revolute">_


**4. Dev Workflow After Code Changes:**
cd build
cmake --build . # Incremental rebuild (2s)
./converter ../test_data/industrial_arm.step robot_arm
_**Usage:** _./converter <input.step> <output_prefix>__





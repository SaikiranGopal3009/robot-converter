#pragma once
#include <string>
#include <vector>

struct RobotLink {
    std::string name;
    std::string mesh_file;
    double x = 0, y = 0, z = 0;
    double mass = 1.0;
};

using RobotLinks = std::vector<RobotLink>;

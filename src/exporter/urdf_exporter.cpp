#include "urdf_exporter.h"      
#include <iostream>             
#include "../core/robot_link.h" 
#include <fstream>              

void export_urdf(const RobotLinks& links, const std::string& filename) {
    std::ofstream out(filename);
    
    out << "<?xml version=\"1.0\"?>\n";
    out << "<robot name=\"industrial_arm\">\n";
    
    std::string parent = "base_link";
    for (size_t i = 0; i < links.size(); ++i) {
        // Every link gets visual geometry
        out << "  <link name=\"" << links[i].name << "\">\n";
        out << "    <visual>\n";
        out << "      <geometry>\n";
        out << "        <mesh filename=\"" << links[i].mesh_file << "\" scale=\"1 1 1\"/>\n";
        out << "      </geometry>\n";
        out << "    </visual>\n";
        out << "  </link>\n";
        
        if (i > 0) {
            // Joint connects parent → child
            out << "  <joint name=\"joint_" << i << "\" type=\"revolute\">\n";
            out << "    <parent link=\"" << parent << "\"/>\n";
            out << "    <child link=\"" << links[i].name << "\"/>\n";  
            out << "    <origin xyz=\"0 0 " << (0.1 * i) << "\" rpy=\"0 0 0\"/>\n";
            out << "    <axis xyz=\"0 0 1\"/>\n";
            out << "  </joint>\n";
        }
        parent = links[i].name;
    }
    
    out << "</robot>\n";
    std::cout << "URDF: " << filename << " (" << links.size() << " links)\n";
}

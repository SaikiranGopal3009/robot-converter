#include "../core/robot_link.h"
#include <regex>
#include <iostream>

RobotLinks parse_step(const std::string& content) {
    RobotLinks links;
    std::regex part_regex(R"(#(\d+)=PRODUCT_DEFINITION_SHAPE\('([^']+)'.*?)");
    std::smatch match;
    
    std::sregex_iterator begin(content.begin(), content.end(), part_regex);
    std::sregex_iterator end;
    
    for (std::sregex_iterator i = begin; i != end; ++i) {
        RobotLink link;
        link.name = (*i)[2];
        link.mesh_file = "package://robot_meshes/" + link.name + ".step";
        links.push_back(link);
    }
    
    std::cout << "Parser extracted " << links.size() << " parts\n";
    return links;
}

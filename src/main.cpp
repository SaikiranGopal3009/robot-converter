#include <iostream>
#include <fstream>
#include "parser/step_parser.h"
#include "exporter/urdf_exporter.h"

int main(int argc, char* argv[]) {
    std::cout << "Modular STEP → URDF\n";
    
    if (argc < 3) {
        std::cout << "Usage: ./converter input.step output\n";
        return 1;
    }
    
    std::ifstream file(argv[1]);
    std::string content, line;
    while (std::getline(file, line)) content += line + "\n";
    
    auto links = parse_step(content);
    export_urdf(links, std::string(argv[2]) + ".urdf");
    
    return 0;
}

cmake_minimum_required(VERSION 3.20)
project(robot_converter)

set(CMAKE_CXX_STANDARD 17)

add_executable(converter 
    src/main.cpp
    src/parser/step_parser.cpp
    src/exporter/urdf_exporter.cpp
)

target_include_directories(converter PRIVATE 
    src 
    src/core 
    src/parser 
    src/exporter
)

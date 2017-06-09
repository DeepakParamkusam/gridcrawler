cmake_minimum_required(VERSION 2.8)
# Declare the name of the CMake Project
project(game)
# Add the directory to search for header files
include_directories(src)
# Define an executable target called hello_world_node
add_executable(game src/game.cpp src/robot.cpp)

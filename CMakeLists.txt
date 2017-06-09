cmake_minimum_required(VERSION 2.8)
# Declare the name of the CMake Project
project(game)
# Add the directories
include_directories(src include)
# Define an executable target 
add_executable(gridcrawler src/game.cpp src/robot.cpp)

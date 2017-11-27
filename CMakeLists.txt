cmake_minimum_required(VERSION 3.8)
project(adventofcode)

set(CMAKE_CXX_FLAGS "-std=c++17")

include_directories(include)
file(GLOB SOURCES "src/*/*.cpp" "AoC.cpp")

add_executable(adventofcode ${SOURCES})

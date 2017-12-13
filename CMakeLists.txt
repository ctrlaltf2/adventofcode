cmake_minimum_required(VERSION 3.8)
project(adventofcode)

find_package(Boost 1.65.1 COMPONENTS program_options REQUIRED)
set(CMAKE_CXX_FLAGS "-Wall -std=c++17 -O2")

include_directories(include ${Boost_INCLUDE_DIR})
file(GLOB SOURCES "src/*/*.cpp" "AoC.cpp")

add_executable(adventofcode ${SOURCES})
target_link_libraries(adventofcode LINK_PUBLIC ${Boost_LIBRARIES})

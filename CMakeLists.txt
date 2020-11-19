cmake_minimum_required(VERSION 3.8)
project(adventofcode
    LANGUAGES CXX
    DESCRIPTION "advent of code solutions"
)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

find_package(Boost 1.65.1 COMPONENTS program_options REQUIRED)

set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=-*,bugprone-*,llvm-*,cppcoreguidelines-*,clang-analyzer-*,misc-*,modernize-*,performance-*,portability-*,-modernize-use-trailing-return-type")

include_directories(include ${Boost_INCLUDE_DIR})

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(adventofcode
    ${SOURCES}
)

set_target_properties(adventofcode
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
        RUNTIME_OUTPUT_DIRECTORY bin
)

target_compile_features(adventofcode
    PUBLIC
        cxx_std_17
)

target_compile_options(adventofcode
    PUBLIC
        -Wall
        -Wextra
        -O2
        -fsanitize=address,undefined,leak
        -Wshadow
        -Wnon-virtual-dtor
        -Wold-style-cast
        -Wunused
        -Woverloaded-virtual
        -pedantic-errors
        -Wnull-dereference
)

target_link_libraries(adventofcode
    PUBLIC
        ${Boost_LIBRARIES}
        -fsanitize=address,undefined,leak
)


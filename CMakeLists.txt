cmake_minimum_required(VERSION 3.17)
project(GameLife)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(GameOfLife Field.cpp Field.h Parser.cpp Parser.h main.cpp)
target_link_libraries(GameOfLife gtest gtest_main)

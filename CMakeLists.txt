cmake_minimum_required(VERSION 3.0)

project(curves LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

find_package(Catch2 3 REQUIRED)

add_executable(test test.cpp circle.cpp ellipse.cpp helix.cpp)
target_link_libraries(test Catch2::Catch2WithMain)

add_executable(curves main.cpp)

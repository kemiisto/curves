cmake_minimum_required(VERSION 3.0)

project(curves LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

find_package(Catch2 3 REQUIRED)

add_library(curves lib/src/circle.cpp lib/src/ellipse.cpp lib/src/helix.cpp)
target_include_directories(curves PRIVATE lib/include)

add_executable(test test/src/test.cpp)
target_include_directories(test PRIVATE lib/include)
target_link_libraries(test curves Catch2::Catch2WithMain)

add_executable(app app/src/main.cpp)
target_include_directories(app PRIVATE lib/include)
target_link_libraries(app curves)

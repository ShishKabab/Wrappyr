project(Box2DC)
cmake_minimum_required(VERSION 2.8)

set(BUILD_SHARED_LIBS true)
include_directories(/usr/local/include/Box2D)
add_definitions(-fpermissive)
add_library(Box2DC box2d.cpp)
target_link_libraries(Box2DC /usr/local/lib/libBox2D.so)

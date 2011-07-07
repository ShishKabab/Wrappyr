project(Box2D_C)
cmake_minimum_required(VERSION 2.8)

include_directories(/usr/local/include/Box2D)
add_executable(Box2D_Test main.cpp wrapper.cpp)
target_link_libraries(Box2D_Test /usr/local/lib/libBox2D.so)

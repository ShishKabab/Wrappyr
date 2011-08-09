project(Box2DC)
cmake_minimum_required(VERSION 2.8)

set(BUILD_SHARED_LIBS true)

# include_directories(/usr/local/include/CEGUI)
# add_library(CEGUIC cegui.cpp)
# target_link_libraries(CEGUIC /usr/local/lib/libCEGUIBase.so)

include_directories(/usr/local/include/Box2D)
add_library(Box2DC box2d.cpp)
target_link_libraries(Box2DC /usr/local/lib/libBox2D.so)

# add_executable(Box2DC_Test main.cpp)
# target_link_libraries(Box2DC_Test Box2DC)

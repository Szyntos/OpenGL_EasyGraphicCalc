cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp Axis.cpp Axis.h Point.cpp Point.h Cube.cpp Cube.h Grid.cpp Grid.h Color.cpp Color.h)

target_link_libraries(untitled -lfreeglut -lglew32 -lopengl32 -lglu32)
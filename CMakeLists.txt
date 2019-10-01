cmake_minimum_required(VERSION 3.14)
project(open_gl_tutorial)

include_directories(/usr/local/include)
include_directories(/usr/local/include/GL)

set(CMAKE_CXX_STANDARD 17)

find_package(GLFW3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
link_libraries(${GLFW_LIBRARIES})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
link_libraries(${OPENGL_LIBRARIES})

add_executable(open_gl_tutorial main.cpp)

cmake_minimum_required(VERSION 3.10)
project(MyOpenGLProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add the executable
add_executable(MyOpenGLProject
    src/main.cpp
    src/glad.c
)

# Include directories
target_include_directories(MyOpenGLProject PRIVATE include)

# Find and link libraries
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(MyOpenGLProject PRIVATE OpenGL::GL glfw)

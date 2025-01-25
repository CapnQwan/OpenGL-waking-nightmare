# Option 1: Use environment variable (recommended)
if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" 
        CACHE STRING "Vcpkg toolchain file")
else()
    set(CMAKE_TOOLCHAIN_FILE "C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake" 
        CACHE STRING "Vcpkg toolchain file")
endif()

cmake_minimum_required(VERSION 3.10)
project(WakingNightmare2D)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add the executable
add_executable(MyOpenGLProject
    src/main.cpp
    src/glad.c
)

# Include directories
target_include_directories(MyOpenGLProject PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/KHR
    ${CMAKE_SOURCE_DIR}/include/glad
)

# Find and link libraries
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(MyOpenGLProject PRIVATE OpenGL::GL glfw)

# Copy DLLs to output directory
if(WIN32)
    add_custom_command(TARGET MyOpenGLProject POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:glfw>
            $<TARGET_FILE_DIR:MyOpenGLProject>
    )
endif()

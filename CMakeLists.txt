set(CMAKE_TOOLCHAIN_FILE "C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

cmake_minimum_required(VERSION 3.10)
project(WakingNightmare2D)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add the executable
set(CORE_SOURCES
    src/Core/Core.cpp
    src/Core/ServiceLocator.cpp
    src/Core/GameObjectManager/GameObjectManager.cpp
)

set(OBJECT_SOURCES
    src/Core/GameObjects/Object.cpp
    src/Core/GameObjects/GameObjects/GameObject.cpp
    src/Core/GameObjects/Components/Component.cpp
    src/Core/GameObjects/Components/BehaviourComponent/BehaviourComponent.cpp
    src/Core/GameObjects/Components/RenderComponents/MeshRenderer.cpp
)

set(RENDERER_SOURCES
    src/Core/Rendering/Renderer.cpp
    src/Core/Rendering/Materials/Material.cpp
)

set(TIME_SOURCES
    src/Core/Time/Time.cpp
)

set(UTILS_SOURCES
    src/Utils/Math/Mathf.cpp
    src/Utils/Geometry/Mesh.cpp
    src/Utils/Math/Transform/Transform.cpp
    src/Utils/Math/Vector/Vector3.cpp
    src/Utils/Math/Vector/Vector2.cpp
)

set(SHADERS_SOURCES
    src/Shaders/default_vertex.glsl
    src/Shaders/default_fragment.glsl
)


add_executable(MyOpenGLProject
    src/main.cpp
    src/glad/glad.c
    ${CORE_SOURCES}
    ${OBJECT_SOURCES}
    ${RENDERER_SOURCES}
    ${TIME_SOURCES}
    ${UTILS_SOURCES}
)

# Include directories
target_include_directories(MyOpenGLProject PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/KHR
    ${CMAKE_SOURCE_DIR}/include/glad
    ${CMAKE_SOURCE_DIR}/src
    "$ENV{VCPKG_ROOT}/installed/x64-windows/include"
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

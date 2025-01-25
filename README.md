# OpenGL Waking Nightmare 2D

## Welcome to the repository of the project "Waking Nightmare 2D".

This project is a game engine made using OpenGL intended for the development of 2D games on the web utilizing WASM and WebGL.

## Prerequisites

- CMake 3.10 or higher
- Visual Studio 2019 or higher
- vcpkg package manager

## Setup Instructions

1. Install vcpkg:

    ### Create a directory for vcpkg
    ```
    mkdir C:/dev
    cd C:/dev
    ```
    ### Clone vcpkg
    ```
    git clone https://github.com/Microsoft/vcpkg.git
    ```
    ### Run the bootstrap script
    ```
    .\vcpkg\bootstrap-vcpkg.bat
    ```
    Install required packages
    .\vcpkg\vcpkg install glfw3:x64-windows

2. Set up environment variable:

    - Create a system environment variable named `VCPKG_ROOT`
    - Set its value to your vcpkg installation path (e.g., `C:/dev/vcpkg`)

## Building the Project

### Create build directory
```
mkdir build
cd build
``` 
### Configure with CMake
```
cmake ..
``` 
### Build 
```
cmake --build . --config Release
```

## Running the Project

The executable will be located in `build/Release/MyOpenGLProject.exe`

## Project Structure

```
project_root/
├── include/
│ ├── glad/
│ │ ├── glad.h
│ │ └── khrplatform.h
│ └── KHR/
│ └── khrplatform.h
├── src/
│ ├── main.cpp
│ └── glad.c
└── CMakeLists.txt
```

This should help you get everything set up correctly. Let me know if you run into any other issues!
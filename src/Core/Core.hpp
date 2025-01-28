#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Time/Time.hpp"

class Core {
private:
    GLFWwindow* window;
    Time time;

public:
    Core();
    ~Core();
    
    bool Initialize();
    void Run();
    void Shutdown();

private:
    void ProcessInput();
    void Update();
}; 
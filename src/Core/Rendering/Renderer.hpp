#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include "../../Utils/Geometry/Mesh.hpp"

struct GLFWwindow;

class Renderer {
private:
    GLFWwindow* window;
    Mesh mesh;

public:
    Renderer(GLFWwindow* window);
    ~Renderer();

    void Initialize();
    void Render();
};

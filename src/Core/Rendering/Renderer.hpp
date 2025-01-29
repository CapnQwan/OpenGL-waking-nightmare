#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

struct GLFWwindow;  // Forward declaration

class Renderer {
private:
    GLFWwindow* window;
    unsigned int VAO, VBO;
    unsigned int shaderProgram;

public:
    Renderer(GLFWwindow* window);
    ~Renderer();

    void Initialize();
    void Render();
    //TODO: move to a separate class so that file management is centralized
    std::string LoadShaderSource(const std::string& filepath);
};

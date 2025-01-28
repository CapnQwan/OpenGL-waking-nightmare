#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

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
};

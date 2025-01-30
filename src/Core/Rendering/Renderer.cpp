#include "Renderer.hpp"
#include "../../Utils/Geometry/Mesh.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

Renderer::Renderer(GLFWwindow* window) : window(window) {
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
    Initialize();
}

Renderer::~Renderer() {
}

void Renderer::Initialize() {
    // Set up vertex data for a triangle
    std::vector<float> vertices = {
        -0.5f, -0.5f, 0.0f,  // Bottom left
         0.5f, -0.5f, 0.0f,  // Bottom right
         0.0f,  0.5f, 0.0f   // Top
    };

    std::vector<unsigned int> indices = {
        0, 1, 2
    };


    mesh = std::make_unique<Mesh>(vertices, indices);
}

void Renderer::Render() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    mesh->Render();

    GLenum err;
    while((err = glGetError()) != GL_NO_ERROR) {
        std::cout << "OpenGL error: " << err << std::endl;
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
}

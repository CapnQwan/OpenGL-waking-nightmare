#include "Core.hpp"
#include "ServiceLocator.hpp"
#include "Time/Time.hpp"
#include <iostream>
#include <string>

Core::Core() : window(nullptr) {}

Core::~Core() {
    Shutdown();
}

bool Core::Initialize() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    // Configure GLFW to use Modern OpenGL 4.6
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create window
    window = glfwCreateWindow(800, 600, "Waking Nightmare", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
    
    glfwMakeContextCurrent(window);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    // Set viewport and callback
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    });
    
    auto time = std::make_shared<Time>();
    ServiceLocator::Provide<Time>(time);

    return true;
}

void Core::Run() {
    while (!glfwWindowShouldClose(window)) {
        ProcessInput();
        Update();
        Render();
    }
}

void Core::ProcessInput() {
    // Handle input here
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void Core::Update() {
    ServiceLocator::Get<Time>()->Update();
    
    // Update FPS in title every frame
    float dt = ServiceLocator::Get<Time>()->GetDeltaTime();
    float fps = 1.0f / dt;
    std::string title = "Waking Nightmare | FPS: " + std::to_string(static_cast<int>(fps)) + 
                       " | dt: " + std::to_string(dt).substr(0, 5) + "ms";
    glfwSetWindowTitle(window, title.c_str());
    
    // Update game state here
}

void Core::Render() {
    // Render
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Swap buffers and poll events
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Core::Shutdown() {
    if (window) {
        glfwDestroyWindow(window);
        window = nullptr;
    }
    glfwTerminate();
}
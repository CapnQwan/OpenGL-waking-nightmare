#include "Material.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <filesystem>

std::shared_ptr<Material> Material::defaultMaterial = nullptr;

Material::Material(const std::string& name, const std::string& vertexShaderSrc, const std::string& fragmentShaderSrc)
    : name(name), vertexShaderSrc(vertexShaderSrc), fragmentShaderSrc(fragmentShaderSrc) {
    Initialize();
}

Material::~Material() {
    glDeleteProgram(shaderProgram);
}

void Material::Initialize() {
    // Load shader sources
    std::string vertexShaderStr = LoadShaderSource(vertexShaderSrc);
    std::string fragmentShaderStr = LoadShaderSource(fragmentShaderSrc);
    const char* vertexShaderSource = vertexShaderStr.c_str();
    const char* fragmentShaderSource = fragmentShaderStr.c_str();

    // Compile shaders
    unsigned int vertexShader = CompileShader(vertexShaderSource, GL_VERTEX_SHADER);
    unsigned int fragmentShader = CompileShader(fragmentShaderSource, GL_FRAGMENT_SHADER);

    // Create shader program
    shaderProgram = glCreateProgram();

    // Attach shaders to the program
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Error Checking for Shader Linking
    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cerr << "ERROR: Shader Program Linking Failed\n" << infoLog << std::endl;
    }


    // Clean up shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Material::Use() {
    if (shaderProgram == 0) {
        std::cerr << "ERROR: Shader program is invalid, cannot use!" << std::endl;
        return;
    }

    glUseProgram(shaderProgram);
}

unsigned int Material::CompileShader(const char* source, GLenum shaderType) {
    unsigned int shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &source, NULL);

    glCompileShader(shader);

    // Check for compilation errors
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cerr << "Shader compilation failed: " << infoLog << std::endl;
    }

    return shader;
}

std::string Material::LoadShaderSource(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Failed to open shader file: " << filepath << std::endl;
        std::cout << "Absolute path attempted: " << std::filesystem::absolute(filepath) << std::endl;
        throw std::runtime_error("Failed to load shader: " + filepath);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

std::shared_ptr<Material> Material::GetDefaultMaterial() {
    static bool isDestroyed = false;

    if (!defaultMaterial) {
        std::string vertexPath = "../../src/Shaders/default_vertex.glsl";
        std::string fragmentPath = "../../src/Shaders/default_fragment.glsl";
        // Initialize default material only once
        defaultMaterial = std::make_shared<Material>(
            "DefaultMaterial",
            vertexPath,
            fragmentPath
        );
    }
    
    return defaultMaterial;
}
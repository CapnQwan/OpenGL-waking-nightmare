#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

class Material {
private:
    std::string name;
    std::string vertexShaderSrc;
    std::string fragmentShaderSrc;
    unsigned int shaderProgram;

    static Material* defaultMaterial;

public:
    Material(const std::string& name, const std::string& vertexShader, const std::string& fragmentShader);
    ~Material();

    void Initialize();
    void Use();
    unsigned int CompileShader(const char* source, GLenum shaderType);
    std::string LoadShaderSource(const std::string& filepath);

    static Material* GetDefaultMaterial();
};


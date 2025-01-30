#pragma once
#include <vector>
#include <string>
#include <memory>
#include <glad/glad.h>
#include "../../Core/Rendering/Materials/Material.hpp"

class Mesh {
private:
    // Mesh data
    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    // OpenGL object handles
    // TODO: look into using a single VAO for multiple meshes (batch rendering)
    // This will make the number of draw calls much lower and improve performance
    unsigned int VAO, VBO, EBO;
    
    std::unique_ptr<Material> material;

public:
    Mesh(const std::vector<float>& vertices = {}, const std::vector<unsigned int>& indices = {}, std::unique_ptr<Material> material = nullptr);
    ~Mesh();

    void Render();

private:
    void SetupMesh();
};
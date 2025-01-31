#pragma once
#include <vector>
#include <string>
#include <memory>
#include <glad/glad.h>

class Mesh {
private:
    // Mesh data
    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    // OpenGL object handles
    // TODO: look into using a single VAO for multiple meshes (batch rendering)
    // This will make the number of draw calls much lower and improve performance
    unsigned int VAO, VBO, EBO;

public:
    //TODO: Remove default triangle to a static class
    Mesh(const std::vector<float>& vertices = {}, 
    const std::vector<unsigned int>& indices = {});
    ~Mesh();

    void Render();

    static std::shared_ptr<Mesh> GetDefaultTriangle();
    static std::shared_ptr<Mesh> GetDefaultSquare();

private:
    void SetupMesh();
};

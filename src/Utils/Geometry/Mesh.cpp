#include "Mesh.hpp"
#include <glad/glad.h>
#include "../../Core/Rendering/Materials/Material.hpp"
#include <iostream>
#include <memory>

Mesh::Mesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices)
    : vertices(vertices.empty() ? GetDefaultTriangle()->vertices : vertices),
      indices(indices.empty() ? GetDefaultTriangle()->indices : indices) {
    SetupMesh();
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}   

void Mesh::Render() {    
    if (vertices.empty()) {
        std::cerr << "WARNING: Attempted to render an empty mesh!" << std::endl;
        return;
    }

    // TODO: Add model matrix uniform
    //GLint modelLoc = glGetUniformLocation(material->GetShaderProgram(), "uModel");
    //glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    glBindVertexArray(VAO);

    // Draw using indexed rendering (EBO)
    if (!indices.empty()) {
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, 0);
    } else {
        glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(vertices.size() / 3)); // Assuming 3 floats per vertex
    }

    // Unbind VAO
    glBindVertexArray(0);
}

void Mesh::SetupMesh() { 
    // Generate VAO, VBO, and EBO
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    // Bind VAO
    glBindVertexArray(VAO);

    // Bind and buffer VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    // Bind and buffer EBO (Element Buffer Object)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    // Define vertex attributes (example: positions only)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Unbind VAO to prevent accidental modification
    glBindVertexArray(0);
}

std::shared_ptr<Mesh> Mesh::GetDefaultTriangle() {
    static std::shared_ptr<Mesh> defaultTriangle = std::make_shared<Mesh>(
        std::vector<float>{ -0.5f, -0.5f, 0.0f,  0.5f, -0.5f, 0.0f,  0.0f,  0.5f, 0.0f },
        std::vector<unsigned int>{ 0, 1, 2 }
    );
    return defaultTriangle;
}

std::shared_ptr<Mesh> Mesh::GetDefaultSquare() {
    static std::shared_ptr<Mesh> defaultSquare = std::make_shared<Mesh>(
        std::vector<float>{ -0.5f, -0.5f, 0.0f,  0.5f, -0.5f, 0.0f,  0.5f,  0.5f, 0.0f, -0.5f,  0.5f, 0.0f },
        std::vector<unsigned int>{ 0, 1, 2, 3 }
    );
    return defaultSquare;
}

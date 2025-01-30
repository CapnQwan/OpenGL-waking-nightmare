#include "Mesh.hpp"
#include <glad/glad.h>
#include "../../Core/Rendering/Materials/Material.hpp"

#define CHECK_GL_ERROR() { GLenum err; while((err = glGetError()) != GL_NO_ERROR) { std::cerr << "OpenGL error: " << err << " at line " << __LINE__ << std::endl; } }

Mesh::Mesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices, Material* material) : vertices(vertices), indices(indices) {
    this->material = (material) ? material : Material::GetDefaultMaterial();
    
    SetupMesh();
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}   

void Mesh::Render() {
    std::cout << "Rendering Mesh..." << std::endl;

    if (VAO == 0 || VBO == 0 || EBO == 0) {
        std::cerr << "Error: VAO, VBO, or EBO is not initialized!" << std::endl;
        return;
    }

    material->Use();
    
    GLint currentProgram;
    glGetIntegerv(GL_CURRENT_PROGRAM, &currentProgram);
    std::cout << "Current Shader Program: " << currentProgram << std::endl;
    CHECK_GL_ERROR();

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    GLint boundVAO;
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &boundVAO);
    std::cout << "Bound VAO: " << boundVAO << std::endl;

    GLint arrayBuffer;
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &arrayBuffer);
    std::cout << "Bound VBO: " << arrayBuffer << std::endl;

    GLint isAttribEnabled;
    glGetVertexAttribiv(0, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &isAttribEnabled);
    std::cout << "Vertex Attribute 0 Enabled: " << isAttribEnabled << std::endl;

    CHECK_GL_ERROR();

    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, 0);
    CHECK_GL_ERROR();
    glBindVertexArray(0);   
    CHECK_GL_ERROR();
}

void Mesh::SetupMesh() {
    // Generate VAO, VBO, and EBO
    glGenVertexArrays(1, &VAO);
    if (VAO == 0) {
        std::cerr << "Error: Failed to generate VAO!" << std::endl;
    }
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

    std::cout << "Mesh initialization" << std::endl;
    std::cout << "Generated VAO: " << VAO << std::endl;
    std::cout << "Generated VBO: " << VBO << std::endl;
    std::cout << "Generated EBO: " << EBO << std::endl;
}

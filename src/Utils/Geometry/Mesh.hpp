#include <vector>
#include <string>
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
    Mesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);
    ~Mesh();

    void Render();

private:
    void SetupMesh();
};
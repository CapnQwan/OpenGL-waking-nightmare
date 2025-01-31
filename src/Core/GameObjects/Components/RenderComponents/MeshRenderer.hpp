#pragma once
#include "../Component.hpp"
#include "../../../../Utils/Geometry/Mesh.hpp"
#include "../../../Core/Rendering/Materials/Material.hpp"

class MeshRenderer : public Component {
private:
    std::shared_ptr<Mesh> mesh;
    std::shared_ptr<Material> material;

public:
    MeshRenderer();
    ~MeshRenderer();

    void Render();
    void SetMesh(std::shared_ptr<Mesh> mesh);
    std::shared_ptr<Mesh> GetMesh();
    void SetMaterial(std::shared_ptr<Material> material);
    std::shared_ptr<Material> GetMaterial();
};


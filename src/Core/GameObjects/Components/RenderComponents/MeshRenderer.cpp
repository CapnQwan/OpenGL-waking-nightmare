#include "MeshRenderer.hpp"

MeshRenderer::MeshRenderer(GameObject* gameObject) : Component(gameObject) {}

MeshRenderer::~MeshRenderer() {}

void MeshRenderer::Render() {
    if (!mesh) {
        std::cerr << "MeshRenderer Error: No mesh assigned to " << gameObject->GetName() << "!" << std::endl;
        return;
    }
    if (!material) {
        std::cerr << "MeshRenderer Error: No material assigned to " << gameObject->GetName() << "!" << std::endl;
        return;
    }

    material->Use();
    mesh->Render();
}

void MeshRenderer::SetMesh(std::shared_ptr<Mesh> mesh) {
    this->mesh = mesh;
}

std::shared_ptr<Mesh> MeshRenderer::GetMesh() {
    return mesh;
}

void MeshRenderer::SetMaterial(std::shared_ptr<Material> material) {
    this->material = material;
}

std::shared_ptr<Material> MeshRenderer::GetMaterial() {
    return material;
}


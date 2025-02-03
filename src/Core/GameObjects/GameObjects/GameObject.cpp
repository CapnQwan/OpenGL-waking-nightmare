#include "GameObject.hpp"
#include "../Components/Component.hpp"
#include "../Components/RenderComponents/MeshRenderer.hpp"
#include <iostream>
#include <algorithm>

GameObject::GameObject() : Object() {}

GameObject::~GameObject() {
    components.clear();
}

void GameObject::Awake() {
    for (auto& component : components) {
        component.second->HandleAwake();
    }
}

void GameObject::Start() {
    for (auto& component : components) {
        component.second->HandleStart();
    }
}

void GameObject::Update() {
    for (auto& component : components) {
        component.second->HandleUpdate();
    }
}

void GameObject::Render() {
    MeshRenderer* meshRenderer = GetComponent<MeshRenderer>();
    if (meshRenderer) {
        meshRenderer->Render();
    }
}

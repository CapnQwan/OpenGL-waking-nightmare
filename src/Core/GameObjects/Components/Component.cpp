#include "Component.hpp"

Component::Component(GameObject* gameObject) : gameObject(gameObject) {
    transform = gameObject->GetTransform();
    gameObject->AddComponent(this);
}

Component::~Component() {}
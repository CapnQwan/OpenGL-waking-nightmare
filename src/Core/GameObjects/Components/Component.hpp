#pragma once
#include "Object.hpp"
#include "../GameObjects/GameObject.hpp"

class Component : public Object {
public:
    GameObject* gameObject;
    Transform* transform;

public:
    Component(GameObject* gameObject);
    virtual ~Component();

    Transform* GetTransform() { return transform; }
    GameObject* GetGameObject() { return gameObject; }
};


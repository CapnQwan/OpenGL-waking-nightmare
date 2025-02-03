#pragma once
#include "Object.hpp"
#include "../../Utils/Math/Transform/Transform.hpp"
#include "../Components/Component.hpp"
#include <unordered_map>
#include <typeindex>
#include <memory>

class GameObject : public Object {
private:
    std::unordered_map<std::type_index, std::unique_ptr<Component>> components;
    Transform transform;

public:
    GameObject();
    ~GameObject();

    Transform* GetTransform() { return &transform; }

    template<typename T>
    T* GetComponent() {
        std::type_index type = typeid(T);
        if (components.find(type) != components.end()) {
            return dynamic_cast<T*>(components[type].get());
        }
        return nullptr;
    }

    template<typename T>
    bool HasComponent() {
        return components.find(typeid(T)) != components.end();
    }

    template<typename T>
    void AddComponent(T* component) {
        std::type_index type = typeid(T);
        if (components.find(type) == components.end()) {
            components[type] = std::unique_ptr<T>(component);
        } else {
            std::cerr << "GameObject already has a component of type " << type.name() << std::endl;
        }
    }

    template<typename T>
    void RemoveComponent() {
        std::type_index type = typeid(T);
        components.erase(type);
    }

    void Awake();
    void Start();
    void Update();
    void Render();
};


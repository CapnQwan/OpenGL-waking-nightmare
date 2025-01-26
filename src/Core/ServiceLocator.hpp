#pragma once
#include <GLFW/glfw3.h>
#include <memory>
#include <unordered_map>
#include <string>
#include <stdexcept>
#include <typeindex>
#include <iostream>

class ServiceLocator {
private:
    static std::unordered_map<std::type_index, std::shared_ptr<void>> services;

public:
    ServiceLocator();
    ~ServiceLocator();

    // Register a service of type T
    template <typename T>
    static void Provide(std::shared_ptr<T> service) {
        services[std::type_index(typeid(T))] = service;
    }

    // Get a service of type T
    template <typename T>
    static T* Get() {
        auto it = services.find(std::type_index(typeid(T)));
        if (it != services.end()) {
            return static_cast<T*>(it->second.get());
        }
        return nullptr;
    }

    // Get a shared service of type T
    template <typename T>
    static std::shared_ptr<T> GetShared() {
        auto it = services.find(std::type_index(typeid(T)));
        if (it != services.end()) {
            return std::static_pointer_cast<T>(it->second);
        }
        return nullptr;
    }
};
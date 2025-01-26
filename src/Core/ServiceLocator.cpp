#include "ServiceLocator.hpp"

ServiceLocator::ServiceLocator() {}

ServiceLocator::~ServiceLocator() {}

std::unordered_map<std::type_index, std::shared_ptr<void>> ServiceLocator::services;

template <typename T>
void ServiceLocator::Provide(std::shared_ptr<T> service) {
    services[std::type_index(typeid(T))] = service;
}

template <typename T>
T* ServiceLocator::Get() {
    return static_cast<T*>(services[std::type_index(typeid(T))].get());
}

template <typename T>
std::shared_ptr<T> ServiceLocator::GetShared() {
    return std::static_pointer_cast<T>(services[std::type_index(typeid(T))]);
}
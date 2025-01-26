#include "Core/ServiceLocator.hpp"

ServiceLocator::ServiceLocator() {}

ServiceLocator::~ServiceLocator() {}

std::unordered_map<std::type_index, std::shared_ptr<void>> ServiceLocator::services;
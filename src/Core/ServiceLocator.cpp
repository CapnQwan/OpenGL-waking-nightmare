#include "ServiceLocator.hpp"

ServiceLocator::ServiceLocator() {}

ServiceLocator::~ServiceLocator() {}

// Definition of static member variable
std::unordered_map<std::type_index, std::shared_ptr<void>> ServiceLocator::services;

#include "Object.hpp"
#include <iostream>

std::atomic<int> Object::nextID = 0;

Object::Object(const std::string& name) : id(nextID++), name(name) {}

Object::~Object() {
    std::cout << "Destroying Object: " << name << " (ID: " << id << ")" << std::endl;
}
#include "GameObject.hpp"
#include "../Components/Component.hpp"
#include <iostream>
#include <algorithm>

GameObject::GameObject() : Object() {}

GameObject::~GameObject() {
    components.clear();
}
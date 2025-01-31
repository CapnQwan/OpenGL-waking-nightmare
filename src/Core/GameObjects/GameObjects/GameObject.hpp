#pragma once
#include "Object.hpp"
#include "../../Utils/Math/Transform/Transform.hpp"

class GameObject : public Object {
public:
    GameObject();
    ~GameObject();

    Transform transform;
};

#pragma once
#include "../Vector/Vector3.hpp"

class Transform {
private:
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;

public:
    Transform(Vector3 position = Vector3(0, 0, 0), Vector3 rotation = Vector3(0, 0, 0), Vector3 scale = Vector3(1, 1, 1));
    ~Transform();

    void Translate(Vector3 translation);
    void Rotate(Vector3 rotation);
    void Scale(Vector3 scale);

    Vector3 GetPosition();
    Vector3 GetRotation();
    Vector3 GetScale();

    void SetPosition(Vector3 position);
    void SetRotation(Vector3 rotation);
    void SetScale(Vector3 scale);
};


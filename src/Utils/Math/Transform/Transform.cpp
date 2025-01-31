#include "Transform.hpp"

Transform::Transform(Vector3 position, Vector3 rotation, Vector3 scale) : position(position), rotation(rotation), scale(scale) {}

Transform::~Transform() {}

void Transform::Translate(Vector3 translation) {
    position.Add(translation);
}

void Transform::Rotate(Vector3 rotation) {
    rotation.Add(rotation);
}

void Transform::Scale(Vector3 scale) {
    this->scale.Add(scale);
}

Vector3 Transform::GetPosition() {
    return position;
}

Vector3 Transform::GetRotation() {
    return rotation;
}

Vector3 Transform::GetScale() {
    return scale;
}

void Transform::SetPosition(Vector3 position) {
    this->position = position;
}

void Transform::SetRotation(Vector3 rotation) {
    this->rotation = rotation;
}

void Transform::SetScale(Vector3 scale) {
    this->scale = scale;
}


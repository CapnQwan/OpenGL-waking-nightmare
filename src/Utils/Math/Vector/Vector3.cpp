#include "Vector3.hpp"
#include <math.h>

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3::~Vector3() {}

void Vector3::Normalize() {
    float length = sqrt(x * x + y * y + z * z);
    x /= length;
    y /= length;
    z /= length;
}

void Vector3::Normalize(Vector3& vector) {
    float length = sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
    vector.x /= length;
    vector.y /= length;
    vector.z /= length;
}

Vector3 Vector3::Normalized() {
    Vector3 normalized = *this;
    Normalize(normalized);
    return normalized;
}

float Vector3::Magnitude() {
    return sqrt(x * x + y * y + z * z);
}

void Vector3::Add(Vector3& vector) {
    x += vector.x;
    y += vector.y;
    z += vector.z;
}

void Vector3::Subtract(Vector3& vector) {
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;
}

void Vector3::Multiply(Vector3& vector) {
    x *= vector.x;
    y *= vector.y;
    z *= vector.z;
}

void Vector3::Divide(Vector3& vector) {
    x /= vector.x;
    y /= vector.y;
    z /= vector.z;
}

void Vector3::Scale(float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
}

float Vector3::Dot(Vector3& vector) {
    return x * vector.x + y * vector.y + z * vector.z;
}

Vector3 Vector3::Cross(Vector3& vector) {
    Vector3 result;
    result.x = y * vector.z - z * vector.y;
    result.y = z * vector.x - x * vector.z;
    result.z = x * vector.y - y * vector.x;
    return result;
}

float Vector3::Distance(Vector3& vector) {
    float dx = x - vector.x;
    float dy = y - vector.y;
    float dz = z - vector.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

float Vector3::Angle(Vector3& vector) {
    float dot = Dot(vector);
    float mag1 = Magnitude();
    float mag2 = vector.Magnitude();
    return acos(dot / (mag1 * mag2));
}

Vector3 Vector3::Clone() {
    Vector3 clone;
    clone.x = x;
    clone.y = y;
    clone.z = z;
    return clone;
}

Vector3 Vector3::zero() {
    return Vector3();
}

Vector3 Vector3::one() {
    Vector3 vector;
    vector.x = 1;
    vector.y = 1;
    vector.z = 1;
    return vector;
}

Vector3 Vector3::up() {
    Vector3 vector;
    vector.x = 0;
    vector.y = 1;
    vector.z = 0;
    return vector;
}

Vector3 Vector3::down() {
    Vector3 vector;
    vector.x = 0;
    vector.y = -1;
    vector.z = 0;
    return vector;
}

Vector3 Vector3::left() {
    Vector3 vector;
    vector.x = -1;
    vector.y = 0;
    vector.z = 0;
    return vector;
}

Vector3 Vector3::right() {
    Vector3 vector;
    vector.x = 1;
    vector.y = 0;
    vector.z = 0;
    return vector;
}

Vector3 Vector3::forward() {
    Vector3 vector;
    vector.x = 0;
    vector.y = 0;
    vector.z = 1;
    return vector;
}

Vector3 Vector3::back() {
    Vector3 vector;
    vector.x = 0;
    vector.y = 0;
    vector.z = -1;
    return vector;
}

#include "Vector2.hpp"
#include <math.h>

Vector2::Vector2() : x(0), y(0) {}

Vector2::~Vector2() {}

void Vector2::Normalize() {
    float length = sqrt(x * x + y * y);
    x /= length;
    y /= length;
}

void Vector2::Normalize(Vector2& vector) {
    float length = sqrt(vector.x * vector.x + vector.y * vector.y);
    vector.x /= length;
    vector.y /= length;
}

Vector2 Vector2::Normalized() {
    Vector2 normalized = *this;
    Normalize(normalized);
    return normalized;
}

float Vector2::Magnitude() {
    return sqrt(x * x + y * y);
}

void Vector2::Add(Vector2& vector) {
    x += vector.x;
    y += vector.y;
}

void Vector2::Subtract(Vector2& vector) {
    x -= vector.x;
    y -= vector.y;
}

void Vector2::Multiply(Vector2& vector) {
    x *= vector.x;
    y *= vector.y;
}

void Vector2::Divide(Vector2& vector) {
    x /= vector.x;
    y /= vector.y;
}

void Vector2::Scale(float scalar) {
    x *= scalar;
    y *= scalar;
}

float Vector2::Dot(Vector2& vector) {
    return x * vector.x + y * vector.y;
}

Vector2 Vector2::Cross(Vector2& vector) {
    Vector2 result;
    result.x = y * vector.x;
    result.y = x * vector.y;
    return result;
}

float Vector2::Distance(Vector2& vector) {
    float dx = x - vector.x;
    float dy = y - vector.y;
    return sqrt(dx * dx + dy * dy);
}

float Vector2::Angle(Vector2& vector) {
    float dot = Dot(vector);
    float mag1 = Magnitude();
    float mag2 = vector.Magnitude();
    return acos(dot / (mag1 * mag2));
}

Vector2 Vector2::Clone() {
    Vector2 clone;
    clone.x = x;
    clone.y = y;
    return clone;
}

Vector2 Vector2::zero() {
    return Vector2();
}

Vector2 Vector2::one() {
    Vector2 vector;
    vector.x = 1;
    vector.y = 1;
    return vector;
}

Vector2 Vector2::up() {
    Vector2 vector;
    vector.x = 0;
    vector.y = 1;
    return vector;
}

Vector2 Vector2::down() {
    Vector2 vector;
    vector.x = 0;
    vector.y = -1;
    return vector;
}

Vector2 Vector2::left() {
    Vector2 vector;
    vector.x = -1;
    vector.y = 0;
    return vector;
}

Vector2 Vector2::right() {
    Vector2 vector;
    vector.x = 1;
    vector.y = 0;
    return vector;
}

#include "Mathf.hpp"

float Mathf::Clamp(float value, float min, float max) {
    return std::min(std::max(value, min), max);
}

float Mathf::Lerp(float a, float b, float t) {
    t = Clamp(t, 0.0f, 1.0f);
    return a + (b - a) * t;
}

float Mathf::LerpUnclamped(float a, float b, float t) {
    return a + (b - a) * t;
}

float Mathf::LerpAngle(float a, float b, float t) {
    float delta = std::fmod(b - a + 180.0f, 360.0f) - 180.0f;
    return a + delta * Clamp(t, 0.0f, 1.0f);
}

float Mathf::LerpUnclampedAngle(float a, float b, float t) {
    float delta = std::fmod(b - a + 180.0f, 360.0f) - 180.0f;
    return a + delta * t;
}

float Mathf::Floor(float value) {
    return std::floor(value);
}

float Mathf::Ceil(float value) {
    return std::ceil(value);
}

float Mathf::Round(float value) {
    return std::round(value);
}

float Mathf::Abs(float value) {
    return std::abs(value);
}

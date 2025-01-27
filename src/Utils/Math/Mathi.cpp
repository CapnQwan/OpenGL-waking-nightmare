#include "Mathi.hpp"

int Mathf::Clamp(int value, int min, int max) {
    return std::min(std::max(value, min), max);
}

int Mathf::Lerp(int a, int b, int t) {
    t = Clamp(t, 0, 1);
    return a + (b - a) * t;
}

int Mathf::LerpUnclamped(int a, int b, int t) {
    return a + (b - a) * t;
}

int Mathf::LerpAngle(int a, int b, int t) {
    int delta = ((b - a + 180) % 360) - 180;
    return a + delta * Clamp(t, 0, 1);
}

int Mathf::LerpUnclampedAngle(int a, int b, int t) {
    int delta = ((b - a + 180) % 360) - 180;
    return a + delta * t;
}

int Mathf::Floor(int value) {
    return value;
}

int Mathf::Ceil(int value) {
    return value;
}

int Mathf::Round(int value) {
    return value;
}

int Mathf::Abs(int value) {
    return std::abs(value);
}

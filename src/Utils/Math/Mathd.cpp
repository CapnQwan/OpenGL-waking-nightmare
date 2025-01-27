#include "Mathd.hpp"

double Mathd::Clamp(double value, double min, double max) {
    return std::min(std::max(value, min), max);
}

double Mathd::Lerp(double a, double b, double t) {
    t = Clamp(t, 0.0, 1.0);
    return a + (b - a) * t;
}

double Mathd::LerpUnclamped(double a, double b, double t) {
    return a + (b - a) * t;
}

double Mathd::LerpAngle(double a, double b, double t) {
    double delta = std::fmod(b - a + 180.0, 360.0) - 180.0;
    return a + delta * Clamp(t, 0.0, 1.0);
}

double Mathd::LerpUnclampedAngle(double a, double b, double t) {
    double delta = std::fmod(b - a + 180.0, 360.0) - 180.0;
    return a + delta * t;
}

double Mathd::Floor(double value) {
    return std::floor(value);
}

double Mathd::Ceil(double value) {
    return std::ceil(value);
}

double Mathd::Round(double value) {
    return std::round(value);
}

double Mathd::Abs(double value) {
    return std::abs(value);
}

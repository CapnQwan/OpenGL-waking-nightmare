#ifndef MATHF_H
#define MATHF_H

#include <algorithm>
#include <cmath>

namespace Mathf {
    float Clamp(float value, float min, float max);
    float Lerp(float a, float b, float t);
    float LerpUnclamped(float a, float b, float t);
    float LerpAngle(float a, float b, float t);
    float LerpUnclampedAngle(float a, float b, float t);
    float Floor(float value);
    float Ceil(float value);
    float Round(float value);
    float Abs(float value);
}

#endif // MATHF_H

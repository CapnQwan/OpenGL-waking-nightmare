#ifndef MATHI_H
#define MATHI_H

#include <algorithm>
#include <cmath>

namespace Mathf {
    int Clamp(int value, int min, int max);
    int Lerp(int a, int b, int t);
    int LerpUnclamped(int a, int b, int t);
    int LerpAngle(int a, int b, int t);
    int LerpUnclampedAngle(int a, int b, int t);
    int Floor(int value);
    int Ceil(int value);
    int Round(int value);
    int Abs(int value);
}

#endif // MATHI_H

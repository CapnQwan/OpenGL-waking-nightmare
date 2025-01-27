#ifndef MATHD_H
#define MATHD_H

#include <algorithm>
#include <cmath>

namespace Mathd {
    double Clamp(double value, double min, double max);
    double Lerp(double a, double b, double t);
    double LerpUnclamped(double a, double b, double t);
    double LerpAngle(double a, double b, double t);
    double LerpUnclampedAngle(double a, double b, double t);
    double Floor(double value);
    double Ceil(double value);
    double Round(double value);
    double Abs(double value);
}

#endif // MATHD_H

#ifndef CURVES_UTIL_H
#define CURVES_UTIL_H

#include <cmath>

namespace cadex {
    constexpr auto eps = 1e-6f;
    constexpr bool approximately_equal(float a, float b) {
        return std::abs(a - b) <= eps;
    }
}

#endif // CURVES_UTIL_H

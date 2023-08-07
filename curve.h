#ifndef CURVES_CURVE_H
#define CURVES_CURVE_H

#include <array>

namespace cadex {
    class curve {
    public:
        virtual ~curve() = default;
        virtual std::array<float, 3> point(float t) const = 0;
    };
}

#endif // CURVES_CURVE_H

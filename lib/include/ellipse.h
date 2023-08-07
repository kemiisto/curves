#ifndef CURVES_ELLIPSE_H
#define CURVES_ELLIPSE_H

#include "curve.h"

namespace cadex {
    class ellipse final : public curve {
    public:
        explicit ellipse(float a, float b);
        std::array<float, 3> point(float t) const override;
        std::array<float, 3> first_derivative(float t) const override;
    private:
        float m_a;
        float m_b;
    };
}

#endif // CURVES_ELLIPSE_H

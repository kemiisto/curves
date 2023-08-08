#ifndef CURVES_ELLIPSE_H
#define CURVES_ELLIPSE_H

#include "curve.h"

namespace cadex {
    class ellipse final : public curve {
    public:
        explicit ellipse(float radius_x, float radius_y);
        std::array<float, 3> point(float t) const override;
        std::array<float, 3> first_derivative(float t) const override;
    private:
        float m_radius_x;
        float m_radius_y;
    };
}

#endif // CURVES_ELLIPSE_H

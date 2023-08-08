#ifndef CURVES_CIRCLE_H
#define CURVES_CIRCLE_H

#include "curve.h"

namespace cadex {
    class circle final : public curve {
    public:
        explicit circle(float radius);
        std::array<float, 3> point(float t) const override;
        std::array<float, 3> first_derivative(float t) const override;
        float radius() const;
    private:
        float m_radius;
    };
}

#endif // CURVES_CIRCLE_H

#ifndef CURVES_CIRCLE_H
#define CURVES_CIRCLE_H

#include "curve.h"

namespace cadex {
    class circle final : public curve {
    public:
        explicit circle(float r);
        std::array<float, 3> point(float t) const override;
        std::array<float, 3> first_derivative(float t) const override;
        const float radius() const;
    private:
        float m_r;
    };
}

#endif // CURVES_CIRCLE_H

#ifndef CURVES_HELIX_H
#define CURVES_HELIX_H

#include "curve.h"

namespace cadex {
    class helix final : public curve {
    public:
        explicit helix(float radius, float step);
        std::array<float, 3> point(float t) const override;
        std::array<float, 3> first_derivative(float t) const override;
    private:
        float m_radius;
        float m_step;
    };
}

#endif // CURVES_HELIX_H

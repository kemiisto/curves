#ifndef CURVES_HELIX_H
#define CURVES_HELIX_H

#include "curve.h"

namespace cadex {
    class helix final : public curve {
    public:
        explicit helix(float r, float s);
        std::array<float, 3> point(float t) const override;
        std::array<float, 3> first_derivative(float t) const override;
    private:
        float m_r;
        float m_s;
    };
}

#endif // CURVES_HELIX_H

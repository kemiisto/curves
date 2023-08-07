#ifndef CURVES_ELLIPSE_H
#define CURVES_ELLIPSE_H

#include "curve.h"

namespace cadex {
    class ellipse final : public curve {
    public:
        explicit ellipse(float a, float b)
            : m_a{a <= 0 ? throw std::invalid_argument{"a should be positive"} : a}
            , m_b{b <= 0 ? throw std::invalid_argument{"b should be positive"} : b} {}
        // x = a cos(t), y = b sin(t), z = 0
        std::array<float, 3> point(float t) const override {
            return {m_a * std::cos(t), m_b * std::sin(t), 0.0f};
        }
    private:
        float m_a;
        float m_b;
    };
}

#endif // CURVES_ELLIPSE_H

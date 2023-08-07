#ifndef CURVES_HELIX_H
#define CURVES_HELIX_H

#include "curve.h"
#include <exception>

namespace cadex {
    class helix final : public curve {
    public:
        explicit helix(float r, float s)
            : m_r{r <= 0 ? throw std::invalid_argument{"r should be positive"} : r}
            , m_s{s <= 0 ? throw std::invalid_argument{"s should be positive"} : s} {}
        // x = r cos(t), y = r sin(t), z = s t
        std::array<float, 3> point(float t) const override {
            return {m_r * std::cos(t), m_r * std::sin(t), m_s * t};
        }
        // x = -r sin(t), y = r cos(t), z = s
        std::array<float, 3> first_derivative(float t) const override {
            return {-m_r * std::sin(t), m_r * std::cos(t), m_s};
        }
    private:
        float m_r;
        float m_s;
    };
}

#endif // CURVES_HELIX_H

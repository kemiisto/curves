#ifndef CURVES_CIRCLE_H
#define CURVES_CIRCLE_H

#include "curve.h"
#include <exception>

namespace cadex {
    class circle final : public curve {
    public:
        explicit circle(float r)
            : m_r{r <= 0 ? throw std::invalid_argument{"r should be positive"} : r} {}
        // x = r cos(t), y = r sin(t), z = 0
        std::array<float, 3> point(float t) const override {
            return {m_r * std::cos(t), m_r * std::sin(t), 0.0f};
        }
    private:
        float m_r;
    };
}

#endif // CURVES_CIRCLE_H

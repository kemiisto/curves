#include "circle.h"
#include <cmath>
#include <stdexcept>

cadex::circle::circle(float r)
    : m_r{r <= 0 ? throw std::invalid_argument{"r should be positive"} : r} {}

// x = r cos(t), y = r sin(t), z = 0
std::array<float, 3> cadex::circle::point(float t) const {
    return {m_r * std::cos(t), m_r * std::sin(t), 0.0f};
}

// x = -r sin(t), y = r cos(t), z = 0
std::array<float, 3> cadex::circle::first_derivative(float t) const {
    return {-m_r * std::sin(t), m_r * std::cos(t), 0.0f};
}

const float cadex::circle::radius() const {
    return m_r;
}

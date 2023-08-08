#include "circle.h"
#include <cmath>
#include <stdexcept>

cadex::circle::circle(float radius)
    : m_radius{radius <= 0 ? throw std::invalid_argument{"radius should be positive"} : radius} {}

// x = r cos(t), y = r sin(t), z = 0
std::array<float, 3> cadex::circle::point(float t) const {
    return {m_radius * std::cos(t), m_radius * std::sin(t), 0.0f};
}

// x = -r sin(t), y = r cos(t), z = 0
std::array<float, 3> cadex::circle::first_derivative(float t) const {
    return {-m_radius * std::sin(t), m_radius * std::cos(t), 0.0f};
}

float cadex::circle::radius() const {
    return m_radius;
}

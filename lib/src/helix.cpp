#include "helix.h"
#include <cmath>
#include <stdexcept>

cadex::helix::helix(float radius, float step)
    : m_radius{radius <= 0 ? throw std::invalid_argument{"radius should be positive"} : radius}
    , m_step{step <= 0 ? throw std::invalid_argument{"step should be positive"} : step} {}

// x = r cos(t), y = r sin(t), z = s t
std::array<float, 3> cadex::helix::point(float t) const {
    return {m_radius * std::cos(t), m_radius * std::sin(t), m_step * t};
}
// x = -r sin(t), y = r cos(t), z = s
std::array<float, 3> cadex::helix::first_derivative(float t) const {
    return {-m_radius * std::sin(t), m_radius * std::cos(t), m_step};
}

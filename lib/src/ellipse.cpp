#include "ellipse.h"
#include <cmath>
#include <stdexcept>

cadex::ellipse::ellipse(float radius_x, float radius_y)
    : m_radius_x{radius_x <= 0 ? throw std::invalid_argument{"radius_x should be positive"} : radius_x}
    , m_radius_y{radius_y <= 0 ? throw std::invalid_argument{"radius_y should be positive"} : radius_y} {}

// x = rx cos(t), y = ry sin(t), z = 0
std::array<float, 3> cadex::ellipse::point(float t) const {
    return {m_radius_x * std::cos(t), m_radius_y * std::sin(t), 0.0f};
}

// x = -rx sin(t), y = ry cos(t), z = 0
std::array<float, 3> cadex::ellipse::first_derivative(float t) const {
    return {-m_radius_x * std::sin(t), m_radius_y * std::cos(t), 0.0f};
}

#include "ellipse.h"
#include <exception>

cadex::ellipse::ellipse(float a, float b)
    : m_a{a <= 0 ? throw std::invalid_argument{"a should be positive"} : a}
    , m_b{b <= 0 ? throw std::invalid_argument{"b should be positive"} : b} {}

// x = a cos(t), y = b sin(t), z = 0
std::array<float, 3> cadex::ellipse::point(float t) const {
    return {m_a * std::cos(t), m_b * std::sin(t), 0.0f};
}

// x = -a sin(t), y = b cos(t), z = 0
std::array<float, 3> cadex::ellipse::first_derivative(float t) const {
    return {-m_a * std::sin(t), m_b * std::cos(t), 0.0f};
}
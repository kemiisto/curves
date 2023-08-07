#include "helix.h"
#include <exception>

cadex::helix::helix(float r, float s)
    : m_r{r <= 0 ? throw std::invalid_argument{"r should be positive"} : r}
    , m_s{s <= 0 ? throw std::invalid_argument{"s should be positive"} : s} {}

// x = r cos(t), y = r sin(t), z = s t
std::array<float, 3> cadex::helix::point(float t) const {
    return {m_r * std::cos(t), m_r * std::sin(t), m_s * t};
}
// x = -r sin(t), y = r cos(t), z = s
std::array<float, 3> cadex::helix::first_derivative(float t) const {
    return {-m_r * std::sin(t), m_r * std::cos(t), m_s};
}

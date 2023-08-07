#include "circle.h"
#include "ellipse.h"
#include "helix.h"

#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_all.hpp>

#include <numbers>

using Catch::Matchers::RangeEquals;

constexpr auto eps = 1e-6f;
constexpr bool approximately_equal(float a, float b) {
    return std::abs(a - b) <= eps;
}

TEST_CASE("circle construction") {
    SECTION("works when radius is positive") {
        REQUIRE_NOTHROW(cadex::circle{1.0f});
    }
    SECTION("throws when radius is negative ") {
        REQUIRE_THROWS(cadex::circle{-1.0f});
    }
}

TEST_CASE("ellipse construction") {
    SECTION("works when both radii are positive") {
        REQUIRE_NOTHROW(cadex::ellipse{1.0f, 2.0f});
    }
    SECTION("throws when the first radius is negative") {
        REQUIRE_THROWS(cadex::ellipse{-1.0f, 2.0f});
    }
    SECTION("throws when the second radius is negative") {
        REQUIRE_THROWS(cadex::ellipse{1.0f, -2.0f});
    }
    SECTION("throws when both radii are negative") {
        REQUIRE_THROWS(cadex::ellipse{-1.0f, -2.0f});
    }
}

TEST_CASE("helix construction") {
    SECTION("works when both radius and step are positive") {
        REQUIRE_NOTHROW(cadex::helix{1.0f, 2.0f});
    }
    SECTION("throws when radius is negative") {
        REQUIRE_THROWS(cadex::helix{-1.0f, 2.0f});
    }
    SECTION("throws when step is negative") {
        REQUIRE_THROWS(cadex::ellipse{1.0f, -2.0f});
    }
    SECTION("throws when both radius and step are negative") {
        REQUIRE_THROWS(cadex::ellipse{-1.0f, -2.0f});
    }
}

TEST_CASE("point() works for a unit circle") {
    const auto c = cadex::circle{1.0f};
    CHECK_THAT(
        c.point(std::numbers::pi_v<float> / 2),
        RangeEquals(std::array{0.0f, 1.0f, 0.0f}, approximately_equal)
    );
    CHECK_THAT(
        c.point(std::numbers::pi_v<float>),
        RangeEquals(std::array{-1.0f, 0.0f, 0.0f}, approximately_equal)
    );
    CHECK_THAT(
        c.point(3 * std::numbers::pi_v<float> / 2),
        RangeEquals(std::array{0.0f, -1.0f, 0.0f}, approximately_equal)
    );
    CHECK_THAT(
        c.point(2 * std::numbers::pi_v<float>),
        RangeEquals(std::array{1.0f, 0.0f, 0.0f}, approximately_equal)
    );
}

TEST_CASE("first_derivative() works for a unit circle") {
    const auto c = cadex::circle{1.0f};
    CHECK_THAT(
        c.first_derivative(std::numbers::pi_v<float> / 2),
        RangeEquals(std::array{-1.0f, 0.0f, 0.0f}, approximately_equal)
    );
    CHECK_THAT(
        c.first_derivative(std::numbers::pi_v<float>),
        RangeEquals(std::array{0.0f, -1.0f, 0.0f}, approximately_equal)
    );
    CHECK_THAT(
        c.first_derivative(3 * std::numbers::pi_v<float> / 2),
        RangeEquals(std::array{1.0f, 0.0f, 0.0f}, approximately_equal)
    );
    CHECK_THAT(
        c.first_derivative(2 * std::numbers::pi_v<float>),
        RangeEquals(std::array{0.0f, 1.0f, 0.0f}, approximately_equal)
    );
}

TEST_CASE("point() works for an ellipse that is a unit circle") {
    const auto e = cadex::ellipse{1.0f, 1.0f};
    CHECK_THAT(
        e.point(std::numbers::pi_v<float> / 2),
        RangeEquals(std::array{0.0f, 1.0f, 0.0f}, approximately_equal)
    );
    CHECK_THAT(
        e.point(std::numbers::pi_v<float>),
        RangeEquals(std::array{-1.0f, 0.0f, 0.0f}, approximately_equal)
    );
    CHECK_THAT(
        e.point(3 * std::numbers::pi_v<float> / 2),
        RangeEquals(std::array{0.0f, -1.0f, 0.0f}, approximately_equal)
    );
    CHECK_THAT(
        e.point(2 * std::numbers::pi_v<float>),
        RangeEquals(std::array{1.0f, 0.0f, 0.0f}, approximately_equal)
    );
}

TEST_CASE("first_derivative() works for an ellipse that is a unit circle") {
    const auto e = cadex::ellipse{1.0f, 1.0f};
    CHECK_THAT(
        e.first_derivative(std::numbers::pi_v<float> / 2),
        RangeEquals(std::array{-1.0f, 0.0f, 0.0f}, approximately_equal)
    );
    CHECK_THAT(
        e.first_derivative(std::numbers::pi_v<float>),
        RangeEquals(std::array{0.0f, -1.0f, 0.0f}, approximately_equal)
    );
    CHECK_THAT(
        e.first_derivative(3 * std::numbers::pi_v<float> / 2),
        RangeEquals(std::array{1.0f, 0.0f, 0.0f}, approximately_equal)
    );
    CHECK_THAT(
        e.first_derivative(2 * std::numbers::pi_v<float>),
        RangeEquals(std::array{0.0f, 1.0f, 0.0f}, approximately_equal)
    );
}

TEST_CASE("point() works for an ellipse") {
    const auto e = cadex::ellipse{1.0f, 2.0f};
    CHECK_THAT(
        e.point(std::numbers::pi_v<float> / 2),
        RangeEquals(std::array{0.0f, 2.0f, 0.0f}, approximately_equal)
    );
    CHECK_THAT(
        e.point(std::numbers::pi_v<float>),
        RangeEquals(std::array{-1.0f, 0.0f, 0.0f}, approximately_equal)
    );
    CHECK_THAT(
        e.point(3 * std::numbers::pi_v<float> / 2),
        RangeEquals(std::array{0.0f, -2.0f, 0.0f}, approximately_equal)
    );
    CHECK_THAT(
        e.point(2 * std::numbers::pi_v<float>),
        RangeEquals(std::array{1.0f, 0.0f, 0.0f}, approximately_equal)
    );
}

TEST_CASE("first_derivative() works for an ellipse") {
    const auto e = cadex::ellipse{1.0f, 2.0f};
    CHECK_THAT(
        e.first_derivative(std::numbers::pi_v<float> / 2),
        RangeEquals(std::array{-1.0f, 0.0f, 0.0f}, approximately_equal)
    );
    CHECK_THAT(
        e.first_derivative(std::numbers::pi_v<float>),
        RangeEquals(std::array{0.0f, -2.0f, 0.0f}, approximately_equal)
    );
    CHECK_THAT(
        e.first_derivative(3 * std::numbers::pi_v<float> / 2),
        RangeEquals(std::array{1.0f, 0.0f, 0.0f}, approximately_equal)
    );
    CHECK_THAT(
        e.first_derivative(2 * std::numbers::pi_v<float>),
        RangeEquals(std::array{0.0f, 2.0f, 0.0f}, approximately_equal)
    );
}

TEST_CASE("point() works for a unit helix with step=2") {
    const auto h = cadex::helix{1.0f, 2.0f};
    CHECK_THAT(
        h.point(std::numbers::pi_v<float> / 2),
        RangeEquals(std::array{0.0f, 1.0f, std::numbers::pi_v<float>}, approximately_equal)
    );
    CHECK_THAT(
        h.point(std::numbers::pi_v<float>),
        RangeEquals(std::array{-1.0f, 0.0f, 2 * std::numbers::pi_v<float>}, approximately_equal)
    );
    CHECK_THAT(
        h.point(3 * std::numbers::pi_v<float> / 2),
        RangeEquals(std::array{0.0f, -1.0f, 3 * std::numbers::pi_v<float>}, approximately_equal)
    );
    CHECK_THAT(
        h.point(2 * std::numbers::pi_v<float>),
        RangeEquals(std::array{1.0f, 0.0f, 4 * std::numbers::pi_v<float>}, approximately_equal)
    );
}

TEST_CASE("first_derivative() works for a unit helix with step=2") {
    const auto h = cadex::helix{1.0f, 2.0f};
    CHECK_THAT(
        h.first_derivative(std::numbers::pi_v<float> / 2),
        RangeEquals(std::array{-1.0f, 0.0f, 2.0f}, approximately_equal)
    );
    CHECK_THAT(
        h.first_derivative(std::numbers::pi_v<float>),
        RangeEquals(std::array{0.0f, -1.0f, 2.0f}, approximately_equal)
    );
    CHECK_THAT(
        h.first_derivative(3 * std::numbers::pi_v<float> / 2),
        RangeEquals(std::array{1.0f, 0.0f, 2.0f}, approximately_equal)
    );
    CHECK_THAT(
        h.first_derivative(2 * std::numbers::pi_v<float>),
        RangeEquals(std::array{0.0f, 1.0f, 2.0f}, approximately_equal)
    );
}

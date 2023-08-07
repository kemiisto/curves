#include "circle.h"
#include "ellipse.h"
#include "util.h"

#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_all.hpp>

#include <numbers>

using Catch::Matchers::RangeEquals;

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

TEST_CASE("point() works for a unit circle") {
    const auto c = cadex::circle{1.0f};
    CHECK_THAT(
        c.point(std::numbers::pi_v<float> / 2),
        RangeEquals(std::array{0.0f, 1.0f, 0.0f}, cadex::approximately_equal)
    );
    CHECK_THAT(
        c.point(std::numbers::pi_v<float>),
        RangeEquals(std::array{-1.0f, 0.0f, 0.0f}, cadex::approximately_equal)
    );
    CHECK_THAT(
        c.point(3 * std::numbers::pi_v<float> / 2),
        RangeEquals(std::array{0.0f, -1.0f, 0.0f}, cadex::approximately_equal)
    );
    CHECK_THAT(
        c.point(2 * std::numbers::pi_v<float>),
        RangeEquals(std::array{1.0f, 0.0f, 0.0f}, cadex::approximately_equal)
    );
}

TEST_CASE("point() works for an ellipse that is a unit circle") {
    const auto e = cadex::ellipse{1.0f, 1.0f};
    CHECK_THAT(
        e.point(std::numbers::pi_v<float> / 2),
        RangeEquals(std::array{0.0f, 1.0f, 0.0f}, cadex::approximately_equal)
    );
    CHECK_THAT(
        e.point(std::numbers::pi_v<float>),
        RangeEquals(std::array{-1.0f, 0.0f, 0.0f}, cadex::approximately_equal)
    );
    CHECK_THAT(
        e.point(3 * std::numbers::pi_v<float> / 2),
        RangeEquals(std::array{0.0f, -1.0f, 0.0f}, cadex::approximately_equal)
    );
    CHECK_THAT(
        e.point(2 * std::numbers::pi_v<float>),
        RangeEquals(std::array{1.0f, 0.0f, 0.0f}, cadex::approximately_equal)
    );
}

TEST_CASE("point() works for an ellipse") {
    const auto e = cadex::ellipse{1.0f, 2.0f};
    CHECK_THAT(
        e.point(std::numbers::pi_v<float> / 2),
        RangeEquals(std::array{0.0f, 2.0f, 0.0f}, cadex::approximately_equal)
    );
    CHECK_THAT(
        e.point(std::numbers::pi_v<float>),
        RangeEquals(std::array{-1.0f, 0.0f, 0.0f}, cadex::approximately_equal)
    );
    CHECK_THAT(
        e.point(3 * std::numbers::pi_v<float> / 2),
        RangeEquals(std::array{0.0f, -2.0f, 0.0f}, cadex::approximately_equal)
    );
    CHECK_THAT(
        e.point(2 * std::numbers::pi_v<float>),
        RangeEquals(std::array{1.0f, 0.0f, 0.0f}, cadex::approximately_equal)
    );
}
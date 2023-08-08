#include "curve.h"
#include "circle.h"
#include "ellipse.h"
#include "helix.h"

#define CATCH_CONFIG_RUNNER
#include <catch2/catch_session.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

#include <algorithm>
#include <format>
#include <execution>
#include <iostream>
#include <memory>
#include <numbers>
#include <random>
#include <vector>

auto generate_curves(size_t n) {
    auto seed = std::random_device{};
    auto gen = std::mt19937{seed()};
    auto curve_type_dist = std::uniform_int_distribution{0, 2};
    auto float_dist = std::uniform_real_distribution{0.1f, 5.0f};

    auto curves = std::vector<std::unique_ptr<cadex::curve>>{};
    curves.reserve(n);

    for (size_t i = 0; i < n; ++i) {
        const auto curve_type = curve_type_dist(gen);
        const auto radius = float_dist(gen);
        switch (curve_type) {
            case 0: {
                curves.push_back(std::make_unique<cadex::circle>(radius));
                break;
            }
            case 1: {
                const auto second_radius = float_dist(gen);
                curves.push_back(std::make_unique<cadex::ellipse>(radius, second_radius));
                break;
            }
            case 2: {
                const auto step = float_dist(gen);
                curves.push_back(std::make_unique<cadex::helix>(radius, step));
            }
        }
    }

    return curves;
}

auto get_circles(std::vector<std::unique_ptr<cadex::curve>>& curves) {
    auto circles = std::vector<cadex::circle*>{};
    for (const auto& curve : curves) {
        auto circle = dynamic_cast<cadex::circle*>(curve.get());
        if (circle) circles.push_back(circle);
    }
    return circles;
}

int main(int argc, char* const argv[]) {
    constexpr auto n = 20;
    constexpr auto pi_4 = std::numbers::pi_v<float> / 4;

    auto curves = generate_curves(n);
    std::cout << "Curves coordinates and derivatives at PI/4:" << '\n';
    for (const auto& curve : curves) {
        const auto& point = curve->point(pi_4);
        const auto& derivative = curve->first_derivative(pi_4);
        std::cout
            << std::format("({:10.5f}, {:10.5f}, {:10.5f})\t", point[0], point[1], point[2])
            << std::format("({:10.5f}, {:10.5f}, {:10.5f})", derivative[0], derivative[1], derivative[2])
            << '\n';
    }

    auto circles = get_circles(curves);
    std::ranges::sort(circles, {}, &cadex::circle::radius);

    std::cout << "\nCircles radii (in ascending order):" << '\n';
    for (const auto& circle : circles) {
        std::cout << std::format("{:10.5f}", circle->radius()) << '\n';
    }

    auto total_radii = std::transform_reduce(
        std::execution::par_unseq,
        circles.begin(), circles.end(), 0.0f,
        [](float a, float b) {
            return a + b;
        },
        [](cadex::circle* c) {
            return c->radius();
        }
    );
    std::cout << std::format("\nTotal circles radii: {:10.5f}", total_radii) << '\n';

    std::cout << "Benchmarking parallel transform_reduce()...\n";
    return Catch::Session().run(argc, argv);
}

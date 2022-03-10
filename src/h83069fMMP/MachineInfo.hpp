#pragma once

#include <2022EOMMP>

namespace eommpsys {
namespace utils {

constexpr float WHEEL_DIAMETER = 50.7f;
constexpr float TRED = 80.0f;

constexpr float WHEEL_CIRCUMFERENCE = WHEEL_DIAMETER * PI<float>;
constexpr float DISTANCE_PER_DEGREE = WHEEL_CIRCUMFERENCE / 360.0f;
// constexpr float DISTANCE_PER_PULSE = WHEEL_CIRCUMFERENCE / 200.0f;
// full phase
constexpr float DISTANCE_PER_PULSE =
    WHEEL_CIRCUMFERENCE / 400.0f;  // half phase

constexpr float TURNING_CIRCUMFERENCE = TRED * PI<float>;

}  // namespace utils
}  // namespace eommpsys

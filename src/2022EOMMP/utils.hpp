#pragma once

#include "utils/delay.hpp"
#include "utils/timerManager.hpp"

namespace eommpsys {
namespace utils {

constexpr auto M_PI = 3.14159265358979323846;

template <typename T>
constexpr T degreeToRadian(T degree) {
  return degree * M_PI / 180.0;
}

}  // namespace utils
}  // namespace eommpsys

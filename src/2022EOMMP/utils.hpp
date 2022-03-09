#pragma once

#include "utils/delay.hpp"
#include "utils/timerManager.hpp"

namespace eommpsys {
namespace utils {

template <typename T>
constexpr T PI = 3.14159265358979323846;

constexpr float WHEEL_DIAMETER = 50.7f;
constexpr float TRED = 80.0f;
constexpr float WHEEL_CIRCUMFERENCE = WHEEL_DIAMETER * PI<float>;
constexpr float DISTANCE_PER_DEGREE = WHEEL_CIRCUMFERENCE / 360.0f;
// constexpr float DISTANCE_PER_PULSE = WHEEL_CIRCUMFERENCE / 200.0f;
// full phase
constexpr float DISTANCE_PER_PULSE =
    WHEEL_CIRCUMFERENCE / 400.0f;  // half phase

constexpr float TURNING_CIRCUMFERENCE = TRED * PI<float>;

template <typename T, typename U>
constexpr T DegreeToRadian(U degree) {
  return degree * PI<T> / static_cast<T>(180);
}

constexpr float CalcDiameter(uint16_t radius, uint16_t degree = 360) {
  return DegreeToRadian<float>(degree) * static_cast<float>(radius);
}
constexpr float calcCurveTime(uint16_t degree,
                              uint16_t radius,
                              uint16_t speed) {
  return (DegreeToRadian<float>(degree) * radius) / static_cast<float>(speed);
}

constexpr auto CalcClockFreq(clockSource_t source) {
  uint32_t val = 0;
  switch (source) {
    case Prescaler_1:
      val = CPU_CLOCK;
      break;
    case Prescaler_2:
      val = CPU_CLOCK / 2.0;
      break;
    case Prescaler_4:
      val = CPU_CLOCK / 4.0;
      break;
    case Prescaler_8:
      val = CPU_CLOCK / 8.0;
      break;
    case Prescaler_64:
      val = CPU_CLOCK / 64.0;
      break;
    case Prescaler_8192:
      val = CPU_CLOCK / 8192.0;
      break;
    default:
      val = 0.0f;
      break;
  }
  return val;
}

}  // namespace utils
}  // namespace eommpsys

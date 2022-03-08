#pragma once

#include <2022EOMMP>

#include "Motor.hpp"
#include "Types.hpp"

namespace eommpsys {

class H8MouseMovementController {
 private:
  H8Motor *motor_left, *motor_right;

  static constexpr float WHEEL_DIAMETER = 50.7f;
  static constexpr float TRED = 80.0f;
  static constexpr float CIRCUMFERENCE = WHEEL_DIAMETER * utils::PI<float>;

  static constexpr float DISTANCE_PER_DEGREE = CIRCUMFERENCE / 360.0f;
  static constexpr float DISTANCE_PER_PULSE = CIRCUMFERENCE / 200.0f;

  static constexpr float TURNING_CIRCUMFERENCE = TRED * utils::PI<float>;

  static constexpr float CalcDiameter(uint16_t radius, uint16_t degree = 360) {
    return utils::DegreeToRadian<float>(degree) * static_cast<float>(radius);
  }
  static constexpr float calcCurveTime(uint16_t radius, uint16_t speed) {
    return (utils::DegreeToRadian<float>(90) * radius) /
           static_cast<float>(speed);
  }

 public:
  H8MouseMovementController() : motor_left(nullptr), motor_right(nullptr) {}
  ~H8MouseMovementController() {
    motor_left = nullptr;
    motor_right = nullptr;
  }

  inline void LinkMotor(H8Motor& left, H8Motor& right) {
    motor_left = &left;
    motor_right = &right;
  }

  inline void UnlinkMotor() {
    motor_left = nullptr;
    motor_right = nullptr;
  }

  /**
   * @brief
   *
   * @param distance mm
   * @param speed mm/s
   * @return Result
   */
  Result Advance(uint16_t distance, uint16_t speed);
  Result Spinturn(uint16_t speed, Direction direction);
};

}  // namespace eommpsys

#pragma once

#include <2022EOMMP>

#include "Motor.hpp"
#include "Types.hpp"
// #include "WallDetector.hpp"

namespace eommpsys {
class H8Mouse {
 private:
  H8Motor *motorLeft, *motorRight;
  // WallDetector* wd;

  static constexpr auto WHEEL_DIAMETER = 50.7;
  static constexpr auto TRED = 80.0;

  static constexpr auto WHEEL_CIRCLE = WHEEL_DIAMETER * utils::M_PI;
  static constexpr float DISTANCE_PER_DEGREE = WHEEL_CIRCLE / 360.0f;
  static constexpr float DISTANCE_PER_PULSE = WHEEL_CIRCLE / 200.0f;
  static constexpr float CONSTANT = WHEEL_CIRCLE / 360.0f;

  static constexpr float TURNING_DIAMETER = TRED * utils::M_PI;

  static constexpr float calcDiameter(uint16_t radius, uint16_t degree = 360) {
    return utils::degreeToRadian(degree) * radius;
  }
  static constexpr float calcCurveTime(uint16_t radius, uint16_t speed) {
    return radius * utils::M_PI * 0.25f / speed;
  }

 public:
  uint16_t distanceCell, distanceTireToTire;

 public:
  /**
   * @brief Mouse のコンストラクタ。
   *
   */
  H8Mouse() : motorLeft(nullptr), motorRight(nullptr), distanceCell(0) {
    // motorLeft = nullptr;
    // motorRight = nullptr;
    // wd = nullptr;
    // distanceCell = 0;
  }
  /**
   * @brief Mouse のデコンストラクタ。
   *
   */
  ~H8Mouse() {
    motorLeft = nullptr;
    motorRight = nullptr;
    // wd = nullptr;
  }

  /**
   * @brief モータインスタンスとリンクします。
   *
   *  @param left 左モータインスタンス。
   *  @param right 右モータインスタンス。
   */
  inline void LinkMotor(H8Motor& left, H8Motor& right) {
    motorLeft = &left;
    motorRight = &right;
  }
  /**
   * @brief ウエスタンデジタルインスタンスとリンクします。
   *
   * @param wd ウエスタンデジタルインスタンス。
   */
  // void LinkWallDetector(WallDetector& wd) { this->wd = &wd; }
  /**
   * @brief モータインスタンスとのリンクを解除します。
   *
   */
  inline void UnlinkMotor() {
    motorLeft = nullptr;
    motorRight = nullptr;
  }
  /**
   * @brief ウエスタンデジタルインスタンスとのリンクを解除します。
   *
   */
  // inline void UnlinkWallDetector() { wd = nullptr; }

  template <uint16_t distance, uint16_t speed>
  Result Advance(void);

  Result Advance(uint16_t distance, uint16_t speed);

  Result Spinturn(uint16_t speed, Direction direction);

  // template <uint16_t speed, uint16_t radius>
  // constexpr Result Curve(Direction direction) {
  //   const float curve_time = calcCurveTime(radius, speed);
  //   const float inner_radius = calcDiameter(radius - 40);
  //   const float outer_radius = calcDiameter(radius + 40);
  //   const float inner_speed = inner_radius / curve_time;
  //   const float outer_speed = outer_radius / curve_time;
  //   ui::MonLed led;

  //   Result left_stats, right_stats;

  //   if (motorLeft == nullptr || motorRight == nullptr) {
  //     return Result::NOT_LINKED_MOTOR;
  //   } else if (!(direction != Direction::WEST) ||
  //              !(direction != Direction::EAST)) {
  //     return Result::INVALID_DIRECTION;
  //   }

  //   led.left(true);

  //   switch (direction) {
  //     case Direction::EAST:
  //       left_stats =
  //           motorLeft->Setup(outer_radius / DISTANCE_PER_DEGREE,
  //           outer_speed);
  //       right_stats =
  //           motorRight->Setup(inner_radius / DISTANCE_PER_DEGREE,
  //           inner_speed);
  //       break;
  //     case Direction::WEST:
  //       left_stats =
  //           motorLeft->Setup(inner_radius / DISTANCE_PER_DEGREE,
  //           inner_speed);
  //       right_stats =
  //           motorRight->Setup(outer_radius / DISTANCE_PER_DEGREE,
  //           outer_speed);
  //       break;
  //     default:
  //       return Result::UNKNOWN_ERROR;
  //   }

  //   led.center(true);

  //   if (left_stats != Result::SUCCESS || right_stats != Result::SUCCESS) {
  //     return Result::UNKNOWN_ERROR;
  //   }

  //   motorLeft->Enable(true);
  //   motorLeft->Start();
  //   motorRight->Start();

  //   led.right(true);

  //   while (motorLeft->CheckEnd() != Result::HALTED &&
  //          motorRight->CheckEnd() != Result::HALTED) {
  //   }

  //   motorLeft->Enable(false);

  //   return Result::SUCCESS;
  // }
};
}  // namespace eommpsys

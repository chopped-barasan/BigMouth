#pragma once

#include <array>

#include "MachineInfo.hpp"
#include "Motor.hpp"
#include "Types.hpp"

namespace eommpsys {

class H8Mouse {
 private:
  H8Motor *motor_left, *motor_right;

  static constexpr uint16_t MAX_SPEED = 600;
  static constexpr std::array<float, 14> ACCELE_TABLE = {
      0.0714286f, 0.142857f, 0.214286f, 0.285714f, 0.357143f, 0.428571f, 0.5f,
      0.571429f,  0.642857f, 0.714286f, 0.785714f, 0.857143f, 0.928571f, 1.0f};
  // static constexpr std::array<float, 12> ACCELE_TABLE = {
  //     0.0170371f, 0.0669873f, 0.146447f, 0.25f,     0.37059f,  0.5f,
  //     0.62941f,   0.75f,      0.853553f, 0.933013f, 0.982963f, 1.0f};
  static constexpr uint16_t ACCELE_DELTA_TIME = 19;  // msec

  enum MouseState {
    STOPED,        // 停車中
    STOP_REQURED,  // 停車要求
    CRUISE,        // 巡航中
    TURN,          // 転回中
    ACCELERATE,    // 加速中
    DECELERATE,    // 減速中
    WAITING,       // 待機中
    REACHED        // 目的地に到達
  } mouse_state;

 public:
  H8Mouse() : motor_left(nullptr), motor_right(nullptr), mouse_state(WAITING) {}
  ~H8Mouse() {
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

  inline void Neutral(void) { motor_left->Enable(false); }

  Result AutoPilot(void);
  Result Advance(uint16_t distance, uint16_t speed);
  Result Spinturn(uint16_t speed, Direction direction);
  void Stop(void);
  Result ChangeSpeed(uint16_t speed);

  template <uint16_t left_distance,
            uint16_t left_speed,
            uint16_t right_distance,
            uint16_t right_speed>
  Result Move(const bool left_reverse, const bool right_reverse) {
    constexpr uint16_t left_rotate = left_distance / utils::DISTANCE_PER_DEGREE;
    constexpr uint16_t right_rotate =
        right_distance / utils::DISTANCE_PER_DEGREE;
    constexpr uint16_t left_angver = left_speed / utils::DISTANCE_PER_DEGREE;
    constexpr uint16_t right_angver = right_speed / utils::DISTANCE_PER_DEGREE;
    Result left_stats, right_stats;

    if (nullptr == motor_left || nullptr == motor_right) {
      return Result::NOT_LINKED_MOTOR;
    }

    left_stats = motor_left->Setup(left_rotate, left_angver, left_reverse);
    right_stats = motor_right->Setup(right_rotate, right_angver, right_reverse);

    if (left_stats != Result::SUCCESS) {
      return left_stats;
    } else if (right_stats != Result::SUCCESS) {
      return right_stats;
    }

    motor_left->Enable(true);
    motor_left->Start();
    motor_right->Start();

    return Result::SUCCESS;
  }

  /**
   * @brief
   *
   * @param distance mm
   * @param speed mm/s
   * @return Result
   */
  template <uint16_t distance, uint16_t speed>
  Result Advance(void) {
    uint16_t acc_count = 0;
    Result stats;

    stats =
        Move<distance, static_cast<uint16_t>(speed * ACCELE_TABLE[0]), distance,
             static_cast<uint16_t>(speed * ACCELE_TABLE[0])>(false, false);

    if (stats != Result::SUCCESS) {
      return stats;
    }

    while (motor_left->CheckEnd() == Result::RUNNING &&
           motor_right->CheckEnd() == Result::RUNNING) {
      uint16_t table_index = 0;

      Time::Delay(ACCELE_DELTA_TIME);

      acc_count++;

      if (acc_count < ACCELE_TABLE.size()) {
        table_index = acc_count;
      } else if (acc_count >= (ACCELE_TABLE.size() * 2) - 1) {
        // nothing to do
      } else {
        table_index = (ACCELE_TABLE.size() * 2) - 1 - acc_count;
      }

      stats = ChangeSpeed(speed * ACCELE_TABLE[table_index]);
    }

    return Result::SUCCESS;
  }

  template <uint16_t speed>
  Result ChangeSpeed() {
    constexpr uint16_t wheel_speed = speed / utils::DISTANCE_PER_DEGREE;

    if (nullptr == motor_left || nullptr == motor_right) {
      return Result::NOT_LINKED_MOTOR;
    }

    motor_left->ChangeSpeed(wheel_speed);
    motor_right->ChangeSpeed(wheel_speed);

    return Result::SUCCESS;
  }
};

}  // namespace eommpsys

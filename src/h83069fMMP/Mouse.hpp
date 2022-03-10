#pragma once

#include <array>

#include "MachineInfo.hpp"
#include "Motor.hpp"
#include "Types.hpp"

namespace eommpsys {

class H8Mouse {
 private:
  H8Motor *motor_left, *motor_right;

  static constexpr uint16_t MAX_SPEED = 650;
  // static constexpr std::array<float, 20> ACCELE_TABLE = {
  //     0.05f, 0.1f, 0.15,  0.2f, 0.25f, 0.3f, 0.35f, 0.4f, 0.45f, 0.5f,
  //     0.55f, 0.6f, 0.65f, 0.7f, 0.75f, 0.8f, 0.85f, 0.9f, 0.95f, 1.0f};
  static constexpr std::array<float, 20> ACCELE_TABLE = {0.006155829702f,
                                                         0.02447174185f,
                                                         0.05449673791f,
                                                         0.09549150281f,
                                                         0.1464466094f,
                                                         0.2061073739f,
                                                         0.2730047501f,
                                                         0.3454915028f,
                                                         0.4217827675f,
                                                         0.5f,
                                                         0.5782172325f,
                                                         0.6545084972f,
                                                         0.7269952499f,
                                                         0.7938926261f,
                                                         0.8535533906f,
                                                         0.9045084972f,
                                                         0.9455032621f,
                                                         0.9755282581f,
                                                         0.9938441703f,
                                                         1.0f

  };
  static constexpr uint16_t ACCELE_DELTA_TIME = 25;  // msec

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

  Result AutoPilot(void);
  Result Advance(uint16_t distance, uint16_t speed);
  Result Spinturn(uint16_t speed, Direction direction);
  void Stop(void);
  Result ChangeSpeed(uint16_t speed);

  /**
   * @brief
   *
   * @param distance mm
   * @param speed mm/s
   * @return Result
   */
  template <uint16_t distance, uint16_t speed>
  Result Advance(void) {
    constexpr uint16_t movement_range = distance / utils::DISTANCE_PER_DEGREE;
    constexpr uint16_t wheel_speed =
        speed / utils::DISTANCE_PER_DEGREE;  // degree per sec
    Result left_stats, right_stats;

    if (nullptr == motor_left || nullptr == motor_right) {
      return Result::NOT_LINKED_MOTOR;
    }

    left_stats = motor_left->Setup(movement_range, wheel_speed);
    right_stats = motor_right->Setup(movement_range, wheel_speed);

    if (left_stats != Result::SUCCESS || right_stats != Result::SUCCESS) {
      return Result::UNKNOWN_ERROR;
    }

    motor_left->Enable(true);
    motor_left->Start();
    motor_right->Start();

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

    if (left_stats != Result::SUCCESS || right_stats != Result::SUCCESS) {
      return Result::UNKNOWN_ERROR;
    }

    motor_left->Enable(true);
    motor_left->Start();
    motor_right->Start();

    while (motor_left->CheckEnd() != Result::HALTED &&
           motor_right->CheckEnd() != Result::HALTED)
      ;

    motor_left->Enable(false);

    return Result::SUCCESS;
  }
};

}  // namespace eommpsys

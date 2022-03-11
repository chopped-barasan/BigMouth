#pragma once

#include <array>

#include "Info.hpp"
#include "Motor.hpp"
#include "Types.hpp"

namespace eommpsys {

class H8MovementController {
 private:
  H8Motor *motor_left, *motor_right;

 public:
  MouseState mouse_state;

  H8MovementController()
      : motor_left(nullptr), motor_right(nullptr), mouse_state(WAITING) {}
  ~H8MovementController() {
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

  // Result AutoPilot(void);
  Result Forward(uint16_t distance, uint16_t speed);
  Result Spinturn(uint16_t speed, Direction direction);
  Result ChangeSpeed(uint16_t speed);
  MouseState GetMouseState(void) { return mouse_state; }
  Result BackOnTrack(float resolution, Direction dir);
  Result Brake(void) {
    if (motor_left->Brake() == RUNNING || motor_right->Brake() == RUNNING) {
      return RUNNING;
    } else {
      return HALTED;
    }
  }
  inline bool OnCenter(void) {
    return motor_left->OnCenter() && motor_right->OnCenter();
  }
  void PutDownCenterFlag(void) {
    motor_left->PutDownCenterFlag();
    motor_right->PutDownCenterFlag();
  }
  Result CheckEnd(void) {
    if (motor_left->CheckEnd() == HALTED && motor_right->CheckEnd() == HALTED) {
      return HALTED;
    } else {
      return RUNNING;
    }
  }
  void Stop(void) { motor_left->Enable(false); }

  /**
   * @brief
   *
   * @param distance mm
   * @param speed mm/s
   * @return Result
   */
  template <uint16_t distance, uint16_t speed>
  Result Advance(void) {
    constexpr uint32_t movement_range = distance / utils::DISTANCE_PER_DEGREE;
    constexpr uint32_t wheel_speed =
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

  /**
   * @brief
   *
   * @param distance mm
   * @param speed mm/s
   * @return Result
   */
  template <uint16_t distance, uint16_t speed>
  Result Backward(void) {
    constexpr uint16_t movement_range = distance / utils::DISTANCE_PER_DEGREE;
    constexpr uint16_t wheel_speed =
        speed / utils::DISTANCE_PER_DEGREE;  // degree per sec
    Result left_stats, right_stats;

    if (nullptr == motor_left || nullptr == motor_right) {
      return Result::NOT_LINKED_MOTOR;
    }

    left_stats = motor_left->Setup(movement_range, wheel_speed, true);
    right_stats = motor_right->Setup(movement_range, wheel_speed, true);

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

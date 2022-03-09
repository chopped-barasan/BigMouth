#include "Mouse.hpp"

using namespace eommpsys;

Result H8Mouse::Advance(uint16_t distance, uint16_t speed) {
  const uint16_t movement_range = distance / utils::DISTANCE_PER_DEGREE;
  const uint16_t wheel_speed =
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

  while (motor_left->CheckEnd() != Result::HALTED &&
         motor_right->CheckEnd() != Result::HALTED)
    ;

  motor_left->Enable(false);

  return Result::SUCCESS;
}

Result H8Mouse::Spinturn(uint16_t speed, Direction direction) {
  // constexpr uint16_t movement_range =
  //     static_cast<uint16_t>(utils::TURNING_CIRCUMFERENCE /
  //                           utils::DISTANCE_PER_DEGREE) /
  //     4;
  constexpr uint16_t movement_range =
      (utils::DegreeToRadian<float>(90) * (utils::TRED / 2.0f)) /
      utils::DISTANCE_PER_DEGREE;
  uint16_t wheel_speed = speed / utils::DISTANCE_PER_DEGREE;
  Result left_stats, right_stats;

  if (motor_left == nullptr || motor_right == nullptr) {
    return Result::NOT_LINKED_MOTOR;
  } else if (direction < Direction::SOUTH || direction > Direction::EAST) {
    return Result::INVALID_DIRECTION;
  }

  switch (direction) {
    case Direction::NORTH:
      break;
    case Direction::SOUTH:
      left_stats = motor_left->Setup((movement_range * 2), wheel_speed, true);
      right_stats = motor_right->Setup((movement_range * 2), wheel_speed);
      break;
    case Direction::WEST:
      left_stats = motor_left->Setup(movement_range, wheel_speed, true);
      right_stats = motor_right->Setup(movement_range, wheel_speed);
      break;
    case Direction::EAST:
      left_stats = motor_left->Setup(movement_range, wheel_speed);
      right_stats = motor_right->Setup(movement_range, wheel_speed, true);
      break;
    default:
      return Result::UNKNOWN_ERROR;
  }

  if (left_stats != Result::SUCCESS || right_stats != Result::SUCCESS) {
    return Result::UNKNOWN_ERROR;
  }

  motor_left->Enable(true);
  motor_left->Start();
  motor_right->Start();

  while (motor_left->CheckEnd() != Result::HALTED &&
         motor_right->CheckEnd() != Result::HALTED) {
  }

  motor_left->Enable(false);

  return Result::SUCCESS;
}

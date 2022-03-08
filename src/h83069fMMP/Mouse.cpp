#include "Mouse.hpp"

using namespace eommpsys;

// VSCodeでのエラー回避のためにあえて冗長に「Pikachu::Result」と記述しています。それ以外の意味はありません。

Result H8Mouse::Advance(uint16_t distance, uint16_t speed) {
  uint16_t movement_range = distance / DISTANCE_PER_DEGREE;
  uint16_t wheel_speed = speed / CONSTANT;
  Result left_stats, right_stats;

  if (motorLeft == nullptr || motorRight == nullptr) {
    return Result::NOT_LINKED_MOTOR;
  }

  left_stats = motorLeft->Setup(movement_range, wheel_speed);
  right_stats = motorRight->Setup(movement_range, wheel_speed);

  if (left_stats != Result::SUCCESS || right_stats != Result::SUCCESS) {
    return Result::UNKNOWN_ERROR;
  }

  motorLeft->Enable(false);
  motorLeft->Start();
  motorRight->Start();

  while (motorLeft->CheckEnd() != Result::HALTED &&
         motorRight->CheckEnd() != Result::HALTED) {
  }

  motorLeft->Enable(false);

  return Result::SUCCESS;
}

Result H8Mouse::Spinturn(uint16_t speed, Direction direction) {
  constexpr uint16_t movement_range =
      static_cast<uint16_t>(TURNING_DIAMETER / DISTANCE_PER_DEGREE) / 4;
  uint16_t wheel_speed = speed / CONSTANT;
  Result left_stats, right_stats;

  if (motorLeft == nullptr || motorRight == nullptr) {
    return Result::NOT_LINKED_MOTOR;
  } else if (direction < Direction::SOUTH || direction > Direction::EAST) {
    return Result::INVALID_DIRECTION;
  }

  switch (direction) {
    case Direction::NORTH:
      break;
    case Direction::SOUTH:
      left_stats = motorLeft->Setup((movement_range * 2), wheel_speed, true);
      right_stats = motorRight->Setup((movement_range * 2), wheel_speed);
      break;
    case Direction::WEST:
      left_stats = motorLeft->Setup(movement_range, wheel_speed, true);
      right_stats = motorRight->Setup(movement_range, wheel_speed);
      break;
    case Direction::EAST:
      left_stats = motorLeft->Setup(movement_range, wheel_speed);
      right_stats = motorRight->Setup(movement_range, wheel_speed, true);
      break;
    default:
      return Result::UNKNOWN_ERROR;
  }

  if (left_stats != Result::SUCCESS || right_stats != Result::SUCCESS) {
    return Result::UNKNOWN_ERROR;
  }

  motorLeft->Enable(true);
  motorLeft->Start();
  motorRight->Start();

  while (motorLeft->CheckEnd() != Result::HALTED &&
         motorRight->CheckEnd() != Result::HALTED) {
  }

  motorLeft->Enable(false);

  return Result::SUCCESS;
}

// template <uint16_t speed, uint16_t radius>
// constexpr Result H8Mouse::Curve(Direction direction) {
//   const float curve_time = calcCurveTime(radius, speed);
//   const float inner_radius = calcDiameter(radius - 40);
//   const float outer_radius = calcDiameter(radius + 40);
//   const float inner_speed = calcDiameter(radius - 40) / curve_time;
//   const float outer_speed = calcDiameter(radius + 40) / curve_time;

//   Result left_stats, right_stats;

//   if (motorLeft == nullptr || motorRight == nullptr) {
//     return Result::NOT_LINKED_MOTOR;
//   } else if (!(direction != Direction::WEST) ||
//              !(direction != Direction::EAST)) {
//     return Result::INVALID_DIRECTION;
//   }

//   switch (direction) {
//     case Direction::EAST:
//       left_stats =
//           motorLeft->Setup(outer_radius / DISTANCE_PER_DEGREE, outer_speed);
//       right_stats =
//           motorLeft->Setup(inner_radius / DISTANCE_PER_DEGREE, inner_speed);
//       break;
//     case Direction::WEST:
//       left_stats =
//           motorLeft->Setup(inner_radius / DISTANCE_PER_DEGREE, inner_speed);
//       right_stats =
//           motorLeft->Setup(outer_radius / DISTANCE_PER_DEGREE, outer_speed);
//       break;
//   }

//   if (left_stats != Result::SUCCESS || right_stats != Result::SUCCESS) {
//     return Result::UNKNOWN_ERROR;
//   }

//   motorLeft->Enable(true);
//   motorLeft->Start();
//   motorRight->Start();

//   while (motorLeft->CheckEnd() != Result::HALTED &&
//          motorRight->CheckEnd() != Result::HALTED) {
//   }

//   motorLeft->Enable(false);

//   return Result::SUCCESS;
// }

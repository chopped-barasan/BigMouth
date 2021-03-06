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

Result H8Mouse::ChangeSpeed(uint16_t speed) {
  uint16_t wheel_speed;

  if (nullptr == motor_left || nullptr == motor_right) {
    return Result::NOT_LINKED_MOTOR;
  }

  if (speed != 0) {
    wheel_speed = speed / utils::DISTANCE_PER_DEGREE;
  } else {
    motor_left->Enable(false);
    return Result::SUCCESS;
  }

  motor_left->ChangeSpeed(wheel_speed);
  motor_right->ChangeSpeed(wheel_speed);

  return Result::SUCCESS;
}

inline void H8Mouse::Stop(void) {
  motor_left->Enable(false);
}

Result H8Mouse::AutoPilot(void) {
  volatile uint16_t acc_count = 0, temp_count = 0;
  uint64_t acc_start_time = 0;

  if (nullptr == motor_left || nullptr == motor_right) {
    return Result::NOT_LINKED_MOTOR;
  } else if (mouse_state != MouseState::WAITING) {
    return Result::RUNNING;
  }

  while (true) {
    switch (mouse_state) {
      // ????????????(????????????)
      // ??????????????????????????????????????????
      // ACCELERATE?????????
      case WAITING:
        Advance<180, static_cast<uint16_t>(MAX_SPEED * ACCELE_TABLE[0])>();
        acc_start_time = Time::GetCurrentTime();
        mouse_state = ACCELERATE;
        break;
      // ????????????
      // ?????????????????????????????????????????????
      // CRUISE?????????
      case ACCELERATE:
        if (Time::GetCurrentTime() - acc_start_time > ACCELE_DELTA_TIME) {
          acc_start_time = Time::GetCurrentTime();
          ChangeSpeed(MAX_SPEED * ACCELE_TABLE[++acc_count]);
        }
        if (acc_count >= ACCELE_TABLE.size()) {
          acc_count = 0;
          mouse_state = CRUISE;
        }
        break;
      case CRUISE:
        if (motor_right->CheckEnd() == Result::HALTED &&
            motor_left->CheckEnd() == Result::HALTED) {
          Stop();
          Advance<180, MAX_SPEED>();
          temp_count++;
        } else if (temp_count >= 4) {
          mouse_state = STOP_REQURED;
        }
        break;
      case STOP_REQURED:
        acc_count = ACCELE_TABLE.size();
        acc_start_time = Time::GetCurrentTime();
        mouse_state = DECELERATE;
        break;
      case DECELERATE:
        if (Time::GetCurrentTime() - acc_start_time > ACCELE_DELTA_TIME) {
          acc_start_time = Time::GetCurrentTime();
          ChangeSpeed(MAX_SPEED * ACCELE_TABLE[--acc_count]);
        }
        if (acc_count <= 0) {
          acc_count = 0;
          mouse_state = STOPED;
        }
        break;
      case STOPED:
        if (motor_right->CheckEnd() == Result::HALTED &&
            motor_left->CheckEnd() == Result::HALTED) {
          ChangeSpeed(0);
          mouse_state = REACHED;
        }
        break;
      case TURN:
        break;
      case REACHED:
        mouse_state = WAITING;
        motor_left->Enable(false);
        return Result::SUCCESS;
      default:
        return Result::UNKNOWN_ERROR;
    }
  }
}

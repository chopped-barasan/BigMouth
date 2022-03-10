#include "Mouse.hpp"


using namespace Pikachu;


// VSCodeでのエラー回避のためにあえて冗長に「Pikachu::Result」と記述しています。それ以外の意味はありません。


Pikachu::Result Mouse::Advance(uint16_t speed)
{
  WallStatus ws;


  if (motorLeft == nullptr) {
    return Result::NOT_LINKED_MOTOR;
  }
  else if (wd == nullptr) {
    return Result::NOT_LINKED_WALLDETECTOR;
  }


  motorLeft->Start(distanceCell, speed);
  motorRight->Start(distanceCell, speed);

  while (motorLeft->CheckEnd() == Result::HALTED && motorRight->CheckEnd() == Result::HALTED) {
    wd->GetStatus(ws);

    // 書いている途中。
    if (ws.leftLeft) {
      motorLeft->ChangeSpeed(0);
      motorRight->ChangeSpeed(0);
    }
  }

  return Result::SUCCESS;
}

Pikachu::Result Mouse::Spinturn(uint16_t speed, Direction direction)
{
  if (motorLeft == nullptr) {
    return Result::NOT_LINKED_MOTOR;
  }
  else if (wd == nullptr) {
    return Result::NOT_LINKED_WALLDETECTOR;
  }
  else if (direction < Direction::SOUTH || direction > Direction::EAST) {
    return Result::INVALID_DIRECTION;
  }


  switch (direction) {
    case Direction::NORTH:
      break;

    case Direction::SOUTH:
      motorLeft->Start(distanceTireToTire, speed, true);
      motorRight->Start(distanceTireToTire, speed);
      break;

    case Direction::WEST:
      motorLeft->Start(distanceTireToTire, speed, true);
      motorRight->Start(distanceTireToTire, speed);
      break;

    case Direction::EAST:
      motorLeft->Start(distanceTireToTire, speed);
      motorRight->Start(distanceTireToTire, speed, true);
      break;

    default:
      return UNKNOWN_ERROR;
  }

  while (motorLeft->CheckEnd() == Result::RUNNING || motorRight->CheckEnd() == Result::RUNNING)
    ;


  return Result::SUCCESS;
}

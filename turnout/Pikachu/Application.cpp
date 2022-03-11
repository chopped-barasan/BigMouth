#include "Application.hpp"


using namespace Pikachu;


Pikachu::Result Application::Run(ExecutionMode mode, Motor &motorLeft, Motor &motorRight, WallDetector &wd)
{
  Map        map      = Map();
  Mouse      mouse    = Mouse();
  Cell       cell     = {};
  Location   location = {};
  WallStatus ws       = {};

  uint8_t
    route[256]  = {},
    branch[256] = {};
  uint8_t
    routeIndex  = 0,
    branchIndex = 0;


  if (running) {
    Result::RUNNING;
  }


  running = true;

  map.ChangeLocation(location);
  map.ChangeDirection(Direction::NORTH);
  mouse.LinkMotor(motorLeft, motorRight);
  mouse.LinkWallDetector(wd);
  while (true) {
    switch (mode) {
      case ExecutionMode::OPTIMAL:
        break;

      case ExecutionMode::MAPPING_PRIORITY_STRAIGHT:
        while (true) {
          cell = CELL_INITIALIZATION;

          wd.GetStatus(ws);
          if ((ws.leftLeft || ws.leftCenter || ws.leftRight) == false) {
            cell.west = true;
          }
          if ((ws.rightLeft || ws.rightCenter || ws.rightRight) == false) {
            cell.east = true;
          }
          if ((ws.frontLeft || ws.frontRight) == false) {
            cell.east = true;
          }
          map.WriteCell(cell);

          if (cell.north &&) {
            map.IncrementCell();
            mouse.Advance(SPEED);
          }
        }
        break;

      case ExecutionMode::MAPPING_PRIORITY_CURVE:
        break;
    }
  }


  return Result::SUCCESS;
}

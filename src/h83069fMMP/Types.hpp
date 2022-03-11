#pragma once

#include <cinttypes>

namespace eommpsys {
typedef enum {
  SUCCESS = 0U,
  UNKNOWN_ERROR,
  NOT_INITIALIZED,
  INVALID_ARGUMENTS,
  INVALID_DIRECTION,
  INVALID_SPEED,
  INVALID_AXIS,
  INVALID_DEGREES,
  INVALID_BASIS_LOCATION,
  INVALID_BASIS_DIRECTION,
  CONTRADICTED,
  OUT_OF_RANGE_LOCATION,
  NOT_LINKED_MOTOR,
  NOT_LINKED_WALLDETECTOR,
  RUNNING,
  HALTED,
  ABORTING
} Result;

typedef enum {
  NONE = 0U,
  NORTH,
  SOUTH,
  WEST,
  EAST,
  NORTHWEST,
  NORTHEAST,
  SOUTHWEST,
  SOUTHEAST
} Direction;

typedef enum {
  OPTIMAL,
  MAPPING_PRIORITY_STRAIGHT,
  MAPPING_PRIORITY_CURVE
} ExecutionMode;

typedef enum { LEFT = 0U, RIGHT } Axis;

typedef struct {
  uint8_t x, y;
} Location;

typedef enum {
  START_REQUIRED,  // 発車要求 //
  STOPED,          // 停車中 //
  STOP_REQURED,    // 停車要求 //
  CRUISE,          // 巡航中 //
  TURN_REQUIRED,   // 転回要求 //
  TURNING,         // 転回中 //
  KETSU,           // ケツアタック //
  ACCELERATE,      // 加速中 //
  DECELERATE,      // 減速中
  WAITING,         // 待機中　//
  REACHED          // 目的地に到達　//
} MouseState;

typedef union {
  bitAccess_t<_BYTE, 0> left;
  bitAccess_t<_BYTE, 1> center;
  bitAccess_t<_BYTE, 2> right;
} SideDegiSens_t;

union un_degisens {
  _BYTE BYTE;
  bitAccess_t<_BYTE, 0> R3;
  bitAccess_t<_BYTE, 1> R2;
  bitAccess_t<_BYTE, 2> R1;
  bitAccess_t<_BYTE, 3> F1;
  bitAccess_t<_BYTE, 4> F2;
  bitAccess_t<_BYTE, 5> L1;
  bitAccess_t<_BYTE, 6> L2;
  bitAccess_t<_BYTE, 7> L3;
};

typedef union {
  bitAccess_t<_BYTE, 0> center;
  bitAccess_t<_BYTE, 1> back;
  bitAccess_t<_BYTE, 2> right;
  bitAccess_t<_BYTE, 3> left;
} Wall_t;

using DegiSens_t = un_degisens;

}  // namespace eommpsys

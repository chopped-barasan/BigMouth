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
}  // namespace eommpsys

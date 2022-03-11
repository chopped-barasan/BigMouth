#pragma once

#include <2022EOMMP>
#include <array>

namespace eommpsys {
namespace utils {

constexpr float WHEEL_DIAMETER = 50.7f;
constexpr float TRED = 80.0f;
constexpr uint16_t MAX_SPEED = 575;

constexpr uint16_t GRID_SIZE = 180;
constexpr uint16_t ACCELERATE_DISTANCE = 120;

// static constexpr std::array<float, 20> ACCELE_TABLE = {
//     0.05f, 0.1f, 0.15,  0.2f, 0.25f, 0.3f, 0.35f, 0.4f, 0.45f, 0.5f,
//     0.55f, 0.6f, 0.65f, 0.7f, 0.75f, 0.8f, 0.85f, 0.9f, 0.95f, 1.0f};
static constexpr std::array<float, 32> ACCELE_TABLE = {
    0.00240764f, 0.00960736f, 0.0215298f, 0.0380602f, 0.0590394f, 0.0842652f,
    0.113495f,   0.146447f,   0.182803f,  0.222215f,  0.264302f,  0.308658f,
    0.354858f,   0.402455f,   0.450991f,  0.5f,       0.549009f,  0.597545f,
    0.645142f,   0.691342f,   0.735698f,  0.777785f,  0.817197f,  0.853553f,
    0.886505f,   0.915735f,   0.940961f,  0.96194f,   0.97847f,   0.990393f,
    0.997592f,   1.0f};
static constexpr uint16_t ACCELE_DELTA_TIME = ACCELERATE_DISTANCE * 2 /
                                              static_cast<double>(MAX_SPEED) *
                                              1000 / ACCELE_TABLE.size();

constexpr float WHEEL_CIRCUMFERENCE = WHEEL_DIAMETER * PI<float>;
constexpr float DISTANCE_PER_DEGREE = WHEEL_CIRCUMFERENCE / 360.0f;
// constexpr float DISTANCE_PER_PULSE = WHEEL_CIRCUMFERENCE / 200.0f;
// full phase
constexpr float DISTANCE_PER_PULSE =
    WHEEL_CIRCUMFERENCE / 400.0f;  // half phase

constexpr float TURNING_CIRCUMFERENCE = TRED * PI<float>;

}  // namespace utils
}  // namespace eommpsys

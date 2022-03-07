#include "Motor.hpp"

namespace eommpsys {

TimerManager::TimerBase<uint16_t>* H8MotorR::timer = nullptr;
bool H8MotorR::running = false;
bool H8MotorR::signal_abort = false;

volatile uint16_t H8MotorR::target_val = 0;
volatile uint16_t H8MotorR::pulse_count = 0;
float H8MotorR::constant = 0.0f;

void H8MotorR::intrHandlerA(void) {
  motor.step = 1;
}

void H8MotorR::intrHandlerB(void) {
  motor.step = 0;

  if (++pulse_count >= target_val) {
    timer->stop();
    End();
  }
}

void H8MotorR::Start_(uint16_t distance, uint16_t speed, bool reverse) {
  uint16_t compare_val = calcCompareVal(speed);
  target_val = static_cast<uint16_t>(distance / MovingDistanceByPulse());
  pulse_count = 0;

  timer->setGeneralA(compare_val / 2);
  timer->setGeneralB(compare_val);

  timer->start();
}

void H8MotorR::Abort_(void) {
  timer->stop();
  enableMotor(false);
}

void H8MotorR::ChangeSpeed_(uint16_t speed) {
  uint16_t compare_val = calcCompareVal(speed);

  timer->setGeneralA(compare_val / 2);
  timer->setGeneralB(compare_val);
}

void H8MotorR::init(TimerManager::TimerBase<uint16_t>& tim) {
  timer = &tim;
  H8Reg::PADDR |= 0b01010011;

  running = false;
  signal_abort = false;
  constant = calcBaseHz(timer->getClockSource()) * MovingDistanceByPulse();

  timer->setHandlerA(H8MotorR::intrHandlerA, 0);
  timer->setHandlerB(H8MotorR::intrHandlerB, 0);
}

// TimerManager::TimerBase<uint16_t>* h8MotorR::timer = nullptr;

// void h8MotorR::init(TimerManager::TimerBase<uint16_t>& tim) {
//   timer = &tim;
//   H8Reg::PADDR |= 01010011;
//   motor.phase = 1;

//   timer->setHandlerA(motorHandlerA, 2083);
//   timer->setHandlerB(motorHandlerB, 4167);
//   timer->start();
// }

// void h8MotorR::motorHandlerA(void) {
//   motor.step = 1;
// }

// void h8MotorR::motorHandlerB(void) {
//   motor.step = 0;
// }

}  // namespace eommpsys

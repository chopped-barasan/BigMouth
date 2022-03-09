#include "Motor.hpp"

namespace eommpsys {

TimerManager::TimerBase<uint16_t>* H8MotorR::timer = nullptr;
volatile bool H8MotorR::running = false;
volatile bool H8MotorR::signal_abort = false;

volatile uint16_t H8MotorR::target_val = 0;
volatile uint16_t H8MotorR::pulse_count = 0;
uint32_t H8MotorR::base_hz = 0;

void H8MotorR::intrHandlerA(void) {
  motor.step = 1;
}

void H8MotorR::intrHandlerB(void) {
  motor.step = 0;

  if (++pulse_count >= target_val) {
    timer->pause();
    End();
  }
}

Result H8MotorR::Setup_(uint16_t degree, uint16_t speed, bool reverse) {
  uint16_t compare_val = CalcCompareVal(speed);

  if (timer == nullptr) {
    return Result::NOT_INITIALIZED;
  }

  // target_val = static_cast<uint16_t>(degree / MovingDistanceByPulse());
  target_val = CalcPulseFromDegree(degree);
  pulse_count = 0;

  motor.dir = reverse ? 0 : 1;

  timer->adaptGeneralA(compare_val >> 1);
  timer->adaptGeneralB(compare_val);

  timer->pause();

  return Result::SUCCESS;
}

void H8MotorR::Abort_(void) {
  timer->pause();
  Enable(false);
}

void H8MotorR::ChangeSpeed_(uint16_t speed) {
  uint16_t compare_val = CalcCompareVal(speed);

  timer->adaptGeneralA(compare_val >> 1);
  timer->adaptGeneralB(compare_val);
}

void H8MotorR::Init(TimerManager::TimerBase<uint16_t>& tim) {
  timer = &tim;
  H8Reg::PADDR |= 0b01010011;

  running = false;
  signal_abort = false;
  // constant = calcBaseHz(timer->getClockSource()) * MovingDistanceByPulse();
  base_hz = utils::CalcClockFreq(timer->getClockSource());

  // motor.phase = 0;  // full phase
  motor.phase = 1;  // half phase
  motor.enable = 1;

  timer->setHandlerA(H8MotorR::intrHandlerA, 0);
  timer->setHandlerB(H8MotorR::intrHandlerB, 0);

  timer->start();
  timer->pause();
}

/*   left side   */

TimerManager::TimerBase<uint16_t>* H8MotorL::timer = nullptr;
volatile bool H8MotorL::running = false;
volatile bool H8MotorL::signal_abort = false;

volatile uint16_t H8MotorL::target_val = 0;
volatile uint16_t H8MotorL::pulse_count = 0;
uint32_t H8MotorL::base_hz = 0;

void H8MotorL::intrHandlerA(void) {
  motor.step = 1;
}

void H8MotorL::intrHandlerB(void) {
  motor.step = 0;

  if (++pulse_count >= target_val) {
    timer->pause();
    End();
  }
}

Result H8MotorL::Setup_(uint16_t degree, uint16_t speed, bool reverse) {
  uint16_t compare_val = CalcCompareVal(speed);

  if (timer == nullptr) {
    return Result::NOT_INITIALIZED;
  }

  // target_val = static_cast<uint16_t>(degree / MovingDistanceByPulse());
  target_val = CalcPulseFromDegree(degree);
  pulse_count = 0;

  motor.dir = reverse ? 0 : 1;

  timer->adaptGeneralA(compare_val >> 1);
  timer->adaptGeneralB(compare_val);

  timer->pause();

  return Result::SUCCESS;
}

void H8MotorL::Abort_(void) {
  timer->pause();
  Enable(false);
}

void H8MotorL::ChangeSpeed_(uint16_t speed) {
  uint16_t compare_val = CalcCompareVal(speed);

  timer->adaptGeneralA(compare_val >> 1);
  timer->adaptGeneralB(compare_val);
}

void H8MotorL::Init(TimerManager::TimerBase<uint16_t>& tim) {
  timer = &tim;
  H8Reg::PADDR |= 0b10100011;

  running = false;
  signal_abort = false;
  // constant = calcBaseHz(timer->getClockSource()) * MovingDistanceByPulse();
  base_hz = utils::CalcClockFreq(timer->getClockSource());

  // motor.phase = 0;  // full phase
  motor.phase = 1;  // half phase
  motor.enable = 1;

  timer->setHandlerA(H8MotorL::intrHandlerA, 0);
  timer->setHandlerB(H8MotorL::intrHandlerB, 0);

  timer->start();
  timer->pause();
}

Result Stop(void) {
  return Result::SUCCESS;
}

}  // namespace eommpsys

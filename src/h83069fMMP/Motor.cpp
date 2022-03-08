#include "Motor.hpp"

namespace eommpsys {

TimerManager::TimerBase<uint16_t>* H8MotorR::timer = nullptr;
volatile bool H8MotorR::running = false;
volatile bool H8MotorR::signal_abort = false;

volatile uint16_t H8MotorR::target_val = 0;
volatile uint16_t H8MotorR::pulse_count = 0;
float H8MotorR::base_hz = 0.0f;

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

constexpr float H8MotorR::calcBaseHz(const clockSource_t source) {
  float val = 0.0f;
  switch (source) {
    case Prescaler_1:
      val = static_cast<float>(CPU_CLOCK);
      break;
    case Prescaler_2:
      val = static_cast<float>(CPU_CLOCK) / 2.0f;
      break;
    case Prescaler_4:
      val = static_cast<float>(CPU_CLOCK) / 4.0f;
      break;
    case Prescaler_8:
      val = static_cast<float>(CPU_CLOCK) / 8.0f;
      break;
    case Prescaler_64:
      val = static_cast<float>(CPU_CLOCK) / 64.0f;
      break;
    case Prescaler_8192:
      val = static_cast<float>(CPU_CLOCK) / 8192.0f;
      break;
    default:
      val = 0.0f;
      break;
  }
  return val;
}

void H8MotorR::Start_(uint16_t degree, uint16_t speed, bool reverse) {
  uint16_t compare_val = calcCompareVal(speed);
  // target_val = static_cast<uint16_t>(degree / MovingDistanceByPulse());
  target_val = calcPulseFromDegree(degree);
  pulse_count = 0;

  timer->setGeneralA(compare_val >> 1);
  timer->setGeneralB(compare_val);

  timer->start();
}

void H8MotorR::Abort_(void) {
  timer->stop();
  enableMotor(false);
}

void H8MotorR::ChangeSpeed_(uint16_t speed) {
  uint16_t compare_val = calcCompareVal(speed);

  timer->adaptGeneralA(compare_val >> 1);
  timer->adaptGeneralB(compare_val);
}

void H8MotorR::init(TimerManager::TimerBase<uint16_t>& tim) {
  timer = &tim;
  H8Reg::PADDR |= 0b01010011;

  running = false;
  signal_abort = false;
  // constant = calcBaseHz(timer->getClockSource()) * MovingDistanceByPulse();
  base_hz = calcBaseHz(timer->getClockSource());

  timer->setHandlerA(H8MotorR::intrHandlerA, 0);
  timer->setHandlerB(H8MotorR::intrHandlerB, 0);
}

/*   left side   */

TimerManager::TimerBase<uint16_t>* H8MotorL::timer = nullptr;
volatile bool H8MotorL::running = false;
volatile bool H8MotorL::signal_abort = false;

volatile uint16_t H8MotorL::target_val = 0;
volatile uint16_t H8MotorL::pulse_count = 0;
float H8MotorL::base_hz = 0.0f;

void H8MotorL::intrHandlerA(void) {
  motor.step = 1;
}

void H8MotorL::intrHandlerB(void) {
  motor.step = 0;

  if (++pulse_count >= target_val) {
    timer->stop();
    End();
  }
}

constexpr float H8MotorL::calcBaseHz(const clockSource_t source) {
  float val = 0.0f;
  switch (source) {
    case Prescaler_1:
      val = static_cast<float>(CPU_CLOCK);
      break;
    case Prescaler_2:
      val = static_cast<float>(CPU_CLOCK) / 2.0f;
      break;
    case Prescaler_4:
      val = static_cast<float>(CPU_CLOCK) / 4.0f;
      break;
    case Prescaler_8:
      val = static_cast<float>(CPU_CLOCK) / 8.0f;
      break;
    case Prescaler_64:
      val = static_cast<float>(CPU_CLOCK) / 64.0f;
      break;
    case Prescaler_8192:
      val = static_cast<float>(CPU_CLOCK) / 8192.0f;
      break;
    default:
      val = 0.0f;
      break;
  }
  return val;
}

void H8MotorL::Start_(uint16_t degree, uint16_t speed, bool reverse) {
  uint16_t compare_val = calcCompareVal(speed);
  // target_val = static_cast<uint16_t>(degree / MovingDistanceByPulse());
  target_val = calcPulseFromDegree(degree);
  pulse_count = 0;

  timer->setGeneralA(compare_val >> 1);
  timer->setGeneralB(compare_val);

  timer->start();
}

void H8MotorL::Abort_(void) {
  timer->stop();
  enableMotor(false);
}

void H8MotorL::ChangeSpeed_(uint16_t speed) {
  uint16_t compare_val = calcCompareVal(speed);

  timer->adaptGeneralA(compare_val >> 1);
  timer->adaptGeneralB(compare_val);
}

void H8MotorL::init(TimerManager::TimerBase<uint16_t>& tim) {
  timer = &tim;
  H8Reg::PADDR |= 0b10100011;

  running = false;
  signal_abort = false;
  // constant = calcBaseHz(timer->getClockSource()) * MovingDistanceByPulse();
  base_hz = calcBaseHz(timer->getClockSource());

  timer->setHandlerA(H8MotorL::intrHandlerA, 0);
  timer->setHandlerB(H8MotorL::intrHandlerB, 0);
}

}  // namespace eommpsys

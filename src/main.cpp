#include <2022EOMMP>
#include <eommpsys>
#include "h83069fMMP/Motor.hpp"
#include "h83069fMMP/TimerIntrMane.hpp"

using namespace eommpsys;

int main(void) {
  DISABLE_GLOBAL_INTRRUPT();

  TimerManager::TMR23 tmr23(CompareMatchA, Raising, Prescaler_8);  // 1ms clock
  // TimerManager::TimerCH2 timer2(CompareMatchB, Raising,
  //                               Prescaler_2);  // buzzer
  TimerManager::TimerCH1 timer1(CompareMatchB, Raising, Prescaler_8);  // rmotor
  TimerManager::TimerCH0 timer0(CompareMatchB, Raising, Prescaler_8);  // lmotor

  Time::init(tmr23);

  ui::MonLed moniter_led;
  ui::MonLed::init();

  // ui::TactSwitch tact;
  // ui::TactSwitch::init();

  H8MotorR motor_r;
  H8MotorR::init(timer1);
  H8MotorL motor_l;
  H8MotorL::init(timer0);

  uint16_t speed = 0;

  moniter_led = 0b111;

  ENABLE_GLOBAL_INTRRUPT();

  while (true) {
    speed = 90;

    motor_r.enableMotor(true);
    motor_r.Start(1800, speed);
    motor_l.Start(1800, speed);
    moniter_led = 0b000;

    while (!motor_r.CheckEnd() && !motor_l.CheckEnd()) {
      Time::delay(50);
      speed += 90;
      motor_r.ChangeSpeed(speed);
      motor_l.ChangeSpeed(speed);
    }
    moniter_led = 0b111;

    motor_r.enableMotor(false);

    Time::delay(500);
  }

  return 0;
}

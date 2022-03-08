#include <2022EOMMP>
#include <eommpsys>
#include "h83069fMMP/Motor.hpp"
#include "h83069fMMP/Mouse.hpp"
#include "h83069fMMP/TimerIntrMane.hpp"

using namespace eommpsys;

int main(void) {
  DISABLE_GLOBAL_INTRRUPT();

  TimerManager::TMR23 tmr23(CompareMatchA, Raising, Prescaler_8);  // 1ms clock
  TimerManager::TimerCH2 timer2(CompareMatchB, Raising, Prescaler_2);  // buzzer
  TimerManager::TimerCH1 timer1(CompareMatchB, Raising, Prescaler_8);  // rmotor
  TimerManager::TimerCH0 timer0(CompareMatchB, Raising, Prescaler_8);  // lmotor

  ui::MonLed moniter_led;
  ui::TactSwitch tact;
  ui::CeraBuzzer buzzer;
  H8MotorR motor_r;
  H8MotorL motor_l;
  H8Mouse mouse;

  Time::init(tmr23);
  ui::MonLed::init();
  ui::TactSwitch::init();
  ui::CeraBuzzer::init(timer2);
  H8MotorR::init(timer1);
  H8MotorL::init(timer0);

  mouse.LinkMotor(motor_l, motor_r);

  moniter_led = 0b111;

  ENABLE_GLOBAL_INTRRUPT();

  while (true) {
    Result result;
    while (tact != ui::TactSwitch::ON)
      ;

    for (uint16_t i = 0; i < 3; i++) {
      buzzer.setHelz(1500);
      buzzer.start();
      Time::delay(150);
      buzzer.mute();
      Time::delay(350);
    }

    // result = mouse.Curve<180, 90>(EAST);

    result = mouse.Advance(180 * 8, 1080);

    if (result == Result::SUCCESS) {
      buzzer.setHelz(1000.0);
      for (uint16_t i = 0; i < 2; i++) {
        buzzer.start();
        Time::delay(100);
        buzzer.mute();
        Time::delay(150);
      }
    } else {
      buzzer.setHelz(440.0);
      buzzer.start();
      for (uint16_t j = 0; j < 3; j++) {
        for (uint16_t i = 440; i < 1500; i = i + 100) {
          buzzer.setHelz(i);
        }
      }
      buzzer.mute();
    }
  }

  return 0;
}

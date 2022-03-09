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

  Time::Init(tmr23);

  ui::MonLed moniter_led;
  ui::MonLed::Init();

  ui::CeraBuzzer buzzer;
  ui::CeraBuzzer::Init(timer2);

  ui::TactSwitch tact;
  ui::TactSwitch::Init();

  ui::SlideSwitch slide;
  ui::SlideSwitch::Init();

  H8MotorR motor_r;
  H8MotorR::Init(timer1);
  H8MotorL motor_l;
  H8MotorL::Init(timer0);

  H8Mouse mouse;
  mouse.LinkMotor(motor_l, motor_r);

  buzzer.setHelz(1000, 50);
  moniter_led = 0b111;

  ENABLE_GLOBAL_INTRRUPT();

  // uint16_t speed = 100;
  while (true) {
    Result result;

    while (tact != ui::TactSwitch::ON)
      ;

    for (volatile uint16_t i = 0; i < 3; i++) {
      buzzer.start();
      Time::Delay(50);
      buzzer.mute();
      Time::Delay(450);
    }

    result = mouse.AutoPilot();

    if (result == Result::SUCCESS) {
      for (volatile uint16_t i = 0; i < 2; i++) {
        buzzer.start();
        Time::Delay(50);
        buzzer.mute();
        Time::Delay(200);
      }
    } else {
      buzzer.start();
      Time::Delay(1000);
      buzzer.mute();
    }
  }

  return 0;
}

#include <2022EOMMP>
#include <eommpsys>
#include "h83069fMMP/Motor.hpp"
#include "h83069fMMP/Mouse.hpp"
#include "h83069fMMP/TimerIntrMane.hpp"

using namespace eommpsys;

int main(void) {
  DISABLE_GLOBAL_INTRRUPT();

  TimerManager::TMR23 tmr23(CompareMatchA, Raising, Prescaler_8);  // 1ms clock
  // TimerManager::TimerCH2 timer2(CompareMatchB, Raising,
  //                               Prescaler_2);  // buzzer
  TimerManager::TimerCH1 timer1(CompareMatchB, Raising, Prescaler_8);  // rmotor
  TimerManager::TimerCH0 timer0(CompareMatchB, Raising, Prescaler_8);  // lmotor

  Time::Init(tmr23);

  ui::MonLed moniter_led;
  ui::MonLed::Init();

  ui::TactSwitch tact;
  ui::TactSwitch::Init();

  H8MotorR motor_r;
  H8MotorR::Init(timer1);
  H8MotorL motor_l;
  H8MotorL::Init(timer0);

  H8MouseMovementController mouse;
  mouse.LinkMotor(motor_l, motor_r);

  moniter_led = 0b111;

  ENABLE_GLOBAL_INTRRUPT();

  while (true) {
    Result result;

    while (tact != ui::TactSwitch::ON)
      ;

    uint64_t start_time = Time::GetCurrentTime();
    mouse.Advance(319, 159);
    uint64_t process_time = Time::GetCurrentTime() - start_time;

    if (1950 < process_time && process_time < 2050) {
      for (uint16_t i = 0; i < 4; i++) {
        ~moniter_led;
        Time::Delay(200);
      }
    } else {
      moniter_led = 0b101;
      for (uint16_t i = 0; i < 10; i++) {
        ~moniter_led;
        Time::Delay(50);
      }
    }
  }

  return 0;
}

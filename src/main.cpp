#include <2022EOMMP>
#include <eommpsys>
#include "h83069fMMP/Motor.hpp"
#include "h83069fMMP/TimerIntrMane.hpp"

using namespace eommpsys;

int main(void) {
  DISABLE_GLOBAL_INTRRUPT();

  TimerManager::TMR23 tmr23(CompareMatchA, Raising,
                            Prescaler_8);  // 1ms clock
  // TimerManager::TimerCH2 timer2(CompareMatchB, Raising,
  //                               Prescaler_2);  // buzzer
  TimerManager::TimerCH1 timer1(CompareMatchB, Raising,
                                Prescaler_8);  // rmotor
  // TimerManager::TimerCH0 timer0(CompareMatchA, Raising, Prescaler_1);

  Time::init(tmr23);

  ui::MonLed moniter_led;
  ui::MonLed::init();

  ui::TactSwitch tact;
  ui::TactSwitch::init();

  H8MotorR motor_r;
  H8MotorR::init(timer1);

  uint16_t speed = 100;
  // H8Reg::PADDR |= 0b01010011;
  // timer1.setHandlerA(H8MotorR::intrHandlerA, 2083);
  // timer1.setHandlerB(H8MotorR::intrHandlerB, 4167);
  // motor_r.enableMotor();
  // timer1.start();

  moniter_led = 0b010;

  ENABLE_GLOBAL_INTRRUPT();

  while (motor_r.CheckEnd() == false)
    ;

  while (true) {
    if (tact == ui::TactSwitch::ON) {
      speed = 100;
      Time::delay(100);
      while (tact == ui::TactSwitch::ON)
        ;
      motor_r.enableMotor(true);
      motor_r.Start(1440, 100);

      while (!motor_r.CheckEnd()) {
        if (tact == ui::TactSwitch::ON) {
          speed += 50;
          Time::delay(50);
          motor_r.ChangeSpeed(speed);
        }
      }

      motor_r.enableMotor(false);
    }

    Time::delay(500);
    ~moniter_led;
  }

  return 0;
}

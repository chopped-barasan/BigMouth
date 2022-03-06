#include <2022EOMMP>
#include <eommpsys>

using namespace eommpsys;

int main(void) {
  DISABLE_GLOBAL_INTRRUPT();

  TimerManager::TMR23 tmr23(CompareMatchA, Raising, Prescaler_8);
  TimerManager::TimerCH2 timer2(CompareMatchB, Raising, Prescaler_2);

  Time::init(tmr23);

  ui::TactSwitch tact;
  ui::TactSwitch::init();

  ui::MonLed moniter_led;
  ui::MonLed::init();

  ui::CeraBuzzer buzzer;
  ui::CeraBuzzer::init(timer2);
  buzzer.setHelz(440.0f, 25);
  buzzer.start();

  ENABLE_GLOBAL_INTRRUPT();

  moniter_led = 0b101;

  while (true) {
    Time::delay(250);
    ~moniter_led;
  }

  return 0;
}

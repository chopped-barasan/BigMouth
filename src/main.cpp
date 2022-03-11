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
  ui::CeraBuzzer buzzer;
  ui::TactSwitch tact;
  ui::SlideSwitch slide;

  H8MotorR motor_r;
  H8MotorL motor_l;
  H8Mouse mouse;

  Time::Init(tmr23);

  ui::MonLed::Init();
  ui::CeraBuzzer::Init(timer2);
  ui::TactSwitch::Init();
  ui::SlideSwitch::Init();

  H8MotorR::Init(timer1);
  H8MotorL::Init(timer0);

  mouse.Init(motor_l, motor_r);

  buzzer.setHelz(1000, 50);
  moniter_led = 0b111;

  ENABLE_GLOBAL_INTRRUPT();

  // uint16_t speed = 100;
  while (true) {
    Result result = SUCCESS;

    // waiting
    while (tact != ui::TactSwitch::ON)
      ;

    // start count
    for (volatile uint16_t i = 0; i < 3; i++) {
      buzzer.start();
      Time::Delay(50);
      buzzer.mute();
      Time::Delay(450);
    }

    // init mouse
    mouse.SetStart();
    if (mouse.GetState() != MouseState::WAITING) {
      result = Result::RUNNING;
    }

    // run
    while (result == Result::SUCCESS) {
      static SideDegiSens_t position = {0};
      static Wall_t detected_wall = {0};
      MouseState current_state;

      current_state = mouse.GetState();

      if (mouse.OnCenter() &&
          (current_state < TURN_REQUIRED || current_state > KETSU)) {
        DegiSens_t sensor = mouse.GetDegiSens();

        // 移動幅の中央に居ることを示すフラグを倒す
        mouse.PutDownCenterFlag();

        // 偏り加減を取得(通路の右寄り左寄り)
        // 左寄りか
        position.left = (sensor.L1 == 1 || sensor.R3 == 1) &&
                        (sensor.L2 == 0 && sensor.R2 == 0);
        // 右寄りか
        position.right = (sensor.L3 == 1 || sensor.R1 == 1) &&
                         (sensor.L2 == 0 && sensor.R2 == 0);
        // 中央に近いか
        position.center = (sensor.L2 == 1 || sensor.R2 == 1);

        // 左右の壁の有無を調べる
        detected_wall.left = sensor.L1 || sensor.L2 || sensor.L3;
        detected_wall.right = sensor.R1 || sensor.R2 || sensor.R3;

        // 次に進む方向を設定する(ただし停止したときしか読み取らない)
        mouse.SetNextDir(detected_wall);

        // 次に到達するマスの壁の有無を設定
        mouse.next_wall.center = 0;
        mouse.next_wall.right = detected_wall.right;
        mouse.next_wall.left = detected_wall.left;
      }

      if (mouse.CheckFrontWall() &&
          (current_state < TURN_REQUIRED || current_state > KETSU)) {
        detected_wall.center = 1;
        mouse.next_wall.center = 1;
        mouse.Stop();
      }

      result = mouse.AutoPilot(position);
    }

    // while (true) {
    //   mouse.WallSensDebug();
    // }

    // result
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

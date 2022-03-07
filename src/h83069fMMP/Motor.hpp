#pragma once

#include <cmath>
#include "TimerIntrMane.hpp"

#define M_PI 3.14159265358979323846

namespace eommpsys {

class H8Motor {
 private:
  virtual void putRunning(void) = 0;
  virtual void setSignalAbort(bool) = 0;

 protected:
  virtual bool isRunning(void) = 0;
  virtual bool isAborting(void) = 0;

  virtual void Start_(uint16_t distance,
                      uint16_t speed,
                      bool reverse = false) = 0;
  virtual void Abort_(void) = 0;
  virtual void ChangeSpeed_(uint16_t speed) = 0;

 public:
  H8Motor() = default;
  ~H8Motor() = default;

  inline void Start(uint16_t distance, uint16_t speed, bool reverse = false) {
    if (speed <= 0) {
      return;
    } else if (isRunning()) {
      return;
    }

    setSignalAbort(false);
    Start_(distance, speed, reverse);

    putRunning();
  }

  inline void Abort() {
    if (isRunning() == false) {
      return;  // halted
    } else if (isAborting()) {
      return;  // aborting
    }

    setSignalAbort(true);
    Abort_();
  }

  inline void ChangeSpeed(uint16_t speed) {
    if (speed <= 0) {
      return;  // invalid speed
    } else if (isRunning() == false) {
      return;  // halted
    } else if (isAborting()) {
      return;  // aborting
    }

    ChangeSpeed_(speed);
  }

  inline bool CheckEnd() {
    if (isRunning()) {
      return false;  // running
    } else {
      return true;  // halted
    }
  }
};

class H8MotorR : public H8Motor {
 private:
  union un_h8motr {
    bitAccess_t<_BYTE, 0> enable;
    bitAccess_t<_BYTE, 1> phase;
    bitAccess_t<_BYTE, 4> step;
    bitAccess_t<_BYTE, 6> dir;
  };

  static inline auto& motor =
      *reinterpret_cast<union un_h8motr*>(H8Reg::addr_padr);
  static TimerManager::TimerBase<uint16_t>* timer;
  static bool running;
  static bool signal_abort;

  static volatile uint16_t target_val;
  static volatile uint16_t pulse_count;
  static float constant;

  static constexpr float diameter = 50.7f;
  static constexpr float circle(void) { return diameter * 2 * M_PI; }
  static constexpr float MovingDistanceByPulse(void) {
    return circle() * 0.005f;
  }
  static inline float calcBaseHz(clockSource_t source) {
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
  static inline uint16_t calcCompareVal(uint16_t speed) {
    return static_cast<uint16_t>(constant / speed);
  }

  static void intrHandlerA(void);
  static void intrHandlerB(void);

  inline void putRunning(void) override { running = true; }
  inline void setSignalAbort(bool flag) override { signal_abort = flag; }

  inline bool isRunning(void) override { return running; }
  inline bool isAborting(void) override { return signal_abort; }

  void Start_(uint16_t distance, uint16_t speed, bool reverse = false) override;
  void Abort_(void) override;
  void ChangeSpeed_(uint16_t speed) override;

  static inline void End(void) {
    running = false;
    signal_abort = false;
  }

 public:
  H8MotorR() = default;
  ~H8MotorR() = default;

  static void init(TimerManager::TimerBase<uint16_t>& tim);
  static void enableMotor(bool flag = true) {
#warning 試作ボード仕様になってます
    if (flag) {
      motor.enable = 0;
      motor.phase = 1;  // 試作ボード
    } else {
      motor.enable = 1;
      motor.phase = 0;  // 試作ボード
    }
  }
};

// class h8MotorR {
//  private:
//   union un_h8motr {
//     bitAccess_t<_BYTE, 0> enable;
//     bitAccess_t<_BYTE, 1> phase;
//     bitAccess_t<_BYTE, 4> step;
//     bitAccess_t<_BYTE, 6> dir;
//   };
//   static inline auto& motor =
//       *reinterpret_cast<union un_h8motr*>(H8Reg::addr_padr);

//   static TimerManager::TimerBase<uint16_t>* timer;

//   static void motorHandlerA(void);
//   static void motorHandlerB(void);

//   static constexpr float diameter = 50.7f;
//   static constexpr float circle(void) { return diameter * 2 * M_PI; }
//   static constexpr float lengthMovingAPulse(void) { return circle() * 0.005f;
//   }

//  public:
//   h8MotorR() = default;
//   ~h8MotorR() = default;

//   static void init(TimerManager::TimerBase<uint16_t>& tim);

//   void reverse(bool reverse) {
//     if (reverse) {
//       motor.dir = 1;
//     } else {
//       motor.dir = 0;
//     }
//   }

//   void start(void) {
//     motor.phase = 1;
//     timer->start();
//   }
//   void stop(void) {
//     motor.phase = 0;
//     timer->stop();
//   }
// };

}  // namespace eommpsys

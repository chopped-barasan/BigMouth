#pragma once

#include <math.h>
#include "TimerIntrMane.hpp"
#include "Types.hpp"

namespace eommpsys {

class H8Motor {
 private:
  virtual void putRunning(void) = 0;
  virtual void setSignalAbort(bool) = 0;

 protected:
  virtual bool isRunning(void) = 0;
  virtual bool isAborting(void) = 0;

  virtual Result Setup_(uint16_t degree,
                        uint16_t speed,
                        bool reverse = false) = 0;
  virtual void Abort_(void) = 0;
  virtual void ChangeSpeed_(uint16_t speed) = 0;

 public:
  H8Motor() = default;
  ~H8Motor() = default;

  virtual void Start(void) = 0;
  /**
   * @brief 回転を開始する
   *
   * @param degree 回転角度(degree)
   * @param speed 回転速度 (degree/sec)
   * @param reverse true: 逆回転, false: 正回転
   */
  inline Result Setup(uint16_t degree, uint16_t speed, bool reverse = false) {
    Result result;

    if (speed <= 0) {
      return Result::INVALID_SPEED;
    } else if (isRunning()) {
      return Result::RUNNING;
    }

    setSignalAbort(false);
    result = Setup_(degree, speed, reverse);

    if (result == Result::SUCCESS) {
      putRunning();
    }

    return result;
  }

  inline Result Abort() {
    if (isRunning() == false) {
      return Result::HALTED;  // halted
    } else if (isAborting()) {
      return Result::ABORTING;  // aborting
    }

    setSignalAbort(true);
    Abort_();

    return Result::SUCCESS;
  }

  inline Result ChangeSpeed(uint16_t speed) {
    if (speed <= 0) {
      return Result::INVALID_SPEED;  // invalid speed
    } else if (isRunning() == false) {
      return Result::HALTED;  // halted
    } else if (isAborting()) {
      return Result::ABORTING;  // aborting
    }

    ChangeSpeed_(speed);

    return Result::SUCCESS;
  }

  inline Result CheckEnd() {
    if (isRunning()) {
      return RUNNING;  // running
    } else {
      return HALTED;  // halted
    }
  }

  virtual void Enable(bool state = true) = 0;
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
  static volatile bool running;
  static volatile bool signal_abort;

  static volatile uint16_t target_val;
  static volatile uint16_t pulse_count;
  static float base_hz;

  // static constexpr float diameter = 50.7f;
  // static constexpr float circle(void) { return diameter * 2 * M_PI; }
  // static constexpr float MovingDistanceByPulse(void) {
  //   return circle() * 0.005f;
  // }
  static constexpr float ROTATE_DEGREE_PER_PULSE = 360.0f / 200.0f;
  static constexpr float calcBaseHz(const clockSource_t source);

  static void intrHandlerA(void);
  static void intrHandlerB(void);

  inline void putRunning(void) override { running = true; }
  inline void setSignalAbort(bool flag) override { signal_abort = flag; }

  inline bool isRunning(void) override { return running; }
  inline bool isAborting(void) override { return signal_abort; }

  /**
   * @brief 回転準備
   *
   * @param degree 回転角度(degree)
   * @param speed 回転速度 (degree/sec)
   * @param reverse true: 逆回転, false: 正回転
   */
  Result Setup_(uint16_t degree, uint16_t speed, bool reverse = false) override;
  void Abort_(void) override;
  void ChangeSpeed_(uint16_t speed) override;

  template <typename T>
  static constexpr uint16_t calcCompareVal(T speed) {
    return base_hz * (ROTATE_DEGREE_PER_PULSE / speed);
  }
  template <typename T>
  static constexpr uint16_t calcPulseFromDegree(T degree) {
    return static_cast<uint16_t>(degree / ROTATE_DEGREE_PER_PULSE);
  }

  static inline void End(void) {
    running = false;
    signal_abort = false;
  }

 public:
  H8MotorR() = default;
  ~H8MotorR() = default;

  inline void Start(void) override { timer->restart(); }
  static void init(TimerManager::TimerBase<uint16_t>& tim);
  inline void Enable(bool flag = true) override {
    // #warning 試作ボード仕様になってます
    if (flag) {
      motor.enable = 0;
      // motor.phase = 1;  // 試作ボード
    } else {
      motor.enable = 1;
      // motor.phase = 0;  // 試作ボード
    }
  }
};

class H8MotorL : public H8Motor {
 private:
  union un_h8motl {
    bitAccess_t<_BYTE, 0> enable;
    bitAccess_t<_BYTE, 1> phase;
    bitAccess_t<_BYTE, 5> step;
    bitAccess_t<_BYTE, 7> dir;
  };

  static inline auto& motor =
      *reinterpret_cast<union un_h8motl*>(H8Reg::addr_padr);
  static TimerManager::TimerBase<uint16_t>* timer;
  static volatile bool running;
  static volatile bool signal_abort;

  static volatile uint16_t target_val;
  static volatile uint16_t pulse_count;
  static float base_hz;

  static constexpr float ROTATE_DEGREE_PER_PULSE = 360.0f / 200.0f;
  static constexpr float calcBaseHz(const clockSource_t source);

  static void intrHandlerA(void);
  static void intrHandlerB(void);

  inline void putRunning(void) override { running = true; }
  inline void setSignalAbort(bool flag) override { signal_abort = flag; }

  inline bool isRunning(void) override { return running; }
  inline bool isAborting(void) override { return signal_abort; }

  /**
   * @brief 回転を開始する
   *
   * @param degree 回転角度(degree)
   * @param speed 回転速度 (degree/sec)
   * @param reverse true: 逆回転, false: 正回転
   */
  Result Setup_(uint16_t degree, uint16_t speed, bool reverse = false) override;
  void Abort_(void) override;
  void ChangeSpeed_(uint16_t speed) override;

  template <typename T>
  static constexpr uint16_t calcCompareVal(T speed) {
    return base_hz * (ROTATE_DEGREE_PER_PULSE / speed);
  }
  template <typename T>
  static constexpr uint16_t calcPulseFromDegree(T degree) {
    return static_cast<uint16_t>(degree / ROTATE_DEGREE_PER_PULSE);
  }

  static inline void End(void) {
    running = false;
    signal_abort = false;
  }

 public:
  H8MotorL() = default;
  ~H8MotorL() = default;

  inline void Start(void) { timer->restart(); }
  static void init(TimerManager::TimerBase<uint16_t>& tim);
  inline void Enable(bool flag = true) override {
    // #warning 試作ボード仕様になってます
    if (flag) {
      motor.enable = 0;
      // motor.phase = 1;  // 試作ボード
    } else {
      motor.enable = 1;
      // motor.phase = 0;  // 試作ボード
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

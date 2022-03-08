#pragma once

#include <cmath>
#include "TimerIntrMane.hpp"
#include "Types.hpp"

namespace eommpsys {

class H8Motor {
 private:
  virtual void PutRunning(void) = 0;
  virtual void SetSignalAbort(bool) = 0;

 protected:
  virtual bool IsRunning(void) = 0;
  virtual bool IsAborting(void) = 0;

  virtual Result Setup_(uint16_t distance,
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
    } else if (IsRunning()) {
      return Result::RUNNING;
    }

    SetSignalAbort(false);
    result = Setup_(degree, speed, reverse);

    if (result == Result::SUCCESS) {
      PutRunning();
    }

    return result;
  }

  inline Result Abort() {
    if (IsRunning() == false) {
      return Result::HALTED;  // halted
    } else if (IsAborting()) {
      return Result::ABORTING;  // aborting
    }

    SetSignalAbort(true);
    Abort_();

    return Result::SUCCESS;
  }

  inline Result ChangeSpeed(uint16_t speed) {
    if (speed <= 0) {
      return Result::INVALID_SPEED;  // invalid speed
    } else if (IsRunning() == false) {
      return Result::HALTED;  // halted
    } else if (IsAborting()) {
      return Result::ABORTING;  // aborting
    }

    ChangeSpeed_(speed);

    return Result::SUCCESS;
  }

  inline Result CheckEnd() {
    if (IsRunning()) {
      return Result::RUNNING;  // running
    } else {
      return Result::HALTED;  // halted
    }
  }

  virtual void Enable(bool) = 0;
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
  static uint32_t base_hz;

  static constexpr float ROTATE_DEGREE_PER_PULSE = 360.0f / 200.0f;

  static void intrHandlerA(void);
  static void intrHandlerB(void);

  inline void PutRunning(void) override { running = true; }
  inline void SetSignalAbort(bool flag) override { signal_abort = flag; }

  inline bool IsRunning(void) override { return running; }
  inline bool IsAborting(void) override { return signal_abort; }

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
  static uint16_t CalcCompareVal(const T speed) {
    return base_hz * (speed / ROTATE_DEGREE_PER_PULSE);
  }
  template <typename T>
  static uint16_t CalcPulseFromDegree(const T degree) {
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
  static void Init(TimerManager::TimerBase<uint16_t>& tim);
  void Enable(bool flag = true) override {
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
  static uint32_t base_hz;

  static constexpr float ROTATE_DEGREE_PER_PULSE = 360.0f / 200.0f;

  static void intrHandlerA(void);
  static void intrHandlerB(void);

  inline void PutRunning(void) override { running = true; }
  inline void SetSignalAbort(bool flag) override { signal_abort = flag; }

  inline bool IsRunning(void) override { return running; }
  inline bool IsAborting(void) override { return signal_abort; }

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
  static uint16_t CalcCompareVal(const T speed) {
    return base_hz * (speed / ROTATE_DEGREE_PER_PULSE);
  }
  template <typename T>
  static uint16_t CalcPulseFromDegree(const T degree) {
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
  static void Init(TimerManager::TimerBase<uint16_t>& tim);
  void Enable(bool flag = true) override {
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

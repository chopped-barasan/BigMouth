#pragma once
#include "2022EOMMP"

namespace eommpsys {
namespace TimerManager {

class TimerCH0 final : public TimerBase<uint16_t> {
 public:
  TimerCH0(counterClearTrigger_t clear, clockEdge_t edge, clockSource_t source)
      : TimerBase(clear, edge, source) {}
  ~TimerCH0() = default;

 private:
  inline void adaptHandlerA(void) override;
  inline void adaptHandlerB(void) override;
  inline void adaptHandlerOVF(void) override;

 public:
  void start(void) override;
  inline void stop(void) override;

  inline void adaptGeneralA(uint16_t val) override {
    Peripherals::Timer0::setGRA(val);
  }
  inline void adaptGeneralB(uint16_t val) override {
    Peripherals::Timer0::setGRB(val);
  }
  static inline void setIOModeA(IOMode_t io_mode) {
    Peripherals::Timer0::setIOModeA(io_mode);
  }
  static inline void setIOModeB(IOMode_t io_mode) {
    Peripherals::Timer0::setIOModeB(io_mode);
  }
  static inline void pwmMode(bool flag) { Peripherals::Timer0::pwmMode(flag); }
  static inline void syncMode(bool flag) { Peripherals::Timer0::pwmMode(flag); }
};

class TimerCH1 final : public TimerBase<uint16_t> {
 public:
  TimerCH1(counterClearTrigger_t clear, clockEdge_t edge, clockSource_t source)
      : TimerBase(clear, edge, source) {}
  ~TimerCH1() = default;

 private:
  inline void adaptHandlerA(void) override;
  inline void adaptHandlerB(void) override;
  inline void adaptHandlerOVF(void) override;

 public:
  void start(void) override;
  inline void stop(void) override;

  inline void adaptGeneralA(uint16_t val) override {
    Peripherals::Timer1::setGRA(val);
  }
  inline void adaptGeneralB(uint16_t val) override {
    Peripherals::Timer1::setGRB(val);
  }
  static inline void setIOModeA(IOMode_t io_mode) {
    Peripherals::Timer1::setIOModeA(io_mode);
  }
  static inline void setIOModeB(IOMode_t io_mode) {
    Peripherals::Timer1::setIOModeB(io_mode);
  }
  static inline void pwmMode(bool flag) { Peripherals::Timer1::pwmMode(flag); }
  static inline void syncMode(bool flag) { Peripherals::Timer1::pwmMode(flag); }
};

class TimerCH2 final : public TimerBase<uint16_t> {
 public:
  TimerCH2(counterClearTrigger_t clear, clockEdge_t edge, clockSource_t source)
      : TimerBase(clear, edge, source) {}
  ~TimerCH2() = default;

 private:
  inline void adaptHandlerA(void) override;
  inline void adaptHandlerB(void) override;
  inline void adaptHandlerOVF(void) override;

 public:
  void start(void) override;
  inline void stop(void) override;

  inline void adaptGeneralA(uint16_t val) override {
    Peripherals::Timer2::setGRA(val);
  }
  inline void adaptGeneralB(uint16_t val) override {
    Peripherals::Timer2::setGRB(val);
  }
  static inline void setIOModeA(IOMode_t io_mode) {
    Peripherals::Timer2::setIOModeA(io_mode);
  }
  static inline void setIOModeB(IOMode_t io_mode) {
    Peripherals::Timer2::setIOModeB(io_mode);
  }
  static inline void pwmMode(bool flag) { Peripherals::Timer2::pwmMode(flag); }
  static inline void syncMode(bool flag) { Peripherals::Timer2::pwmMode(flag); }
};

/**
 * @brief TMR2とTMR3をカスケード接続して16bitタイマーとして使うクラス
 *
 */
class TMR23 final : public TimerBase<uint16_t> {
 public:
  TMR23(counterClearTrigger_t clear, clockEdge_t edge, clockSource_t source)
      : TimerBase(clear, edge, source) {}
  ~TMR23() = default;

 private:
  void adaptHandlerA(void) override;
  void adaptHandlerB(void) override;
  void adaptHandlerOVF(void) override;

 public:
  void start(void) override;
  inline void stop(void) override;

  inline void adaptGeneralA(uint16_t val) override { H8Reg::TMR23.TCORA = val; }
  inline void adaptGeneralB(uint16_t val) override { H8Reg::TMR23.TCORB = val; }
};

}  // namespace TimerManager
}  // namespace eommpsys

/**
 * @file timerManager.hpp
 * @author 20eo0125 松原広樹
 * @brief タイマー周りの割り込みの登録とか云々
 * 正直使う分しか実装してないです。
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <eommpsys>

namespace eommpsys {
namespace TimerManager {

/**
 * @brief タイマーオブジェクトのインターフェース。
 *
 * @tparam T タイマーの分解能を指定
 *
 * @details タイマーの設定値を保持しておくものです。start()を呼び出すまでは設定値は代入されません。
 * なのでクロックソースとかいろいろ設定の違うオブジェクトをいっぱい作って使うときにそれぞれのstart()を呼び出せば、
 * 同じタイマーを別々の設定で使い回すのが少し楽になります。
 */
template <typename T>
class TimerBase {
 protected:
  counterClearTrigger_t clear_cause;  // カウンタのクリア要因
  clockEdge_t clock_edge;             // カウントエッジ
  clockSource_t clock_source;         // クロックソース
  T compare_a;                        // コンペアマッチAの値
  T compare_b;                        // コンペアマッチBの値

  intrHandler_t handler_a;    // 割り込みハンドラA
  intrHandler_t handler_b;    // 割り込みハンドラB
  intrHandler_t handler_ovf;  // 割り込みハンドラOVF

  /**
   * @brief コンペアマッチA割り込みのハンドラを登録し、割り込みを許可する。
   *
   */
  virtual void adaptHandlerA(void) = 0;
  /**
   * @brief コンペアマッチB割り込みのハンドラを登録し、割り込みを許可する。
   *
   */
  virtual void adaptHandlerB(void) = 0;
  /**
   * @brief オーバーフロー割り込みのハンドラを登録し、割り込みを許可する。
   *
   */
  virtual void adaptHandlerOVF(void) = 0;

 public:
  /**
  * @brief TimerBase のコンストラクタ。
  *
  * @param clear カウントクリア要因
  * @param edge カウントエッジ
  * @param source クロックソース
  */
  TimerBase(counterClearTrigger_t clear, clockEdge_t edge, clockSource_t source)
      : clear_cause(clear),
        clock_edge(edge),
        clock_source(source),
        compare_a(0),
        compare_b(0),
        handler_a(nullptr),
        handler_b(nullptr),
        handler_ovf(nullptr) {}
  /**
   * @brief TimerBase のデコンストラクタ。
   *
   */
  ~TimerBase() = default;

  /**
   * @brief HandlerA を設定する。
   *
   * @param handler 割り込みハンドラ
   * @param val コンペアマッチの値
   */
  void setHandlerA(intrHandler_t handler, T val) {
    this->handler_a = handler;
    this->compare_a = val;
  }
  /**
   * @brief Handler B を設定する。
   *
   * @param handler 割り込みハンドラ
   * @param val コンペアマッチの値
   */
  void setHandlerB(intrHandler_t handler, T val) {
    this->handler_b = handler;
    this->compare_b = val;
  }
  /**
   * @brief HandlerOVF を設定する。
   *
   * @param handler 割り込みハンドラ
   */
  void setHandlerOVF(intrHandler_t handler) { this->handler_ovf = handler; }

  /**
   * @brief ClearCause を取得する。
   *
   * @return counterClearTrigger_t 設定中のカウンタクリア要因
   */
  inline counterClearTrigger_t getClearCause(void) const { return clear_cause; }
  /**
   * @brief ClockEdge を取得する。
   *
   * @return clockEdge_t 設定中のカウンタエッジ
   */
  inline clockEdge_t getClockEdge(void) const { return clock_edge; }
  /**
   * @brief ClockSource を取得する。
   *
   * @return clockSource_t 設定中のクロックソース
   */
  inline clockSource_t getClockSource(void) const { return clock_source; }

  /**
   * @brief タイマーのカウントを開始する。
   *
   */
  virtual void start(void) = 0;
  /**
   * @brief タイマーのカウントを停止する。
   *
   */
  virtual void stop(void) = 0;
  /**
   * @brief コンペアマッチAの値を設定する。
   *
   * @param val
   */
  virtual void setGeneralA(uint16_t val) = 0;
  /**
   * @brief コンペアマッチBの値を設定する。
   *
   * @param val
   */
  virtual void setGeneralB(uint16_t val) = 0;
};

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

  inline void setGeneralA(uint16_t val) override {
    Peripherals::Timer0::setGRA(val);
  }
  inline void setGeneralB(uint16_t val) override {
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

  inline void setGeneralA(uint16_t val) override {
    Peripherals::Timer1::setGRA(val);
  }
  inline void setGeneralB(uint16_t val) override {
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

  inline void setGeneralA(uint16_t val) override {
    Peripherals::Timer2::setGRA(val);
  }
  inline void setGeneralB(uint16_t val) override {
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

  inline void setGeneralA(uint16_t val) override { H8Reg::TMR23.TCORA = val; }
  inline void setGeneralB(uint16_t val) override { H8Reg::TMR23.TCORB = val; }
};

}  // namespace TimerManager
}  // namespace eommpsys

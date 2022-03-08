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

using namespace h8mmpsys;

namespace eommpsys {
namespace TimerManager {

/**
 * @brief タイマーオブジェクトのインターフェース。
 *
 * @tparam T タイマーの分解能を指定
 *
 * @details
 * タイマーの設定値を保持しておくものです。start()を呼び出すまでは設定値は代入されません。
 * なのでクロックソースとかいろいろ設定の違うオブジェクトをいっぱい作って使うときにそれぞれのstart()を呼び出せば、
 * 同じタイマーを別々の設定で使い回すのが少し楽になります。
 */
template <typename T>
class TimerBase {
 protected:
  const counterClearTrigger_t clear_cause;  // カウンタのクリア要因
  const clockEdge_t clock_edge;             // カウントエッジ
  const clockSource_t clock_source;         // クロックソース
  T compare_a;                              // コンペアマッチAの値
  T compare_b;                              // コンペアマッチBの値

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
   * @brief コンペアマッチAの値 を設定する。
   *
   * @param val
   */
  void setGeneralA(T val) { this->compare_a = val; }
  /**
   * @brief コンペアマッチBの値 を設定する。
   *
   * @param val
   */
  void setGeneralB(T val) { this->compare_b = val; }

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
  virtual void adaptGeneralA(uint16_t val) = 0;
  /**
   * @brief コンペアマッチBの値を設定する。
   *
   * @param val
   */
  virtual void adaptGeneralB(uint16_t val) = 0;
};

}  // namespace TimerManager
}  // namespace eommpsys

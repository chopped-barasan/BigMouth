/**
 * @file delay.hpp
 * @author 20eo0125 松原広樹
 * @brief 時間関係
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <cinttypes>
#include "timerManager.hpp"

// using namespace h8mmpsys;

namespace eommpsys {
/**
 * @brief 時間関係のクラス
 *
 * @details
 * 分周なしか8分周のタイマーを使用してください。なぜなら書くのがめんどくさかったからです。
 */
class Time {
 private:
  /// 使用するタイマーオブジェクト
  static TimerManager::TimerBase<uint16_t>* timer;

  /// 経過時間
  static volatile uint64_t current_time;
  /// 割り込みハンドラ
  static void delayHandler(void) { current_time++; }

  /// 16bitタイマー使ってるときのコンペアマッチの値
  static constexpr uint16_t compare_1 = 25000;
  /// 8bitタイマーカスケード接続して使ってるときのコンペアマッチの値
  static constexpr uint16_t compare_8 = 3125;
  /**
   * @brief コンペアマッチの値を計算する。
   *
   * @param source
   * @return constexpr uint16_t
   */
  static constexpr uint16_t calcCompareNum(clockSource_t source) {
    uint16_t ret_val = 0;
    if (source == Prescaler_1) {
      ret_val = compare_1;
    } else if (source == Prescaler_8) {
      ret_val = compare_8;
    } else {
      // nothing to do
    }
    return ret_val;
  }

 public:
  /**
   * @brief Time のコンストラクタ。
   *
   */
  Time() = default;
  /**
   * @brief Time のデコンストラクタ。
   *
   */
  ~Time() = default;

  /**
   * @brief 初期化関数
   *
   * @param tim
   * 使用するタイマーオブジェクト(分周なしか8分周の設定をしたものを使用してください)
   */
  static void Init(TimerManager::TimerBase<uint16_t>& tim) {
    timer = &tim;
    timer->setHandlerA(Time::delayHandler,
                       calcCompareNum(timer->getClockSource()));
    timer->start();
  }
  /**
   * @brief CurrentTime を取得する。
   *
   * @return uint64_t プログラムの経過時間(ms)
   */
  static inline uint64_t GetCurrentTime(void) { return current_time; }
  /**
   * @brief 指定した時間待機します。
   *
   * @param ms 待機時間(ms)
   */
  static void Delay(uint64_t ms) {
    uint64_t start_time = GetCurrentTime();
    while (GetCurrentTime() - start_time < ms)
      ;
  }
};

}  // namespace eommpsys

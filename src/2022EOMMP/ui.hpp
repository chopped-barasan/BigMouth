/**
 * @file ui.hpp
 * @author 20eo0125 松原広樹
 * @brief LEDとかボタンとかのUI周りのやつ
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <eommpsys>
#include "utils/timerManager.hpp"

using namespace h8mmpsys;

namespace eommpsys {
namespace ui {

/**
 * @brief モニターLED
 *
 */
class MonLed {
 private:
  /// レジスタ操作用のunion
  union un_monled {
    bitAccess_t<_BYTE, 0, 2> ALL;  // LED全部
    union {
      bitAccess_t<_BYTE, 0> LEFT;  // 側端のLED(便宜上左としている)
      bitAccess_t<_BYTE, 1> CENTER;  // 中央のLED
      bitAccess_t<_BYTE, 2> RIGHT;  // 側端のLED(便宜上左としている)
    } BIT;
  };
  /// レジスタ操作用
  static inline auto& moniterLed =
      *reinterpret_cast<union un_monled*>(H8Reg::addr_p1dr);

 public:
  /**
   * @brief MonLed のコンストラクタ。
   *
   */
  MonLed() = default;
  /**
   * @brief MonLed のデコンストラクタ。
   *
   */
  ~MonLed() = default;

  static constexpr uint8_t ON = 0;   // アクティブローのため0がオン
  static constexpr uint8_t OFF = 1;  // アクティブローのため1がオフ

  /**
   * @brief 初期化関数。
   *
   * @details ポート1の1~3ビットを出力モードにする
   */
  static inline void init(void) { H8Reg::P1DDR |= 0x07; }

  /**
   * @brief 左LEDの制御関数。
   *
   * @param state true: 点灯, false: 消灯
   */
  inline void left(bool state) {
    moniterLed.BIT.LEFT = state ? MonLed::ON : MonLed::OFF;
  }
  /**
   * @brief 中央LEDの制御関数。
   *
   * @param state true: 点灯, false: 消灯
   */
  inline void center(bool state) {
    moniterLed.BIT.CENTER = state ? MonLed::ON : MonLed::OFF;
  }
  /**
   * @brief 右LEDの制御関数。
   *
   * @param state true: 点灯, false: 消灯
   */
  inline void right(bool state) {
    moniterLed.BIT.RIGHT = state ? MonLed::ON : MonLed::OFF;
  }

  /**
   * @brief 直接代入できます。
   *
   * @param pattern 代入するパターン
   */
  void operator=(const uint8_t pattern) { moniterLed.ALL = pattern; }
  /**
   * @brief 現在の点灯状態を反転する。
   *
   * @return uint8_t 反転後の状態
   */
  uint8_t operator~(void) {
    moniterLed.ALL = ~moniterLed.ALL;
    return moniterLed.ALL;
  }
};

/**
 * @brief タクトスイッチ
 *
 */
class TactSwitch {
 private:
  /// レジスタ操作用のstruct
  struct st_tact {
    bitAccess_t<_BYTE, 0> TACT;  // タクトスイッチ
  };
  /// レジスタ操作用
  static inline auto& tact_switch =
      *reinterpret_cast<struct st_tact*>(H8Reg::addr_p5dr);

 public:
  /**
   * @brief TactSwitch のコンストラクタ。
   *
   */
  TactSwitch() = default;
  /**
   * @brief TactSwitch のデコンストラクタ。
   *
   */
  ~TactSwitch() = default;

  static constexpr uint8_t ON = 0;   // アクティブローのため0がオン
  static constexpr uint8_t OFF = 1;  // アクティブローのため1がオフ

  /**
   * @brief 初期化関数。
   *
   * @details
   * ポート5の1ビットを入力モードにし、内部プルアップモードをオンにする。
   */
  static inline void init(void) {
    H8Reg::P5DDR &= ~(0x01);
    H8Reg::P5PCR.BIT.B0 = 1;
  }

  /**
   * @brief 現在の入力状態を返す。(アクティブロー)
   *
   * @return uint8_t 入力状態
   */
  operator uint8_t() const { return tact_switch.TACT; }
  /**
   * @brief 現在の入力状態を返す。(アクティブロー)
   *
   * @return uint8_t 入力状態
   */
  static inline uint8_t state(void) { return tact_switch.TACT; }
};

/**
 * @brief スライドスイッチ
 *
 */
class SlideSwitch {
 private:
  /// レジスタ操作用struct
  struct st_slide {
    bitAccess_t<_BYTE, 2> SLIDE;  // スライドスイッチ
  };
  /// レジスタ操作用
  static inline auto& slide_switch =
      *reinterpret_cast<struct st_slide*>(H8Reg::addr_p5dr);

 public:
  /**
   * @brief SlideSwitch のコンストラクタ。
   *
   */
  SlideSwitch() = default;
  /**
   * @brief SlideSwitch のデコンストラクタ。
   *
   */
  ~SlideSwitch() = default;

  static constexpr uint8_t ON = 0;   // アクティブローのため0がオン
  static constexpr uint8_t OFF = 1;  // アクティブローのため1がオフ

  /**
   * @brief 初期化関数。
   *
   * @details
   * ポート5の3ビットを入力モードにし、内部プルアップモードをオンにする。
   */
  static inline void init(void) {
    H8Reg::P5DDR &= ~(0x04);
    H8Reg::P5PCR.BIT.B2 = 1;
  }
  /**
   * @brief 状態の取得。
   *
   * @return uint8_t
   */
  operator uint8_t() const { return slide_switch.SLIDE; }
};

/**
 * @brief ブザー
 *
 * @details ほとんどstaticなんですけどこれってどうなんでしょう。
 */
class CeraBuzzer {
 private:
  /// ビット操作用struct
  struct st_buzzer {
    bitAccess_t<_BYTE, 7> BUZZER;  // ブザー
  };
  static inline auto& ceramic_buzzer =
      *reinterpret_cast<struct st_buzzer*>(H8Reg::addr_p1dr);
  /// 基準となる周波数
  static float base_hz;
  /// 使用するタイマーオブジェクト
  static TimerManager::TimerBase<uint16_t>* timer;

  static void handlerOn(void) { H8Reg::P1DR.BIT.B7 = 1; }  // 割り込みハンドラA
  static void handlerOff(void) { H8Reg::P1DR.BIT.B7 = 0; }  // 割り込みハンドラB

  /**
   * @brief 基準となる周波数を計算する。
   *
   * @param source タイマーに設定されているクロックソース
   * @return float 基準の周波数
   */
  static constexpr float calcBaseHz(const clockSource_t source) {
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
  /**
   * @brief
   * 鳴らしたい周波数から16bitタイマーのコンペアマッチに設定するべき値を計算する。
   *
   * @param hz
   * @return uint16_t コンペアマッチの値
   */
  static uint16_t calcGeneralVal(float hz) {
    return static_cast<uint16_t>(base_hz / hz);
  }

  static constexpr float calcDutyRatio(uint8_t val) {
    float temp = 0.0f;
    if (val <= 100) {
      val = 100 - val;
      temp = static_cast<float>(val) / 100.0f;
    } else {
      temp = 0.5f;
    }
    return temp;
  }

 public:
  /**
   * @brief CeraBuzzer のコンストラクタ。
   *
   */
  CeraBuzzer() = default;
  /**
   * @brief CeraBuzzer のデコンストラクタ。
   *
   */
  ~CeraBuzzer() = default;

  /**
   * @brief 初期化関数。
   *
   * @param tim 使用するタイマーのオブジェクト。
   *
   * @details
   * ポート1の8ビットを出力モードにし、基準周波数を計算し、割り込みハンドラを割り当てる
   */
  static inline void init(TimerManager::TimerBase<uint16_t>& tim) {
    timer = &tim;
    H8Reg::P1DDR |= 0x80;
    base_hz = calcBaseHz(timer->getClockSource());
    timer->setHandlerA(handlerOn, 14204);
    timer->setHandlerB(handlerOff, 28409);
  }
  /**
   * @brief 周波数とデューティー比を設定する。
   *
   * @param hz 鳴らしたい周波数
   * @param duty_ratio デューティー比
   *
   * @details
   * デューティー比変えられたら面白いかなって思ったんですけど、音変わんなかったです。
   * まあ波形確認してないんでコード間違えてるだけかもしれないですが。
   */
  inline void setHelz(float hz, uint8_t duty_ratio) {
    uint16_t temp = calcGeneralVal(hz);
    timer->adaptGeneralB(temp);
    timer->adaptGeneralA(temp * calcDutyRatio(duty_ratio));
  }

  /**
   * @brief 音を鳴らし始める。
   *
   */
  inline void start(void) { timer->start(); }
  /**
   * @brief 音を止める。
   *
   */
  inline void mute(void) {
    handlerOff();
    timer->stop();
  }
};

}  // namespace ui
}  // namespace eommpsys

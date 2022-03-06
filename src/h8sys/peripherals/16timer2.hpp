#pragma once

#include <cinttypes>
#include "3069.h"
#include "inttrupts/intr.h"
#include "iodef.hpp"

namespace eommpsys {
namespace Peripherals {
namespace Timer2 {
/// タイマーカウントをスタート
inline void startTimer(void) {
  eommpsys::H8Reg::ITU.TSTR.BIT.STR2 = 1;
}
/// タイマーカウントをストップ
inline void stopTimer(void) {
  eommpsys::H8Reg::ITU.TSTR.BIT.STR2 = 0;
}
/// 独立動作・同期動作を選択（true: 同期動作 false: 独立動作)
inline void syncMode(bool flag) {
  eommpsys::H8Reg::ITU.TSNC.BIT.SYNC2 = flag;
}
/// PWMモードの設定 (true: PWMモード false: 通常動作)
inline void pwmMode(bool flag) {
  eommpsys::H8Reg::ITU.TMDR.BIT.PWM2 = flag;
}
/*              Aチャネル               */
/// GRAによるコンペアマッチ・インプットキャプチャの発生を示す
inline bool intrruptStatsA(void) {
  return eommpsys::H8Reg::ITU.TISRA.BIT.IMFA2;
}
/// GRAによるコンペアマッチ・インプットキャプチャの発生を示すフラグをリセットする
inline void resetIntrFlagA(void) {
  eommpsys::H8Reg::ITU.TISRA.BIT.IMFA2 = 0;
}
/// IMFAによる割り込みの設定(true: 許可 false: 禁止)
inline void permitIntrA(bool flag) {
  eommpsys::H8Reg::ITU.TISRA.BIT.IMIEA2 = flag;
}
/// IMFAによる割り込みの認可状況
inline bool getPermissionIntrA(void) {
  return eommpsys::H8Reg::ITU.TISRA.BIT.IMIEA2;
}
/*              Bチャネル               */
/// GRBによるコンペアマッチ・インプットキャプチャの発生を示す
inline bool intrruptStatsB(void) {
  return eommpsys::H8Reg::ITU.TISRB.BIT.IMFB2;
}
/// GRBによるコンペアマッチ・インプットキャプチャの発生を示すフラグをリセットする
inline void resetIntrFlagB(void) {
  eommpsys::H8Reg::ITU.TISRB.BIT.IMFB2 = 0;
}
/// IMFBによる割り込みの設定(true: 許可 false: 禁止)
inline void permitIntrB(bool flag) {
  eommpsys::H8Reg::ITU.TISRB.BIT.IMIEB2 = flag;
}
/// IMFBによる割り込みの認可状況
inline bool getPermissionIntrB(void) {
  return eommpsys::H8Reg::ITU.TISRB.BIT.IMIEB2;
}
/*              OVF                     */
/// オーバーフロー・アンダーフローによるコンペアマッチ・インプットキャプチャの発生を示す
inline bool intrruptStatsOVF(void) {
  return eommpsys::H8Reg::ITU.TISRC.BIT.OVF2;
}
/// GRBによるコンペアマッチ・インプットキャプチャの発生を示すフラグをリセットする
inline void resetIntrFlagOVF(void) {
  eommpsys::H8Reg::ITU.TISRC.BIT.OVF2 = 0;
}
/// OVF0による割り込みの設定(true: 許可 false: 禁止)
inline void permitIntrOVF(bool flag) {
  eommpsys::H8Reg::ITU.TISRC.BIT.OVIE2 = flag;
}
/// OVF0による割り込みの認可状況
inline bool getPermissionIntrOVF(void) {
  return eommpsys::H8Reg::ITU.TISRC.BIT.OVIE2;
}
/// GRAを取得する
inline uint16_t getGRA(void) {
  return eommpsys::H8Reg::ITU2.GRA;
}
/// GRAに代入する
inline void setGRA(uint16_t val) {
  eommpsys::H8Reg::ITU2.GRA = val;
}
/// GRBを取得する
inline uint16_t getGRB(void) {
  return eommpsys::H8Reg::ITU2.GRB;
}
/// GRBに代入する
inline void setGRB(uint16_t val) {
  eommpsys::H8Reg::ITU2.GRB = val;
}
/// プリスケーラ設定レジスタの値を計算
static constexpr uint8_t calcClockSource(clockSource_t ps) {
  uint8_t val = 0;
  switch (ps) {
    case clockSource_t::Prescaler_1:
      val = 0x00;
      break;
    case clockSource_t::Prescaler_2:
      val = 0x01;
      break;
    case clockSource_t::Prescaler_4:
      val = 0x02;
      break;
    case clockSource_t::Prescaler_8:
      val = 0x03;
      break;
    case clockSource_t::External_TCLKA:
      val = 0x04;
      break;
    case clockSource_t::External_TCLKB:
      val = 0x05;
      break;
    case clockSource_t::External_TCLKC:
      val = 0x06;
      break;
    case clockSource_t::External_TCLKD:
      val = 0x07;
      break;
    default:
      val = 0x00;
      break;
  }
  return val;
}
/// プリスケーラの設定 φ, φ/2, φ/4, φ/8で設定可能 (その他の値の場合は等倍に設定)
inline void setPrescaler(clockSource_t ps) {
  eommpsys::H8Reg::ITU2.TCR.BIT.TPSC = calcClockSource(ps);
}
/// 現在のプリスケーラ設定の読み出し
inline clockSource_t getPreScaler(void) {
  clockSource_t ret_val;

  switch (eommpsys::H8Reg::ITU2.TCR.BIT.TPSC) {
    case 0x00:
      ret_val = clockSource_t::Prescaler_1;
      break;
    case 0x01:
      ret_val = clockSource_t::Prescaler_2;
      break;
    case 0x02:
      ret_val = clockSource_t::Prescaler_4;
      break;
    case 0x03:
      ret_val = clockSource_t::Prescaler_8;
      break;
    default:
      ret_val = clockSource_t::Prescaler_1;
      break;
  }

  return ret_val;
}
// 入力エッジ設定レジスタの値を計算
static constexpr uint8_t calcClockEdge(clockEdge_t ce) {
  uint8_t val = 0;
  switch (ce) {
    case clockEdge_t::Raising:
      val = 0x00;
      break;
    case clockEdge_t::Falling:
      val = 0x01;
      break;
    case clockEdge_t::Both:
      val = 0x02;
      break;
    default:
      val = 0x00;
      break;
  }

  return val;
}
/// 外部クロック選択時の入力エッジ選択 (0: 立ち上がり 1: 立ちさがり 2: 両エッジ その他: 立ち上がり)
inline void setClockEdge(clockEdge_t ce) {
  eommpsys::H8Reg::ITU2.TCR.BIT.CKEG = calcClockEdge(ce);
}
/// 外部クロックの入力エッジ設定状況の取得 (0: 立ち上がり 1: 立ち下がり 2:両エッジ)
inline uint8_t getClockEdge(void) {
  clockEdge_t ret_val;
  switch (eommpsys::H8Reg::ITU2.TCR.BIT.CKEG) {
    case 0x00:
      ret_val = clockEdge_t::Raising;
      break;
    case 0x01:
      ret_val = clockEdge_t::Falling;
      break;
    case 0x02:
      ret_val = clockEdge_t::Both;
      break;
    default:
      ret_val = clockEdge_t::Raising;
      break;
  }
  return ret_val;
}
/// カウンタクリア要因設定レジスタの値を計算する
static constexpr uint8_t calcCounterClearCause(counterClearTrigger_t cause) {
  uint8_t val = 0x00;
  switch (cause) {
    case counterClearTrigger_t::NeverClear:
      val = 0x00;
      break;
    case counterClearTrigger_t::CompareMatchA:
      val = 0x01;
      break;
    case counterClearTrigger_t::CompareMatchB:
      val = 0x02;
      break;
    case counterClearTrigger_t::SyncOther:
      val = 0x03;
      break;
    default:
      val = 0x00;
      break;
  }
  return val;
}
/// カウンタクリア要因の設定 (禁止, GRA, GRB, 同期クリア)
inline void setCounterClearCause(counterClearTrigger_t cause) {
  eommpsys::H8Reg::ITU2.TCR.BIT.CCLR = calcCounterClearCause(cause);
}
/// 設定中のカウンタクリア要因の取得
inline uint8_t getCounterClearCause(void) {
  counterClearTrigger_t ret_val;
  switch (eommpsys::H8Reg::ITU2.TCR.BIT.CKEG) {
    case 0x00:
      ret_val = counterClearTrigger_t::NeverClear;
      break;
    case 0x01:
      ret_val = counterClearTrigger_t::CompareMatchA;
      break;
    case 0x02:
      ret_val = counterClearTrigger_t::CompareMatchB;
      break;
    case 0x03:
      ret_val = counterClearTrigger_t::SyncOther;
      break;
    default:
      ret_val = counterClearTrigger_t::NeverClear;
      break;
  }
  return ret_val;
}
/// タイマー出力端子設定レジスタの値を計算
static constexpr uint8_t calcIOReg(IOMode_t mode) {
  uint8_t val = 0x00;
  switch (mode) {
    case IOMode_t::InhibitOutput:
      val = 0x00;
      break;
    case IOMode_t::LowCompareMatch:
      val = 0x01;
      break;
    case IOMode_t::HighCompareMatch:
      val = 0x02;
      break;
    case IOMode_t::ToggleCompareMatch:
      val = 0x03;
      break;
    case IOMode_t::InputRaisingEdge:
      val = 0x04;
      break;
    case IOMode_t::InputFallingEdge:
      val = 0x05;
      break;
    default:
      val = 0x06;
      break;
  }

  return val;
}
/// GRAの入出力、TIORA端子の機能設定
inline void setIOModeA(IOMode_t mode) {
  eommpsys::H8Reg::ITU2.TIOR.BIT.IOA = calcIOReg(mode);
}
/// GRBの入出力、TIORB端子の機能設定
inline void setIOModeB(IOMode_t mode) {
  eommpsys::H8Reg::ITU2.TIOR.BIT.IOB = calcIOReg(mode);
}
/// タイマー出力レベルの設定
inline void setTimerPinLevelA(bool state) {
  eommpsys::H8Reg::ITU.TOLR.BIT.TOA2 = state;
}
/// タイマー出力レベルの設定
inline void setTimerPinLevelB(bool state) {
  eommpsys::H8Reg::ITU.TOLR.BIT.TOB2 = state;
}
/// 位相計測モードの設定(true: 位相計測モード, false: 通常モード)
inline void setPhaseMeasureMode(bool state) {
  eommpsys::H8Reg::ITU.TMDR.BIT.MDF = state;
}
/// TISRCのOVFフラグのセット条件を設定(true: 16TCNT2がオーバーフローしたときに1にセット, false: 16TCNT2がオーバーフローもしくはアンダーフロー)
inline void setTriggerOVF(bool state) {
  eommpsys::H8Reg::ITU.TMDR.BIT.FDIR = state;
}

inline void setIntrHandlerA(intrHandler_t handler) {
  set_imia2_handler(handler);
}

inline void setIntrHandlerB(intrHandler_t handler) {
  set_imib2_handler(handler);
}

inline void setIntrHandlerOVF(intrHandler_t handler) {
  set_ovi2_handler(handler);
}

}  // namespace Timer2
}  // namespace Peripherals
}  // namespace eommpsys

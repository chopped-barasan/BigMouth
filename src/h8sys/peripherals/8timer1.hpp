#pragma once

#include <cinttypes>
#include "3069.h"
#include "inttrupts/intr.h"
#include "iodef.hpp"

namespace h8mmpsys {
namespace Peripherals {
namespace TMR1 {
/// インプットキャプチャイネーブル
inline void setInputCapture(bool flag) {
  h8mmpsys::H8Reg::TMR1.TCSR.BIT.ICE = flag;
}

inline uint8_t getInputCapture(void) {
  return h8mmpsys::H8Reg::TMR1.TCSR.BIT.ICE;
}

/// CMFAによる割り込みの認可状況
inline bool intrruptStatsA(void) {
  return h8mmpsys::H8Reg::TMR1.TCSR.BIT.CMFA;
}
/// CMFAのリセット
inline void resetIntrFlagA(void) {
  h8mmpsys::H8Reg::TMR1.TCSR.BIT.CMFA = 0;
}
/// CMFAによる割り込みの設定(true: 許可 false: 禁止)
inline void permitIntrA(bool flag) {
  h8mmpsys::H8Reg::TMR1.TCR.BIT.CMIEA = flag;
}
/// CMFAによる割り込みの認可状況
inline bool getPermissionIntrA(void) {
  return h8mmpsys::H8Reg::TMR1.TCR.BIT.CMIEA;
}
/// TCORBによるコンペアマッチ・インプットキャプチャの発生を示す
inline bool intrruptStatsB(void) {
  return h8mmpsys::H8Reg::TMR1.TCSR.BIT.CMFB;
}
/// CMFBのリセット
inline void resetIntrFlagB(void) {
  h8mmpsys::H8Reg::TMR1.TCSR.BIT.CMFB = 0;
}
/// CMFBによる割り込みの設定(true: 許可 false: 禁止)
inline void permitIntrB(bool flag) {
  h8mmpsys::H8Reg::TMR1.TCR.BIT.CMIEB = flag;
}
/// CMFAによる割り込みの認可状況
inline bool getPermissionIntrB(void) {
  return h8mmpsys::H8Reg::TMR1.TCR.BIT.CMIEB;
}
/// TCORBによるコンペアマッチ・インプットキャプチャの発生を示す
inline bool intrruptStatsOVF(void) {
  return h8mmpsys::H8Reg::TMR1.TCSR.BIT.OVF;
}
/// CMFBのリセット
inline void resetIntrFlagOVF(void) {
  h8mmpsys::H8Reg::TMR1.TCSR.BIT.OVF = 0;
}
/// CMFBによる割り込みの設定(true: 許可 false: 禁止)
inline void permitIntrOVF(bool flag) {
  h8mmpsys::H8Reg::TMR1.TCR.BIT.OVIE = flag;
}
/// CMFAによる割り込みの認可状況
inline bool getPermissionIntrOVF(void) {
  return h8mmpsys::H8Reg::TMR1.TCR.BIT.OVIE;
}

/// TCORAを取得する
inline uint8_t getTCORA(void) {
  return h8mmpsys::H8Reg::TMR1.TCORA;
}
/// TCORAに代入する
inline void setTCORA(uint8_t val) {
  h8mmpsys::H8Reg::TMR1.TCORA = val;
}
/// TCORBを取得する
inline uint8_t getTCORB(void) {
  return h8mmpsys::H8Reg::TMR1.TCORB;
}
/// TCORBに代入する
inline void setTCORB(uint8_t val) {
  h8mmpsys::H8Reg::TMR1.TCORB = val;
}
/// クロックソース選択レジスタの値を計算
static constexpr uint8_t calcClockSource(clockSource_t cs) {
  uint8_t val = 0x00;
  switch (cs) {
    case clockSource_t::No_Source:
      val = 0b000;
      break;
    case clockSource_t::Prescaler_8:
      val = 0b001;
      break;
    case clockSource_t::Prescaler_64:
      val = 0b010;
      break;
    case clockSource_t::Prescaler_8192:
      val = 0b011;
      break;
    case clockSource_t::Compare_MatchA:
      val = 0b100;
      break;
    case clockSource_t::External_Raise:
      val = 0b101;
      break;
    case clockSource_t::External_Fall:
      val = 0b110;
      break;
    case clockSource_t::External_Both:
      val = 0b111;
      break;
    default:
      val = 0b000;
      break;
  }
  return val;
}
/// クロックソースの設定
inline void setClockSource(clockSource_t cs) {
  h8mmpsys::H8Reg::TMR1.TCR.BIT.CKS = calcClockSource(cs);
}
/// 現在のクロックソース設定の読み出し
inline clockSource_t getClockSource(void) {
  clockSource_t ret_val;
  switch (h8mmpsys::H8Reg::TMR1.TCR.BIT.CKS) {
    case 0x00:
      ret_val = clockSource_t::No_Source;
      break;
    case 0x01:
      ret_val = clockSource_t::Prescaler_8;
      break;
    case 0x02:
      ret_val = clockSource_t::Prescaler_64;
      break;
    case 0x03:
      ret_val = clockSource_t::Prescaler_8192;
      break;
    case 0x04:
      ret_val = clockSource_t::Compare_MatchA;
      break;
    case 0x05:
      ret_val = clockSource_t::External_Raise;
      break;
    case 0x06:
      ret_val = clockSource_t::External_Fall;
      break;
    case 0x07:
      ret_val = clockSource_t::External_Both;
      break;
    default:
      ret_val = clockSource_t::No_Source;
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
    case counterClearTrigger_t::InputCaptureB:
      val = 0x03;
      break;
    default:
      val = 0x00;
      break;
  }
  return val;
}
/// カウンタクリア要因の設定
inline void setCounterClearCause(counterClearTrigger_t cause) {
  h8mmpsys::H8Reg::TMR1.TCR.BIT.CCLR = calcCounterClearCause(cause);
}
/// 設定中のカウンタクリア要因の取得
inline uint8_t getCounterClearCause(void) {
  counterClearTrigger_t ret_val;
  switch (h8mmpsys::H8Reg::TMR1.TCR.BIT.CCLR) {
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
      ret_val = counterClearTrigger_t::InputCaptureB;
      break;
    default:
      ret_val = counterClearTrigger_t::NeverClear;
      break;
  }
  return ret_val;
}

static constexpr uint8_t calcIOMode(IOMode_t mode) {
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
    default:
      val = 0x00;
      break;
  }
  return val;
}

inline void setIOModeA(IOMode_t mode) {
  h8mmpsys::H8Reg::TMR1.TCSR.BIT.OS = calcIOMode(mode);
}

inline void setIOModeB(IOMode_t mode) {
  h8mmpsys::H8Reg::TMR1.TCSR.BIT.OIS = calcIOMode(mode);
}
/// タイマーカウントをスタート
inline void startTimer(clockSource_t cs) {
  setClockSource(cs);
}
/// タイマーカウントをストップ
inline void stopTimer(void) {
  setClockSource(clockSource_t::No_Source);
}

}  // namespace TMR1
}  // namespace Peripherals
}  // namespace h8mmpsys

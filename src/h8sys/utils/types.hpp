#pragma once

// #include <inttypes.h>
#include <cinttypes>

namespace eommpsys {

using _LONG = uint32_t;
using _WORD = uint16_t;
using _BYTE = uint8_t;

using intrHandler_t = void (*)(void);

/// ビットフィールド
template <typename T, uint8_t L, uint8_t H = L>
struct bitAccess_t {
  volatile T base;

  static constexpr T mask = static_cast<T>(~(static_cast<T>(~0) << (H - L + 1)))
                            << L;

  void operator=(const T val) {
    base = (base & ~mask) | ((val & (mask >> L)) << L);
  }
  operator T() const { return (base & mask) >> L; }
};
/// シングルトン基底クラス
template <class T>
class Singleton {
 public:
  static T& getInstance() { return instance; }

 protected:
  Singleton() = default;

  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;
  Singleton(Singleton&&) = delete;
  Singleton& operator=(Singleton&&) = delete;

 private:
  static T instance;
};

template <class T>
T Singleton<T>::instance;

/// プリスケーラ分周回数
enum clockSource_t {
  No_Source = 0x00,
  Prescaler_1,
  Prescaler_2,
  Prescaler_4,
  Prescaler_8,
  Prescaler_64,
  Prescaler_8192,
  External_Raise,
  External_Fall,
  External_Both,
  External_TCLKA,
  External_TCLKB,
  External_TCLKC,
  External_TCLKD,
  Overflow,
  Compare_MatchA
};
/// 入力クロックエッジ
enum clockEdge_t { Raising = 0x00, Falling, Both };
/// カウンタクリア要因
enum counterClearTrigger_t {
  NeverClear = 0x00,
  CompareMatchA,
  CompareMatchB,
  SyncOther,
  InputCaptureB
};
/// I/Oコントロール
enum IOMode_t {
  InhibitOutput = 0x00,
  LowCompareMatch,
  HighCompareMatch,
  ToggleCompareMatch,
  InputRaisingEdge,
  InputFallingEdge,
  InputBothEdges
};

}  // namespace eommpsys

#pragma once

#include "peripherals/16timer0.hpp"
#include "peripherals/16timer1.hpp"
#include "peripherals/16timer2.hpp"
#include "peripherals/8timer0.hpp"
#include "peripherals/8timer1.hpp"
#include "peripherals/8timer2.hpp"
#include "peripherals/8timer3.hpp"

namespace h8mmpsys {

inline void ENABLE_GLOBAL_INTRRUPT(void) {
  EI;
}
inline void DISABLE_GLOBAL_INTRRUPT(void) {
  DI;
}

}  // namespace h8mmpsys

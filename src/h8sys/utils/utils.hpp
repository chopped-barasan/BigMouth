#include <cinttypes>

namespace h8mmpsys {

inline void sleep(void) {
  asm("sleep");
}

inline void nop(void) {
  asm("nop");
}

inline void set_ccr(unsigned char mask) {
  asm("ldc %0l,ccr" ::"r"(mask));
}

inline unsigned char get_ccr(void) {
  unsigned char value;
  asm("stc ccr,%0l" : "=g"(value) :);
  return (value);
}

constexpr uint64_t CPU_CLOCK = 25000000;

}  // namespace h8mmpsys

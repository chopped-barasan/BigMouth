#include "delay.hpp"

namespace eommpsys {
volatile uint64_t Time::current_time = 0;
TimerManager::TimerBase<uint16_t>* Time::timer = nullptr;
}  // namespace eommpsys

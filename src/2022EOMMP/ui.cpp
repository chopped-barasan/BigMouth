#include "ui.hpp"

namespace eommpsys {
float ui::CeraBuzzer::base_hz = 0.0;
TimerManager::TimerBase<uint16_t>* ui::CeraBuzzer::timer = nullptr;
}  // namespace eommpsys

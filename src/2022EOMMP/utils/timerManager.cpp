#include "timerManager.hpp"

namespace eommpsys {
namespace TimerManager {

void TimerCH0::adaptHandlerA(void) {
  using namespace Peripherals;
  if (this->handler_a != nullptr) {
    Timer0::setIntrHandlerA(this->handler_a);
    Timer0::setGRA(this->compare_a);
    Timer0::permitIntrA(true);
  } else {
    Timer0::permitIntrA(false);
  }
}

void TimerCH0::adaptHandlerB(void) {
  using namespace Peripherals;
  if (this->handler_b != nullptr) {
    Timer0::setIntrHandlerB(this->handler_b);
    Timer0::setGRB(this->compare_b);
    Timer0::permitIntrB(true);
  } else {
    Timer0::permitIntrB(false);
  }
}

void TimerCH0::adaptHandlerOVF(void) {
  using namespace Peripherals;
  if (this->handler_ovf != nullptr) {
    Timer0::setIntrHandlerOVF(this->handler_ovf);
    Timer0::permitIntrOVF(true);
  } else {
    Timer0::permitIntrOVF(false);
  }
}

void TimerCH0::start(void) {
  using namespace Peripherals;
  adaptHandlerA();
  adaptHandlerB();
  adaptHandlerOVF();
  Timer0::setCounterClearCause(this->clear_cause);
  Timer0::setClockEdge(this->clock_edge);
  Timer0::setPrescaler(this->clock_source);
  Timer0::startTimer();
}

void TimerCH0::stop(void) {
  Peripherals::Timer0::stopTimer();
}

void TimerCH1::adaptHandlerA(void) {
  using namespace Peripherals;
  if (this->handler_a != nullptr) {
    Timer1::setIntrHandlerA(this->handler_a);
    Timer1::setGRA(this->compare_a);
    Timer1::permitIntrA(true);
  } else {
    Timer1::permitIntrA(false);
  }
}

void TimerCH1::adaptHandlerB(void) {
  using namespace Peripherals;
  if (this->handler_b != nullptr) {
    Timer1::setIntrHandlerB(this->handler_b);
    Timer1::setGRB(this->compare_b);
    Timer1::permitIntrB(true);
  } else {
    Timer1::permitIntrB(false);
  }
}

void TimerCH1::adaptHandlerOVF(void) {
  using namespace Peripherals;
  if (this->handler_ovf != nullptr) {
    Timer1::setIntrHandlerOVF(this->handler_ovf);
    Timer1::permitIntrOVF(true);
  } else {
    Timer1::permitIntrOVF(false);
  }
}

void TimerCH1::start(void) {
  using namespace Peripherals;
  adaptHandlerA();
  adaptHandlerB();
  adaptHandlerOVF();
  Timer1::setCounterClearCause(this->clear_cause);
  Timer1::setClockEdge(this->clock_edge);
  Timer1::setPrescaler(this->clock_source);
  Timer1::startTimer();
}

void TimerCH1::stop(void) {
  Peripherals::Timer1::stopTimer();
}

void TimerCH2::adaptHandlerA(void) {
  using namespace Peripherals;
  if (this->handler_a != nullptr) {
    Timer2::setIntrHandlerA(this->handler_a);
    Timer2::setGRA(this->compare_a);
    Timer2::permitIntrA(true);
  } else {
    Timer2::permitIntrA(false);
  }
}

void TimerCH2::adaptHandlerB(void) {
  using namespace Peripherals;
  if (this->handler_b != nullptr) {
    Timer2::setIntrHandlerB(this->handler_b);
    Timer2::setGRB(this->compare_b);
    Timer2::permitIntrB(true);
  } else {
    Timer2::permitIntrB(false);
  }
}

void TimerCH2::adaptHandlerOVF(void) {
  using namespace Peripherals;
  if (this->handler_ovf != nullptr) {
    Timer2::setIntrHandlerOVF(this->handler_ovf);
    Timer2::permitIntrOVF(true);
  } else {
    Timer2::permitIntrOVF(false);
  }
}

void TimerCH2::start(void) {
  using namespace Peripherals;
  adaptHandlerA();
  adaptHandlerB();
  adaptHandlerOVF();
  Timer2::setCounterClearCause(this->clear_cause);
  Timer2::setClockEdge(this->clock_edge);
  Timer2::setPrescaler(this->clock_source);
  Timer2::startTimer();
}

void TimerCH2::stop(void) {
  Peripherals::Timer2::stopTimer();
}

void TMR23::adaptHandlerA(void) {
  using namespace Peripherals;
  if (this->handler_a != nullptr) {
    set_cmia2_handler(this->handler_a);
    H8Reg::TMR23.TCORA = this->compare_a;
    TMR2::permitIntrA(true);
  }
}

void TMR23::adaptHandlerB(void) {
  using namespace Peripherals;
  if (this->handler_b != nullptr) {
    set_cmib2_handler(this->handler_b);
    H8Reg::TMR23.TCORB = this->compare_b;
    TMR2::permitIntrB(true);
  }
}

void TMR23::adaptHandlerOVF(void) {
  using namespace Peripherals;
  if (handler_ovf != nullptr) {
    set_tovi2_handler(handler_ovf);
    TMR2::permitIntrOVF(true);
  }
}

void TMR23::start(void) {
  using namespace Peripherals;
  adaptHandlerA();
  adaptHandlerB();
  adaptHandlerOVF();
  TMR2::setCounterClearCause(this->clear_cause);
  TMR3::setCounterClearCause(this->clear_cause);
  TMR2::setClockSource(Overflow);
  TMR3::setClockSource(this->clock_source);
}

void TMR23::stop(void) {
  using namespace Peripherals;
  TMR2::stopTimer();
  TMR3::stopTimer();
}

}  // namespace TimerManager
}  // namespace eommpsys

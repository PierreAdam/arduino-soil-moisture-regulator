#pragma once

#include "State.hpp"

class BootState : public State {
  private:
    int wait = 20;
    int state = 1;
  
  public:
    BootState(StateController&, Hardware&);
    virtual unsigned long loop(unsigned long);
};

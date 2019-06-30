#pragma once

#include "State.hpp"

class RunningState : public State {
  private:
    int motorState = 0;
    bool pause = false;
  
  public:
    RunningState(StateController&, Hardware&);
    virtual unsigned long loop(unsigned long);
    virtual void buttonDoublePressed();
};

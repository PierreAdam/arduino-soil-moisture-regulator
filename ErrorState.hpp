#pragma once

#include "State.hpp"

class ErrorState : public State {
  private:
  
  public:
    ErrorState(StateController&, Hardware&);
    virtual unsigned long loop(unsigned long);
    virtual void buttonPressed();
};

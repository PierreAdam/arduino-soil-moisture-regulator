#pragma once
#include "Hardware.hpp"

class StateController;

class State {
  protected:
    StateController& controller;
    Hardware& hardware;
  
  public:
    State(StateController& controller, Hardware& hardware) :
      controller(controller), hardware(hardware)
    {}
    virtual ~State() {}
    virtual unsigned long loop(unsigned long) = 0;
    virtual void buttonPressed() {}
    virtual void buttonDoublePressed() {}
};

#pragma once
#include <Arduino.h>
#include <HardwareSerial.h>
#include "Hardware.hpp"
#include "State.hpp"

class StateController {
  private:
    Hardware hardware;
    State* currentState;
    unsigned long elapsedTime;
    
  public:
    StateController();
    void setState(State* state);
    void loop();
    void buttonInterrupt();
};

#pragma once

#include "Led.hpp"

class Hardware {
  private:
    Led redLed;
    Led greenLed;
    Led blueLed;
    
  public:
    Hardware();

    Led&  getRedLed();
    Led&  getGreenLed();
    Led&  getBlueLed();

    float getProbeValue();
    int   getButtonState();

    void  setMotorState(int);

    void  update(unsigned long);
};

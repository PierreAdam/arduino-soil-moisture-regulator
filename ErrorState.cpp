#include <Arduino.h>
#include "ErrorState.hpp"
#include "BootState.hpp"
#include "StateController.hpp"

ErrorState::ErrorState(StateController& controller, Hardware& hardware) : 
  State(controller, hardware)
{
  hardware.getRedLed().setState(ON);
  hardware.getGreenLed().setState(OFF);
  hardware.getBlueLed().setState(BLINK);
  hardware.getBlueLed().setBlinkFrequence(150);
  Serial.println("Error State !");
}

unsigned long   ErrorState::loop(unsigned long) {
  return 50;
}

void            ErrorState::buttonPressed() {
  this->controller.setState(new BootState(this->controller, this->hardware));
}

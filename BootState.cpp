#include <Arduino.h>
#include "BootState.hpp"
#include "RunningState.hpp"
#include "ErrorState.hpp"
#include "StateController.hpp"
#include "Config.hpp"

BootState::BootState(StateController& controller, Hardware& hardware) : 
  State(controller, hardware)
{
  hardware.getRedLed().setState(BLINK);
  hardware.getRedLed().setBlinkFrequence(300);
  hardware.getGreenLed().setState(OFF);
  hardware.getBlueLed().setState(OFF);
  Serial.println("Starting Boot");
}

unsigned long   BootState::loop(unsigned long) {
  if (this->state == 1) {
    if (this->wait > 0) {
      this->wait--;
      return 100;
    }
    this->state = 2;
  } else if (this->state == 2) {
    float value = this->hardware.getProbeValue();
    Serial.println(value);
    if (value < SENSOR_ERROR_VALUE) {
      this->controller.setState(new ErrorState(this->controller, this->hardware));
    } else {
      hardware.getRedLed().setState(OFF);
      hardware.getGreenLed().setState(ON);
      this->wait = 10;
      this->state = 3;
    }
  } else if (this->state == 3) {
    if (this->wait > 0) {
      this->wait--;
      return 100;
    }
    this->state = 4;
    Serial.println("Switch to running state !");
    this->controller.setState(new RunningState(this->controller, this->hardware));
  }
  return 100;
}

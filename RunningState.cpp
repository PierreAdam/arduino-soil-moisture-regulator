#include <Arduino.h>
#include "RunningState.hpp"
#include "ErrorState.hpp"
#include "StateController.hpp"
#include "Config.hpp"

RunningState::RunningState(StateController& controller, Hardware& hardware) : 
  State(controller, hardware)
{
  hardware.getRedLed().setState(OFF);
  hardware.getGreenLed().setState(ON);
  hardware.getBlueLed().setState(OFF);
  Serial.println("Running State");
}

unsigned long   RunningState::loop(unsigned long) {
  float value = this->hardware.getProbeValue();
  
  if (value < SENSOR_ERROR_VALUE) {
    this->controller.setState(new ErrorState(this->controller, this->hardware));
    return 200;
  }

  float percent = 100.0 - ((value - SENSOR_MIN_VALUE) * 100) / (SENSOR_MAX_VALUE - SENSOR_MIN_VALUE);
  if (percent > 100.0) {
    percent = 100.0;
  } else if (percent < 0.0) {
    percent = 0.0;
  }

  if (pause) {
    this->hardware.getBlueLed().setState(OFF);
    this->hardware.getRedLed().setState(BLINK);
    this->hardware.getRedLed().setBlinkFrequence(1000);
    this->hardware.setMotorState(LOW);
    return 200;
  } else {
    this->hardware.getRedLed().setState(OFF);
  }

  if (percent < MOTOR_START) {
    this->motorState = HIGH;
  } else if (percent > MOTOR_STOP) {
    this->motorState = LOW;
  }

  if (this->hardware.getButtonState() == LOW) {
    this->hardware.setMotorState(HIGH);
    this->hardware.getBlueLed().setState(ON);
  } else {
    this->hardware.setMotorState(this->motorState);
    if (this->motorState == LOW) {
      this->hardware.getBlueLed().setState(OFF);
    } else if (this->hardware.getBlueLed().getState() != BLINK) {
      this->hardware.getBlueLed().setState(BLINK);
      this->hardware.getBlueLed().setBlinkFrequence(400);
    }
  }

  return 200;
}

void            RunningState::buttonDoublePressed() {
  this->pause = !this->pause;
}

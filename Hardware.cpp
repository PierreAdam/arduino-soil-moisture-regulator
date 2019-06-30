#include <Arduino.h>
#include "Config.hpp"
#include "Hardware.hpp"

Hardware::Hardware():
  redLed(LED_RED_GPIO),
  greenLed(LED_GREEN_GPIO),
  blueLed(LED_BLUE_GPIO)
{
  pinMode(MOTOR_GPIO, OUTPUT);
  pinMode(LED_RED_GPIO, OUTPUT);
  pinMode(LED_GREEN_GPIO, OUTPUT);
  pinMode(LED_BLUE_GPIO, OUTPUT);
  pinMode(BUTTON_GPIO, INPUT_PULLUP);
}

void        Hardware::update(unsigned long delta) {
  this->redLed.update(delta);
  this->greenLed.update(delta);
  this->blueLed.update(delta);
}

Led&        Hardware::getRedLed() {
  return this->redLed;
}

Led&        Hardware::getGreenLed() {
  return this->greenLed;
}

Led&        Hardware::getBlueLed() {
  return this->blueLed;
}

float       Hardware::getProbeValue() {
  float value = 0;
  for (int i = 0; i < SENSOR_READ_REPEAT; i++) {
    value += analogRead(PROBE_GPIO);
  }
  value /= SENSOR_READ_REPEAT;
  return value;
}

int         Hardware::getButtonState() {
  return digitalRead(BUTTON_GPIO);
}

void        Hardware::setMotorState(int state) {
  digitalWrite(MOTOR_GPIO, state);
}

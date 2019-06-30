#include <Arduino.h>
#include "Led.hpp"

Led::Led(int gpio) {
  this->gpio = gpio;
  this->state = OFF;
  this->pinState = LOW;
  this->elapsedTime = 0;
  this->blinkFrequence = 0;
}

void        Led::setState(LedState state) {
  if (state != this->state) {
    this->elapsedTime = 0;
    this->state = state;
  }
}

LedState    Led::getState() {
  return this->state;
}

void        Led::setBlinkFrequence(unsigned long frequence) {
  this->blinkFrequence = frequence;
}

void        Led::update(unsigned long elapsed) {
  switch (this->state) {
    case ON:
      this->pinState = HIGH;
      break;
    case OFF:
      this->pinState = LOW;
      break;
    case BLINK:
      this->elapsedTime += elapsed;
      if (this->elapsedTime >= this->blinkFrequence) {
        this->pinState = !this->pinState;
        if (this->blinkFrequence != 0) {
          this->elapsedTime = this->elapsedTime % this->blinkFrequence;
        } else {
          this->elapsedTime = 0;
        }
      }
      break;
  }
  digitalWrite(this->gpio, this->pinState);
}

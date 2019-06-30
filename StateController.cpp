#include "StateController.hpp"
#include "BootState.hpp"

StateController::StateController() : 
  hardware()
{
  Serial.begin(115200);
  this->elapsedTime = 0;
  this->currentState = new BootState(*this, this->hardware);
}

void      StateController::loop() {
  unsigned long currentTime = millis();
  unsigned long delta = currentTime - this->elapsedTime;
  this->elapsedTime = currentTime;

  unsigned long targetDelay = this->currentState->loop(delta);
  hardware.update(delta);
  unsigned long realDelay = (currentTime + targetDelay) - millis();
  
  delay(realDelay > 0 ? realDelay : 0);
}

void      StateController::setState(State* state) {
  delete this->currentState;
  this->currentState = state;
}

void      StateController::buttonInterrupt() {
  static unsigned long last_interrupt_time = 0;
  static bool hasBeenPressedOnce = false;
  unsigned long interrupt_time = millis();
  
  if (interrupt_time - last_interrupt_time > 200) {
    Serial.println("CATCH PRESS");
    Serial.println(interrupt_time - last_interrupt_time);
    if (interrupt_time - last_interrupt_time < 1400 && hasBeenPressedOnce == true) {
      this->currentState->buttonDoublePressed();
      hasBeenPressedOnce = false;
    } else {
      this->currentState->buttonPressed();
      hasBeenPressedOnce = true;
    }
  }
  last_interrupt_time = interrupt_time;
}

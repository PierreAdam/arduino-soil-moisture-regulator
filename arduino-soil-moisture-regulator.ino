
#include "StateController.hpp"
#include "Config.hpp"

//bool isStopped = true;
//int stopState = HIGH;

StateController* controller;

void setup() {
  controller = new StateController();
  attachInterrupt(digitalPinToInterrupt(BUTTON_GPIO), buttonInterrupt, RISING);
}

void loop() {
  controller->loop();
  
  // put your main code here, to run repeatedly:

  /*
  float value = 0;
  for (int i = 0; i < ANALOG_READ_REPEAT; i++) {
    value += analogRead(PROBE_GPIO);
  }
  value /= ANALOG_READ_REPEAT;
  Serial.println(value);

  int state = digitalRead(STOP_BUTTON);
  if (state == LOW && state != stopState) {
    isStopped = !isStopped;
  }
  stopState = state;
  
  if (!isStopped && value > 2500) {
    digitalWrite(STATUS_LED_GPIO, HIGH);
  } else {
    digitalWrite(STATUS_LED_GPIO, LOW);
  }

  if (isStopped) {
    digitalWrite(STOP_LED_GPIO, HIGH);
  } else {
    digitalWrite(STOP_LED_GPIO, LOW);
  }
  */
}

void buttonInterrupt() {
  controller->buttonInterrupt();
}

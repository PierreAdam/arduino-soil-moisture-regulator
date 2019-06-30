#pragma once

typedef enum LedState {
  ON,
  OFF,
  BLINK
} LedState;

class Led {
  private:
    int gpio;
    LedState state;
    int pinState;
    unsigned long elapsedTime;
    unsigned long blinkFrequence;

  public:
    Led(int);
    void      setState(LedState);
    void      setBlinkFrequence(unsigned long);
    LedState  getState();
    void      update(unsigned long);
};

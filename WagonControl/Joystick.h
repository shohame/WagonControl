// Joystick.h
#ifndef Joystick_h
#define Joystick_h

#include "Arduino.h"

class Joystick
{
  public:
    Joystick(int pinX, int pinY);
    int readX();
    int readY();
  private:
    int _pinX;
    int _pinY;
};

#endif

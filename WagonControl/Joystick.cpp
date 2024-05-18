// Joystick.cpp
#include "Arduino.h"
#include "Joystick.h"

Joystick::Joystick(int pinX, int pinY)
{
  _pinX = pinX;
  _pinY = pinY;
  pinMode(_pinX, INPUT);
  pinMode(_pinY, INPUT);
}

int Joystick::readX()
{
  return analogRead(_pinX);
}

int Joystick::readY()
{
  return analogRead(_pinY);
}

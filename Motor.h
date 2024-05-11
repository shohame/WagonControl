// Motor.h
#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor
{
  public:
    Motor(int pwmPin, int dirPin, int changeDir=0);
    void setSpeed(int speed);
    void setDirection(bool direction);  // true for one direction, false for the other
  private:
    int _pwmPin;
    int _dirPin;
    int _changeDir;
};

#endif

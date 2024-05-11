// Motor.cpp
#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int pwmPin, int dirPin, int changeDir=0)
{
  _pwmPin = pwmPin;
  _dirPin = dirPin;
  _changeDir = changeDir;
  pinMode(_pwmPin, OUTPUT);
  pinMode(_dirPin, OUTPUT);
}

void Motor::setSpeed(int speed)
{
  analogWrite(_pwmPin, speed);
}

void Motor::setDirection(bool direction)
{
  digitalWrite(_dirPin, direction ^ _changeDir);
}

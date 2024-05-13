#include "HardwareSerial.h"
// Motor.cpp
#include "Arduino.h"
#include "Motor.h"
#include "Config.h"

Motor::Motor(void)
{
}


void Motor::Setup(int pwmPin, int dirPin, int changeDir)
{
  if ((pwmPin != 9) && (pwmPin != 10))
  {
    Serial.println("Error pin for motor speed. It must be 9 or 10!!!");
  }
  _pwmPin = pwmPin;
  _dirPin = dirPin;
  _last_speed = 0;
  _changeDir = changeDir;

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(dirPin, OUTPUT);

  TCCR1B = TCCR1B & B11111000 | B00000001; // set timer 1 (pin 9,10) divisor to 1 for PWM frequency of 31372.55 Hz
}

// Speen from -100 to 100 (as percentage)
int Motor::setSpeed(int speed)
{
  int pwm_val; 
  int dir;
  int current_speed = _last_speed;
  if (speed>_last_speed) current_speed+=1;
  else if (speed<_last_speed) current_speed-=1;

  if (current_speed >= 0){
    pwm_val = MOTORS_MIN_PWM_VAL_SPEED + current_speed * (MOTORS_MAX_PWM_VAL_SPEED - MOTORS_MIN_PWM_VAL_SPEED) / 100;
    dir = 0;
  }
  else{
    pwm_val = MOTORS_MIN_PWM_VAL_SPEED - current_speed * (MOTORS_MAX_SPEED_REVERS - MOTORS_MIN_PWM_VAL_SPEED) / 100;
      dir = 1;
  }
  if (current_speed==0) pwm_val = 0;

  digitalWrite(_dirPin, dir ^ _changeDir);
  analogWrite(_pwmPin, pwm_val);
  _last_speed = current_speed;
  return pwm_val * ((1-dir)*2 - 1);
}


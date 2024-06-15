#include <HardwareSerial.h>
#include <Arduino.h>
#include "Motor.h"
#include "Config.h"

Motor motorR;  
Motor motorL;  


Motor::Motor(void)
{
}


void Motor::setup(int pwmPin, int dirPin, int changeDir)
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

  if (speed>0) {
    speed -= speed % SPEED_RESOLUTION;
  } else{
    speed += (-speed) % SPEED_RESOLUTION;

  }

  if (speed>_last_speed) current_speed+=SPEED_RESOLUTION;
  else if (speed<_last_speed) current_speed-=SPEED_RESOLUTION;
  if (current_speed >= 0){
    pwm_val = MOTORS_MIN_PWM_VAL_SPEED + (long)current_speed * (MOTORS_MAX_PWM_VAL_SPEED - MOTORS_MIN_PWM_VAL_SPEED) / SPEED_RANG;
    dir = 0;
  }
  else{
    pwm_val = MOTORS_MIN_PWM_VAL_SPEED - (long)current_speed * (MOTORS_MAX_SPEED_REVERS - MOTORS_MIN_PWM_VAL_SPEED) / SPEED_RANG;
      dir = 1;
  }
  if (current_speed==0) pwm_val = 0;

  // Serial.print(current_speed);  Serial.print(", "); Serial.println(pwm_val);


  digitalWrite(_dirPin, dir ^ _changeDir);
  analogWrite(_pwmPin, pwm_val);
  _last_speed = current_speed;
  return pwm_val * ((1-dir)*2 - 1);
}


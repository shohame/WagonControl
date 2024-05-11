#include <math.h>

#include "Motor.h"
#include "Joystick.h"
#include "Config.h"

#define DEBUG 1



// Motor setup
Motor motorR(MOTOR_R_SPEED_PIN, MOTOR_R_DIR_PIN, MOTOR_R_CHANGE_DIR);  
Motor motorL(MOTOR_L_SPEED_PIN, MOTOR_L_DIR_PIN, MOTOR_L_CHANGE_DIR);  

// Joystick setup
Joystick joystick(A0, A1);

void setup() {
  Serial.begin(9600);
}

void loop() {
  int adu_speed = 0;

  int adu_speed_r = 0;
  int adu_speed_l = 0;

  int pwm_r = 0;
  int pwm_l = 0;
  int dir_r = 0;
  int dir_l = 0;
  int is_reversing = false;
  int j_adu_x = joystick.readX();
  int j_adu_y = joystick.readY();

  if (DEBUG) {
    Serial.print("j_adu_x,y = ");   Serial.print(j_adu_x); Serial.print(", "); Serial.println(j_adu_y);
  }

  j_adu_x = j_adu_x - ADU_MID_VALUE;
  j_adu_y = j_adu_y - ADU_MID_VALUE;

  if (abs(j_adu_x)<ADU_TOLERANS) j_adu_x = 0;
  if (abs(j_adu_y)<ADU_TOLERANS) j_adu_y = 0;

  
  if (j_adu_y < 0) is_reversing = true;

  adu_speed = j_adu_y;

  adu_speed_r = adu_speed + j_adu_x / TURN_SPEED_FACTOR;
  adu_speed_l = adu_speed - j_adu_x / TURN_SPEED_FACTOR;
  
  if (DEBUG) {
    Serial.print("adu_speed_r,l = ");   Serial.print(adu_speed_r); Serial.print(", "); Serial.println(adu_speed_l);
  }

  pwm_r = map(abs(adu_speed_r), ADU_TOLERANS, 512, MOTORS_MIN_SPEED, MOTORS_MAX_SPEED);
  dir_r = (adu_speed_r >= 0) ? 0 : 1;

  pwm_l = map(abs(adu_speed_l), ADU_TOLERANS, 512, MOTORS_MIN_SPEED, MOTORS_MAX_SPEED);
  dir_l = (adu_speed_l >= 0) ? 0 : 1;

  pwm_r = constrain(pwm_r, 0, MOTORS_MAX_SPEED);
  pwm_l = constrain(pwm_l, 0, MOTORS_MAX_SPEED);

  if (is_reversing) {
    pwm_r = pwm_r / REVERS_SPEED_FACTOR;
    pwm_l = pwm_l / REVERS_SPEED_FACTOR;
  }
  motorR.setSpeed(pwm_r);
  motorR.setDirection(dir_r);

  motorL.setSpeed(pwm_l);
  motorL.setDirection(dir_l);
  
  if (DEBUG) {
    Serial.print("pwm_r,l = ");   Serial.print(dir_r); Serial.print(", ");Serial.print(dir_l); Serial.print(", ");Serial.print(pwm_r); Serial.print(", "); Serial.println(pwm_l);
  }
  Serial.print(pwm_r); Serial.print(", "); Serial.println(pwm_l);

  if (DEBUG){
    delay(1000);
  }
  else{
    delay(100);
  }
}

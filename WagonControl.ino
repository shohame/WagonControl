#include <math.h>

#include "Motor.h"
#include "Joystick.h"
#include "Config.h"

#define DEBUG 0


// Motor setup
Motor motorR(MOTOR_R_SPEED_PIN, MOTOR_R_DIR_PIN, MOTOR_R_CHANGE_DIR);  
Motor motorL(MOTOR_L_SPEED_PIN, MOTOR_L_DIR_PIN, MOTOR_L_CHANGE_DIR);  

// Joystick setup
Joystick joystick(A0, A1);

void setup() {
  Serial.begin(9600);
}

int fb_adu_2_s_pwm(int adu)
{
  int s_pwm;
  int s_adu = adu - 511; // forward and backward

    if (abs(s_adu)<ADU_TOLERANS) return 0;

    if (s_adu > 0) 
    {
      s_pwm = map(s_adu, ADU_TOLERANS, 512, 0, MOTORS_MAX_SPEED - MOTORS_MIN_SPEED);
    }
    else 
    {
       s_pwm = -map(-s_adu, ADU_TOLERANS, 512, 0,  MOTORS_MAX_SPEED_REVERS - MOTORS_MIN_SPEED);
    }

  return s_pwm;
}

void lr_adu_2_s_pwm(int adu, int* p_s_pwm_r, int* p_s_pwm_l){

  int s_pwd_r = *p_s_pwm_r;
  int s_pwd_l = *p_s_pwm_l;

  int s_pwm;
  int s_adu = adu - 511; // forward and backward


  if (abs(s_adu)>ADU_TOLERANS){

    if (s_adu > 0) 
    {
      s_pwm = map(s_adu, ADU_TOLERANS, 512, 0, MOTORS_MAX_SPEED - MOTORS_MIN_SPEED);
    }
    else 
    {
      s_pwm = -map(-s_adu, ADU_TOLERANS, 512, 0, MOTORS_MAX_SPEED - MOTORS_MIN_SPEED);
    }
  
    s_pwd_r+= s_pwm / TURN_SPEED_FACTOR;
    s_pwd_l-= s_pwm / TURN_SPEED_FACTOR;
  }
  //  Serial.print(s_pwd_r);Serial.print(", ");Serial.println(s_pwd_l);

  if (s_pwd_r>0) s_pwd_r+=MOTORS_MIN_SPEED;
  if (s_pwd_r<0) s_pwd_r-=MOTORS_MIN_SPEED;
  if (s_pwd_l>0) s_pwd_l+=MOTORS_MIN_SPEED;
  if (s_pwd_l<0) s_pwd_l-=MOTORS_MIN_SPEED;

  *p_s_pwm_r = s_pwd_r;
  *p_s_pwm_l = s_pwd_l;
   
}

void loop() {
  int adu_speed = 0;

  int adu_speed_r = 0;
  int adu_speed_l = 0;

  int s_pwm_r = 0;
  int s_pwm_l = 0;

  int is_reversing = false;

  int j_adu_x = joystick.readX();
  int j_adu_y = joystick.readY();

  if (DEBUG) {
    Serial.print("j_adu_x,y = ");   Serial.print(j_adu_x); Serial.print(", "); Serial.println(j_adu_y);
  }

  s_pwm_r = fb_adu_2_s_pwm(j_adu_y);
  s_pwm_l = s_pwm_r;

  lr_adu_2_s_pwm(j_adu_x, &s_pwm_r, &s_pwm_l);
  
  motorR.setSpeed(s_pwm_r);
  motorL.setSpeed(s_pwm_l);
  
  Serial.print(s_pwm_r); Serial.print(", "); Serial.println(s_pwm_l);
  if (DEBUG){
    delay(1000);
  }
  else{
    delay(100);
  }
}

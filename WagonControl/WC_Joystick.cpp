#include <Arduino.h>
#include <math.h>
#include "Motor.h"
#include "Joystick.h"
#include "Config.h"


// Joystick setup
Joystick joystick(A0, A1);

void wc_joystick_setup() {
}

int fb_adu_2_speed(int adu) {
  int speed; // from -100 to 100
  int s_adu = adu - 511; // forward and backward

    if (abs(s_adu)<ADU_TOLERANCE) return 0;

    if (s_adu > 0) {
      speed = map(s_adu, ADU_TOLERANCE, 512, 0, 100);
    }
    else {
       speed = -map(-s_adu, ADU_TOLERANCE, 512, 0,  100);
    }

  return speed;
}

void lr_adu_2_speed(int adu, int* p_speed_r, int* p_speed_l){

  int speed_r = *p_speed_r;
  int speed_l = *p_speed_l;

  int speed;
  int s_adu = adu - 511; // forward and backward

  if (abs(s_adu)>ADU_TOLERANCE){

    if (s_adu > 0){
      speed = map(s_adu, ADU_TOLERANCE, 512, 0, 100);
    }
    else {
      speed = -map(-s_adu, ADU_TOLERANCE, 512, 0, 100);
    }
  
    speed_r += (speed / TURN_SPEED_FACTOR);
    speed_l -= (speed / TURN_SPEED_FACTOR);
  }
  
  speed_r = constrain(speed_r, -100, 100);
  speed_l = constrain(speed_l, -100, 100);


  *p_speed_r = speed_r;
  *p_speed_l = speed_l;
 }

void wc_joystick_loop() {
  int adu_speed = 0;

  int adu_speed_r = 0;
  int adu_speed_l = 0;

  int speed_r = 0;
  int speed_l = 0;

  int is_reversing = false;

  int j_adu_x = joystick.readX();
  int j_adu_y = joystick.readY();

  if (DEBUG) {
    Serial.print("j_adu_x,y = ");   Serial.print(j_adu_x); Serial.print(", "); Serial.println(j_adu_y);
  }

  speed_r = fb_adu_2_speed(j_adu_y);
  speed_l = speed_r;

  lr_adu_2_speed(j_adu_x, &speed_r, &speed_l);
  
  int pwm_r = motorR.setSpeed(speed_r);
  int pwm_l = motorL.setSpeed(speed_l);

  
  Serial.print(speed_r); Serial.print(", "); Serial.print(speed_l); 
  Serial.print(", "); Serial.print(pwm_r); Serial.print(", "); Serial.println(pwm_l);
  if (DEBUG){
    delay(1000);
  }
  else{
    delay(10);
  }
}

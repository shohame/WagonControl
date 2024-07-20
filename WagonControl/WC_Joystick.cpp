#include <Arduino.h>
#include <math.h>
#include "Joystick.h"
#include "Config.h"
#include "WC_Movement.h"


// Joystick setup
Joystick joystick(JOYSTICK_X_PIN, JOYSTICK_Y_PIN);

void wc_joystick_setup() {
}

int fb_adu_2_speed(int adu) {
  int speed; // from -100 to 100
  int s_adu = adu - 511; // forward and backward

    if (abs(s_adu)<ADU_TOLERANCE) return 0;

    if (s_adu > 0) {
      speed = map(s_adu, ADU_TOLERANCE, 512, 0, SPEED_RANG);
    }
    else {
       speed = -map(-s_adu, ADU_TOLERANCE, 512, 0,  SPEED_RANG);
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
      speed = map(s_adu, ADU_TOLERANCE, 512, 0, SPEED_RANG);
    }
    else {
      speed = -map(-s_adu, ADU_TOLERANCE, 512, 0, SPEED_RANG);
    }
  
    speed_r += (speed / TURN_SPEED_FACTOR);
    speed_l -= (speed / TURN_SPEED_FACTOR);
  }
  
  speed_r = constrain(speed_r, -SPEED_RANG, SPEED_RANG);
  speed_l = constrain(speed_l, -SPEED_RANG, SPEED_RANG);


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
  
  wcMovement.move(speed_r, speed_l);
  
   
  if (DEBUG){
    delay(1000);
  }
  else{
    delay(10);
  }
}

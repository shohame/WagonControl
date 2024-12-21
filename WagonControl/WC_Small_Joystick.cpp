#include <Arduino.h>
#include <math.h>
#include "Config.h"
#include "Small_Joystick.h"
#include "WC_Movement.h"


// Joystick setup
Small_Joystick small_joystick(SMALL_JOYSTICK_PUSH_PIN, 
                              SMALL_JOYSTICK_UP_PIN, 
                              SMALL_JOYSTICK_DOWN_PIN, 
                              SMALL_JOYSTICK_LEFT_PIN, 
                              SMALL_JOYSTICK_RIGHT_PIN);

void wc_small_joystick_setup() {
}




void wc_small_joystick_loop() {
  e_speed e_speed_;
  e_status e_status_;
  int speed_r;
  int speed_l;
 
  small_joystick.update();
  e_speed_ = small_joystick.getSpeed();
  e_status_ = small_joystick.getStatus();

  int speed  =  (e_speed_==enSLOW) ? SMALL_JOYSTICK_SLOW_SPEED : SMALL_JOYSTICK_FAST_SPEED; 

  if (e_status_ == enU){
    speed_r = speed;
    speed_l = speed;
  }
  else if (e_status_ == enD){
    speed_r = -speed;
    speed_l = -speed;
  }
  else if (e_status_ == enL){
    speed_r = speed/2;
    speed_l = -speed/2;
  }
  else if (e_status_ == enR){
    speed_r = -speed/2;
    speed_l = speed/2;
  }
  else if (e_status_ == enUL){
    speed_r = speed;
    speed_l = speed/2;
  }
  else if (e_status_ == enUR){
    speed_r = speed/2;
    speed_l = speed;
  }
  else if (e_status_ == enDL){
    speed_r = -speed;
    speed_l = -speed/2;
  }
  else if (e_status_ == enDR){
    speed_r = -speed/2;
    speed_l = -speed;
  }
  else if (e_status_ == enPush){
    speed_r = 0;
    speed_l = 0;
  }
  else{
    speed_r = 0;
    speed_l = 0;
  }  
  wcMovement.move(speed_r, speed_l); 
}

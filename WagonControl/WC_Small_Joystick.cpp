#include <Arduino.h>
#include <math.h>
#include "Small_Joystick.h"
#include "Config.h"
#include "WC_Movement.h"


// Joystick setup
Small_Joystick small_joystick(SMALL_JOYSTICK_PUSH_PIN, 
                              SMALL_JOYSTICK_UP_PIN, 
                              SMALL_JOYSTICK_DOWN_PIN, 
                              SMALL_JOYSTICK_LEFT_PIN, 
                              SMALL_JOYSTICK_RIGHT_PIN);

void wc_small_joystick_setup() {
}


void wc_joystick_loop() {
  
    delay(SMALL_JOYSTICK_LOOP_DELAY_mS);
  
}

#include <math.h>
#include <Arduino.h>

#include "Motor.h"
#include "WC_Joystick.h"
#include "WC_Bluetooth.h"
#include "Config.h"
#include "UltrasonicSensor.h"
#include "MD_Brake.h"


// Joystick setup

void setup() {
  
  Serial.begin(9600);
  US_sensor.setup(US_TRIG_PIN, US_ECHO_PIN);
  motorR.setup(9, MOTOR_R_DIR_PIN, MOTOR_R_CHANGE_DIR);
  motorL.setup(10, MOTOR_L_DIR_PIN, MOTOR_L_CHANGE_DIR);
  MD_brake.setup(BRAKE_OPEN_PIN, BRAKE_CLOSE_PIN, BRAKE_OPEN_DURATION_mS, BRAKE_CLOSE_DURATION_mS);

  if (WC_CONTROLED_BY == eJOYSTICK){
    wc_joystick_setup();
  }
  else { // (WC_CONTROLED_BY == eBLUETOOTH
    wc_bluetooth_setup();
  }

}

void loop() {
  if (WC_CONTROLED_BY == eJOYSTICK){
    wc_joystick_loop();
  }
  else { // (WC_CONTROLED_BY == eBLUETOOTH
    wc_bluetooth_loop();
  }


}

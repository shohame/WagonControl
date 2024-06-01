#include <math.h>
#include <Arduino.h>

#include "Motor.h"
#include "WC_Joystick.h"
#include "WC_Bluetooth.h"
#include "Config.h"
#include "UltrasonicSensor.h"


// Joystick setup

void setup() {
  Serial.begin(9600);
  US_sensor.setup(US_TRIG_PIN, US_ECHO_PIN);
  motorR.Setup(9, MOTOR_R_DIR_PIN, MOTOR_R_CHANGE_DIR);
  motorL.Setup(10, MOTOR_L_DIR_PIN, MOTOR_L_CHANGE_DIR);
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

#include <math.h>
#include <Arduino.h>

#include "WC_Joystick.h"
#include "WC_Bluetooth.h"
#include "Config.h"
#include "UltrasonicSensor.h"
#include "WC_Movement.h"

// Joystick setup

void setup() {
  
  Serial.begin(9600);
  US_sensor.setup(US_TRIG_PIN, US_ECHO_PIN);
  wcMovement.setup();

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

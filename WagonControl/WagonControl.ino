#include <math.h>
#include <Arduino.h>

#include "WC_Joystick.h"
#include "WC_Small_Joystick.h"
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
  delay(200);
  Serial.println('=============================');
  Serial.print("Version: ");
  Serial.println(__VERSION__);
  Serial.println('=============================');
  delay(200);

}

void loop() {
  if (WC_CONTROLED_BY == eJOYSTICK){
    wc_joystick_loop();
  }
  else if (WC_CONTROLED_BY == eBLUETOOTH){
    wc_bluetooth_loop();
    delay(20);
  }
  else if (WC_CONTROLED_BY == eSMALL_JOYSTICK){
    wc_small_joystick_loop();
     delay(SMALL_JOYSTICK_LOOP_DELAY_mS);
  }
  else if (WC_CONTROLED_BY == eBLUETOOTH_and_SMALL_JOYSTICK){
    
    wc_bluetooth_loop();
    
    if (!wc_bluetooth_is_connected()){
      wc_small_joystick_loop();
    }

    delay(BLUETOOTH_AND_SMALL_JOYSTICK_LOOP_DELAY_mS);
  }
  else{
    Serial.println("Error: WC_CONTROLED_BY not defined");
    delay(1000);
  }

}


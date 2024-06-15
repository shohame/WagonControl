#include <Arduino.h>
#include "Bluetooth.h"
#include "WC_Bluetooth.h"
#include "BT_RC_Control.h"
#include "Config.h"
#include "UltrasonicSensor.h"
#include "WC_Movement.h"

Bluetooth bluetooth;
BT_RC_Control bl_rc_control;
byte speed;


void wc_bluetooth_setup(){
  bluetooth.setup();
  bl_rc_control.setup();
}


void wc_bluetooth_loop(){
  int pwm_r, pwm_l, speed_r, speed_l;

  char dataByte = bluetooth.read();
  
//Serial.println(dataByte);
  bl_rc_control.set_char(dataByte);


  if (bl_rc_control.get_triangular()){
    long range_cm = US_sensor.get_distance();
    US_sensor.start_measurement();
    if (range_cm >= US_MIN_RANG_cm && range_cm <= US_MAX_RANG_cm){

      speed_r = bl_rc_control.get_forward_speed();
      speed_l = bl_rc_control.get_forward_speed();
     }
    else{
      speed_r = 0;
      speed_l = 0;
     }
  }
  else{
    speed_r = bl_rc_control.get_speed_r();
    speed_l = bl_rc_control.get_speed_l();
  }

  wcMovement.move(speed_r, speed_l);

  if (DEBUG){
    delay(1000);
  }
  else{
    delay(20);
  }
}




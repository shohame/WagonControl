#include <Arduino.h>
#include "Bluetooth.h"
#include "WC_Bluetooth.h"
#include "BT_RC_Control.h"
#include "Motor.h"
#include "Config.h"
#include "UltrasonicSensor.h"

Bluetooth bluetooth;
BT_RC_Control bl_rc_control;
byte speed;


void wc_bluetooth_setup(){
  bluetooth.setup();
  bl_rc_control.setup();
}


void wc_bluetooth_loop(){
  int pwm_r;
  int pwm_l;

  char dataByte = bluetooth.read();
  
//Serial.println(dataByte);
  bl_rc_control.set_char(dataByte);


  if (bl_rc_control.get_triangular()){
    long range_cm = US_sensor.get_distance();
    US_sensor.start_measurement();
    if (range_cm >= US_MIN_RANG_cm && range_cm <= US_MAX_RANG_cm){
      pwm_r = motorR.setSpeed(bl_rc_control.get_forward_speed());
      pwm_l = motorL.setSpeed(bl_rc_control.get_forward_speed());
    }
    else{
      pwm_r = motorR.setSpeed(0);
      pwm_l = motorL.setSpeed(0);
    }
  }
  else{
    pwm_r = motorR.setSpeed(bl_rc_control.get_speed_r());
    pwm_l = motorL.setSpeed(bl_rc_control.get_speed_l());

  }
  
  //Serial.print(speed_r); Serial.print(", "); Serial.print(speed_l); Serial.print(", ");
   Serial.print(pwm_r); Serial.print(", "); Serial.println(pwm_l);
  if (DEBUG){
    delay(1000);
  }
  else{
    delay(20);
  }


}




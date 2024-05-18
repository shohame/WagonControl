#include <Arduino.h>
#include "Bluetooth.h"
#include "WC_Bluetooth.h"
#include "BT_RC_Control.h"

Bluetooth bluetooth;
BT_RC_Control bl_rc_control;
byte speed;


void wc_bluetooth_setup(){
  bluetooth.setup();
  bl_rc_control.setup();
}


void wc_bluetooth_loop(){

  char dataByte = read_bt;

  if (dataByte>='0' && dataByte<='9')



  int pwm_r = motorR.setSpeed(bl_rc_control.get_speed_r());
  int pwm_l = motorL.setSpeed(bl_rc_control.get_speed_l());
  
  Serial.print(speed_r); Serial.print(", "); Serial.print(speed_l); 
  Serial.print(", "); Serial.print(pwm_r); Serial.print(", "); Serial.println(pwm_l);
  if (DEBUG){
    delay(1000);
  }
  else{
    delay(10);
  }


}




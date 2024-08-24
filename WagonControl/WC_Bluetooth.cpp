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
int _wc_bluetooth_is_connected = 0;
int current_us_sensor = 0; // 0 = left, 1 = right


void wc_bluetooth_setup(){
  bluetooth.setup();
  bl_rc_control.setup();
}

int wc_bluetooth_is_connected(){
  return _wc_bluetooth_is_connected;
}

void wc_bluetooth_loop(){
  int pwm_r, pwm_l, speed_r, speed_l;

  char dataByte = bluetooth.read();
  
//Serial.println(dataByte);
  bl_rc_control.set_char(dataByte);

  if (!_wc_bluetooth_is_connected){
    if (dataByte == 'S'){
      _wc_bluetooth_is_connected = 1;
    }
    return;
  }

  if (bl_rc_control.get_triangular()){
    int cond_l = 0;
    int cond_r = 0;
    long l_range_cm = US_sensor_l.get_distance();
    long r_range_cm = US_sensor_r.get_distance();

    if (current_us_sensor == 0){
      current_us_sensor = 1;
      US_sensor_r.start_measurement();
    }
    else{
      current_us_sensor = 0;
      US_sensor_l.start_measurement();
    }

    cond_l = (l_range_cm >= US_MIN_RANG_cm && l_range_cm <= US_MAX_RANG_cm);
    cond_r = (r_range_cm >= US_MIN_RANG_cm && r_range_cm <= US_MAX_RANG_cm);

    speed_l = 0;
    speed_r = 0;
    
    if (cond_l && cond_r){
      speed_l = bl_rc_control.get_forward_speed();
      speed_r = bl_rc_control.get_forward_speed();
     }
    else if (cond_l){
      speed_l = bl_rc_control.get_forward_speed();
      speed_r = bl_rc_control.get_forward_speed()/2;
    }
    else if (cond_r){
      speed_l = bl_rc_control.get_forward_speed()/2;
      speed_r = bl_rc_control.get_forward_speed();
    }
    else{
      speed_l = 0;
      speed_r = 0;
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
    
  }
}




#include "HardwareSerial.h"


#include <Arduino.h>
#include "BT_RC_Control.h"
#include "Config.h"

BT_RC_Control::BT_RC_Control(void){

}


void BT_RC_Control::setup()
{
    _speed_level = 0; // 0 - 10
    _red_light = 0;
    _blue_light = 0;
    _speed_r = 0;
    _speed_l = 0;
    _triangular = 0;
    _forward_speed = 0;
    _turn_speed = 0;
    _last_data_millis = millis();
}

void BT_RC_Control::_set_char(char dataByte){


  switch (dataByte){
    case 'S':         // Stop
      _speed_r = 0;
      _speed_l = 0;
      break;
    case 'q':
      _speed_level = 10;        
      break;
    case 'F':         // Forward
      _speed_r = _forward_speed;
      _speed_l = _forward_speed;
      break;
    case 'B':         // Backward
      _speed_r = -_forward_speed;
      _speed_l = -_forward_speed;
      break;
    case 'R':         // Right
      _speed_r = -_turn_speed;
      _speed_l = _turn_speed;
      break;
    case 'L':         // Left
      _speed_r = _turn_speed;
      _speed_l = -_turn_speed;
      break;
    case 'I':       // FR
      _speed_r = _forward_speed - _turn_speed;
      _speed_l = _forward_speed + _turn_speed;
      break;
    case 'G':       // FL
      _speed_r = _forward_speed + _turn_speed;
      _speed_l = _forward_speed - _turn_speed;
      break;
    case 'J':       // BR
      _speed_r = -_forward_speed + _turn_speed;
      _speed_l = -_forward_speed - _turn_speed;
      break;
    case 'H':       // BL
      _speed_r = -_forward_speed - _turn_speed;
      _speed_l = -_forward_speed + _turn_speed;
      break;
    case 'X':
      _triangular = 1;
      break;
    case 'x':
      _triangular = 0;
      break;

    default:{

      if (dataByte>='0' && dataByte<='9'){
        _speed_level = dataByte - '0';
      }

    }   
  } // switch (dataByte){ 
}

void BT_RC_Control::set_char(char dataByte){

  unsigned long current_millis = millis();

  _turn_speed = _forward_speed / TURN_SPEED_FACTOR;

  // If bluetooth dosen't recive anithing for mSEC_OF_BT_IDEL_TO_STOP_CAR: Stop the car! 
  
  if (dataByte == 0){ // No data in buffer
    if ((current_millis - _last_data_millis) > mSEC_OF_BT_IDEL_TO_STOP_CAR){
      _speed_r = 0;
      _speed_l = 0;
      _forward_speed = 0;
    }
    return;
  }

  _last_data_millis = current_millis;

  _set_char(dataByte);

  _forward_speed =  SPEED_RANG * (_speed_level+1) / 12;

}

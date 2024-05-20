

#include <"Arduino.h">
#include "BT_RC_Control.h"


BT_RC_Control::BT_RC_Control(void){

}


void BT_RC_Control::setup()
{
    _speed_level = 0; // 0 - 10
    _red_light = 0;
    _blue_light = 0;
    _speed_r = 0;
    _speed_l = 0;
}

void BT_RC_Control::set_char(char dataByte){

  int forward_speed;
  forward_speed =  MOTORS_MIN_PWM_VAL_SPEED + 
  _speed_level 
MOTORS_MIN_PWM_VAL_SPEED
MOTORS_MAX_PWM_VAL_SPEED
  if (dataByte>='0' && dataByte<='9'){
    _speed_level = dataByte - '0';
  }
  else 
  {
    switch (dataByte){
      case 'S':         // Stop
        _speed_r = 0;
        _speed_l = 0;
        break;
      case 'F':         // Forward
        _speed_r = 0;
        _speed_l = 0;
        break;
      case 'B':         // Backward
        _speed_r = 0;
        _speed_l = 0;
        break;
      case 'R':         // Right
        _speed_r = 0;
        _speed_l = 0;
        break;
      case 'L':         // Left
        _speed_r = 0;
        _speed_l = 0;
        break;
      case 'I':       // FR
        _speed_r = 0;
        _speed_l = 0;
        break;
      case 'G':       // FL
        _speed_r = 0;
        _speed_l = 0;
        break;
      case 'J':       // BR
        _speed_r = 0;
        _speed_l = 0;
        break;
      case 'H':       // BL
        _speed_r = 0;
        _speed_l = 0;
        break;
      case 'q':
        _speed_level = 10;        
        break;
  
      default:
      

    }
  }

}
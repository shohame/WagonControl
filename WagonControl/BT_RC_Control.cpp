

#include <"Arduino.h">
#include "BT_RC_Control.h"


BT_RC_Control::BT_RC_Control(void){

}


void BT_RC_Control::setup()
{
    _speed_factor = 0;
    _red_light = 0;
    _blue_light = 0;
    _speed_r = 0;
    _speed_l = 0;
}

void BT_RC_Control::set_char(){

}
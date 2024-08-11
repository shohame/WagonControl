#include "WC_Movement.h"

WC_Movement wcMovement;

WC_Movement::WC_Movement()
{
}

void WC_Movement::setup()
{
  _motorR.setup(9, MOTOR_R_DIR_PIN, MOTOR_R_CHANGE_DIR);
  _motorL.setup(10, MOTOR_L_DIR_PIN, MOTOR_L_CHANGE_DIR);
  _MD_brake.setup(BRAKE_CLOSE_PIN, BRAKE_CLOSE_DURATION_mS);
}


void WC_Movement::move(int speedR, int speedL){

    int pwm_r, pwm_l;

  
  //Serial.print(speed_r); Serial.print(", "); Serial.print(speed_l); Serial.print(", ");

    if (speedR==0 && speedL==0){
        _MD_brake.close();
        pwm_r = _motorR.setSpeed(0);
        pwm_l = _motorL.setSpeed(0);
    }
    else{
        _MD_brake.open();   
        if (_MD_brake.is_open()){
            pwm_r = _motorR.setSpeed(speedR);
            pwm_l = _motorL.setSpeed(speedL);
        }
    }
    
    Serial.print(pwm_r); Serial.print(", "); Serial.println(pwm_l);

 }


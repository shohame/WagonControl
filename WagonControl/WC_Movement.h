
#ifndef WC_MOVEMENT_H
#define WC_MOVEMENT_H

#include "Config.h"
#include "Arduino.h"
#include "Motor.h"
#include "MD_Brake.h"


class WC_Movement
{
  public:
    WC_Movement();
    void setup();
    void move(int speedR, int speedL);
    void set_is_continuously_forward(int is_continuously_forward);

  private:
    Motor _motorR;
    Motor _motorL;
    MD_Brake _MD_brake;
    int _is_continuously_forward = 0;
};

extern WC_Movement wcMovement;

#endif
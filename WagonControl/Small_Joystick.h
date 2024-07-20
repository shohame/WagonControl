// Joystick.h
#ifndef Small_Joystick_h
#define Small_Joystick_h

#include "Arduino.h"


enum e_status
{
  enPush,
  enU,
  enD,
  enL,
  enR,
  enUL,
  enUR,
  enDL,
  enDR,
  enNONE
};

class Small_Joystick
{
  public:
    Small_Joystick(int pinPush, int pinUp, int pinDown, int pinLeft, int pinRight);

    void update();
    e_status getStatus();
  private:
    e_status _prevStatus = enNONE;
    e_status _status = enNONE;

    int _pinPush;
    int _pinUp;
    int _pinDown;
    int _pinLeft;
    int _pinRight;
};

#endif

// Joystick.h
#ifndef Small_Joystick_h
#define Small_Joystick_h

#include "Arduino.h"
enum e_speed
{
  enSLOW,
  enFAST
};

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
    e_status getStatus() { return _status; }

    e_speed getSpeed() { return _speed; }
  private:
    e_status _prevStatus = enNONE;
    e_status _status = enNONE;
    e_status _get_current_status_aliexp();
    e_status _get_current_status_althen();

    int _pinPush;
    int _pinUp;
    int _pinDown;
    int _pinLeft;
    int _pinRight;
    e_speed _speed = enSLOW;
    unsigned long _tic = 0;
};

#endif

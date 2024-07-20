#include "Arduino.h"
#include "Small_Joystick.h"

Small_Joystick::Small_Joystick(int pinPush, int pinUp, int pinDown, int pinLeft, int pinRight)
{
  _pinPush = pinPush;
  _pinUp = pinUp;
  _pinDown = pinDown;
  _pinLeft = pinLeft;
  _pinRight = pinRight;
  pinMode(_pinUp, INPUT_PULLUP);
  pinMode(_pinDown, INPUT_PULLUP);
  pinMode(_pinLeft, INPUT_PULLUP);
  pinMode(_pinRight, INPUT_PULLUP);
  pinMode(_pinPush, INPUT_PULLUP);
  
}


void Small_Joystick::update()
{
  e_status status = enNONE;
  // "PushPin" goes low when Pushed or pulled to any direction
  if (digitalRead(_pinPush) == LOW) {

    status = enPush;

    if (digitalRead(_pinUp) == LOW) {
      status = enU;
      if (digitalRead(_pinLeft) == LOW) {
        status = enUL;
      }
      else if (digitalRead(_pinRight) == LOW) {
        status = enUR;
      }
    }
    else if (digitalRead(_pinDown) == LOW) {
      status = enD;
      if (digitalRead(_pinLeft) == LOW) {
        status = enDL;
      }
      else if (digitalRead(_pinRight) == LOW) {
        status = enDR;
      }
    }
    else if (digitalRead(_pinLeft) == LOW) {
      status = enL;
    }
    else if (digitalRead(_pinRight) == LOW) {
      status = enR;
    }
  }  
  else {
    status = enNONE;
  }

  if ((_prevStatus == status) && (status == enPush) && (_status == enPush)) {
    _speed = _speed==enSLOW ? enFAST : enSLOW;
  }


  if (_prevStatus == status) {
    _status = status;
  }
  _prevStatus = status;
}


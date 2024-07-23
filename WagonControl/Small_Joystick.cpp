#include "Arduino.h"
#include "Config.h"
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
    if (_status != status) {
      long diff = millis() - _tic;
      if ( (_status == enPush) && (status == enNONE) && (diff > SMALL_JOYSTICK_PUSH_TIME_TO_GO_FROWARD_mS)) {
        _isGoingForward = 1;
      }
      else{
        _isGoingForward = 0;
        _speed = enSLOW;
      }
      if ( (_status == enNONE) && (diff > SMALL_JOYSTICK_IDEL_TIME_TO_RETURN_TO_SLOW_mS) ) {
        _speed = enSLOW;
      }
      _status = status;
      _tic = millis();
    }
  }
  _prevStatus = status;

}


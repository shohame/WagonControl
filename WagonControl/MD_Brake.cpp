#include "HardwareSerial.h"
#include <Arduino.h>
#include "Config.h"
#include "MD_Brake.h"


MD_Brake MD_brake;

MD_Brake::MD_Brake(){
}

void MD_Brake::setup(int openPin, int closePin, int openDuration_mS, int closeDuration_mS){
  _openPin = openPin;
  _closePin = closePin;
  pinMode(_openPin, OUTPUT);
  pinMode(_closePin, OUTPUT);
  _statuse = bClose;
  _time_to_open_ms = openDuration_mS;
  _time_to_close_ms = closeDuration_mS;
  _tic_mS = 0;
  digitalWrite(_openPin, LOW);
  digitalWrite(_closePin, LOW);
}

void MD_Brake::open(){
  if (_statuse == bClose){
    _statuse = bOnOpenProc;
    digitalWrite(_openPin, HIGH);
    _tic_mS = millis();
  }
  else if (_statuse == bOnOpenProc){
    // check if the current time, adjusted by _tic_mS, has passed the target _time_to_open_ms time, 
    // while also handling the wraparound of the millis() function correctly (* 4 is just for fun).
    if ((_time_to_open_ms * 4) < (_time_to_open_ms + _tic_mS - millis())) //( millis() > _time_to_open_ms + _tic_mS)
    {
      _statuse = bOpen;
      digitalWrite(_openPin, LOW);
    }
  }
}

void MD_Brake::close(){
  if (_statuse == bOpen){
    _statuse = bOnCloseProc;
    digitalWrite(_closePin, HIGH);
    _tic_mS = millis();
  }
  else if (_statuse == bOnCloseProc){
    // check if the current time, adjusted by _tic_mS, has passed the target _time_to_close_ms time, 
    // while also handling the wraparound of the millis() function correctly (* 4 is just for fun).
    if ((_time_to_close_ms * 4) < (_time_to_close_ms + _tic_mS - millis())) //( millis() > _time_to_close_ms + _tic_mS)
    {
      _statuse = bClose;
      digitalWrite(_closePin, LOW);
    }
  }
}

char MD_Brake::is_open()
{
  return _statuse == bOpen;
}

char MD_Brake::is_close()
{
  return _statuse == bClose;
}

#include "HardwareSerial.h"
#include <Arduino.h>
#include "Config.h"
#include "MD_Brake.h"


MD_Brake::MD_Brake()
{
}

void MD_Brake::setup(){
  pinMode(_openPin, OUTPUT);
  pinMode(_closePin, OUTPUT);
}



#include <Arduino.h>
#include "Bluetooth.h"
#include "Config.h"
#include <SoftwareSerial.h>

const byte rxPin = BT_RX_PIN;
const byte txPin = BT_TX_PIN;

SoftwareSerial BTSerial(rxPin, txPin); 

Bluetooth::Bluetooth()
{
}

void Bluetooth::setup(){
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  BTSerial.begin(9600); 
}


char Bluetooth::read(){
  char dataByte = 0;
  if (BTSerial.available(){
    dataByte = BTSerial.read();
  }
  return dataByte;
}


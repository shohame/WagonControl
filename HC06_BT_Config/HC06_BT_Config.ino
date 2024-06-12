#include "Arduino.h"
#include <SoftwareSerial.h>

/*
AT command for HC-06:

AT+NAMEOXEN-0001
AT+PIN1234
AT+BAUD4    // 4-9600, 5-19200, 6—38400, 7—57600, 8—115200

*/


const byte rxPin = 5; // connected to TX on BT module
const byte txPin = 4; // connected to RX on BT module

SoftwareSerial BTSerial(rxPin, txPin); 

void setup() {
  // define pin modes for tx, rx:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  BTSerial.begin(9600); //9600, 19200, 38400, 57600, 115200
  Serial.begin(9600);
}

String messageBuffer = "";
String message = "";
char dataByte;

void loop() {

  while(BTSerial.available()) {
    dataByte = BTSerial.read();
    if (dataByte !='S')
    Serial.write(dataByte);
  }
  
  while(Serial.available()){
    dataByte = Serial.read();
    BTSerial.write(dataByte);
  }
  
}
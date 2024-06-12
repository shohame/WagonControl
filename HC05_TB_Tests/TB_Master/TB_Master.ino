// name: BT003
// Adress: 0C:FC:83:1F:38:4F

#include "Arduino.h"
#include <SoftwareSerial.h>

/*
AT command for HC-05:

AT+ORGL   // Reset to defaults
AT+RMAAD  // Clear any paired devices
AT+ROLE=1 // Master mode
AT+RESET  // Need to restart after changing role:
AT+CMODE=1  // Allow connecting to any address:
AT+INQM=0,5,5 // Inquire mode – Standard, stop after 5 devices found, (or) stop searching after 5 seconds:
AT+PSWD=0000 // Set PIN, should be the same as the slave:
AT+INIT // Start SPP profile lib (needed to do any Bluetooth transmitting/receiving):
    Note: If it says Error:(17) then that means it’s already loaded, you can carry on.
AT+INQ // Start searching:


AT+CMODE=0
AT+BIND=0cfc,83,1f384f
AT+LINK=0cfc,83,1f384f
AT+ROLE=1    // set as master
AT+INIT
AT+PIN

AT+ STATE

*/


const byte rxPin = 4; // connected to TX on BT module
const byte txPin = 2; // connected to RX on BT module

SoftwareSerial BTSerial(rxPin, txPin); 

void setup() {
  // define pin modes for tx, rx:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  
  BTSerial.begin(38400); //9600, 19200, 38400, 57600, 115200
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
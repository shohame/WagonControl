#include <SoftwareSerial.h>

const byte rx_btPin = 5; // connected to TX on Blowtooth module
const byte tx_btPin = 4; // connected to RX on Blowtooth module
const byte rx_loraPin = 10; // connected to TX on Lora module
const byte tx_loraPin = 11; // connected to RX on Lora module

SoftwareSerial LoraSerial(rx_loraPin, tx_loraPin);
SoftwareSerial btSerial(rx_btPin, tx_btPin);


void setup() {
  // Initializes the hardware serial port and software serial port at 9600 baud
  Serial.begin(9600);
  while (!Serial);
  
  LoraSerial.begin(9600);
  btSerial.begin(9600);

  // Output the initialization success message to the serial port monitor
  Serial.println("Setup complete.");
}

void loop() {
  DataFromBT_ToLoRa();
}


void DataFromBT_ToLoRa() {
  if (btSerial.available()) {
    char inChar = (char)btSerial.read(); 
    LoraSerial.print(inChar);          
    Serial.print(inChar);              
  }
}


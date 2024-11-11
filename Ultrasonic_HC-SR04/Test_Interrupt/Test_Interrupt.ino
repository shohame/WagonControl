#include "UltrasonicSensor.h"





#define US_ECHO_PIN   2   // must be 2 or 3 for interrupt in UNO 
#define US_TRIG_PIN   7

void setup() {
  Serial.begin(9600);
  US_sensor.setup(US_TRIG_PIN, US_ECHO_PIN);
  Serial.println("Start loop...");
}

void loop() {
  US_sensor.start_measurement();
  Serial.print("Distance: ");  
  Serial.print(US_sensor.get_distance());

  Serial.println(" cm");
  delay(100); 
} 
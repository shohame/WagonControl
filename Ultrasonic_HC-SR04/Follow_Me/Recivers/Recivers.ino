#include "UltrasonicSensor.h"





#define US_ECHO_PIN_L   2   // must be 2 or 3 for interrupt in UNO 
#define US_ECHO_PIN_R   3   // must be 2 or 3 for interrupt in UNO 
#define US_TRIG_PIN   7

void setup() {
  Serial.begin(9600);
  US_sensor.setup(US_TRIG_PIN, US_ECHO_PIN_L, US_ECHO_PIN_R);
  Serial.println("Start loop...");
}

void loop() {
  US_sensor.start_measurement();
 if (0){
  Serial.print(US_sensor._duration_l);  
  Serial.print(", "); 
  Serial.println(US_sensor._duration_r); 
 }else{
   Serial.println(US_sensor.get_diff_duration());
 }
 delay(100); 
} 
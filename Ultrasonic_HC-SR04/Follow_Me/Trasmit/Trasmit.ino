

#define US_TRIG_PIN   7

void setup() {
  Serial.begin(9600);
  Serial.println("Start loop...");
}

void loop() {
  digitalWrite(US_TRIG_PIN, HIGH);
  delayMicroseconds(30);
  digitalWrite(US_TRIG_PIN, LOW);
  delay(20);
} 
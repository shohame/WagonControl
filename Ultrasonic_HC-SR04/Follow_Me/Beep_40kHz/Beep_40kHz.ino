const byte LED = 3;  // Timer 2 "B" output: OC2B

const long frequency = 40000L;  // Hz


void stopPWM() {
  TCCR2A &= ~_BV(COM2B1);  // Disconnect Timer 2 from pin
  digitalWrite(LED, LOW);  // Set pin to LOW
}

void startPWM() {
  TCCR2A |= _BV(COM2B1);  // Reconnect Timer 2 to pin
}


void setup() 
{
  pinMode (LED, OUTPUT);

  TCCR2A = _BV (WGM20) | _BV (WGM21) | _BV (COM2B1); // fast PWM, clear OC2B on compare
  TCCR2B = _BV (WGM22) | _BV (CS21);         // fast PWM, prescaler of 8
  OCR2A =  ((F_CPU / 8) / frequency) - 1;    // zero relative  (49)
  OCR2B = ((OCR2A + 1) / 2) - 1;             // 50% duty cycle (24)
  }  // end of setup

void loop() { 


    startPWM();
    delayMicroseconds(25*8);
    stopPWM();
    delayMicroseconds(10000);



}
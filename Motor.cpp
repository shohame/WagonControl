// Motor.cpp
#include "Arduino.h"
#include "Motor.h"

uint16_t icr = 0xffff;

void setupPWM16() {
  DDRB  |= _BV(PB1) | _BV(PB2);       /* set pins as outputs */
  TCCR1A = _BV(COM1A1) | _BV(COM1B1)  /* non-inverting PWM */
        | _BV(WGM11);                 /* mode 14: fast PWM, TOP=ICR1 */
  TCCR1B = _BV(WGM13) | _BV(WGM12)
        | _BV(CS10);                  /* prescaler 1 */
  ICR1 = icr;                         /* TOP counter value (freeing OCR1A*/

}

/* 16-bit version of analogWrite(). Works only on pins 9 and 10. */
void analogWrite16(uint8_t pin, uint16_t val)
{
  switch (pin) {
    case  9: OCR1A = val; break;
    case 10: OCR1B = val; break;
  }
}
Motor::Motor(int pwmPin, int dirPin, int changeDir=0)
{
  _pwmPin = pwmPin;
  _dirPin = dirPin;
  _changeDir = changeDir;
    // Configure Timer 1 for PWM on pin 9
  TCCR1A |= _BV(COM1A1) | _BV(WGM10); // Non-inverting mode, fast PWM
  TCCR1B |= _BV(WGM12) | _BV(CS10);   // Set prescaler to 1

  // Set TOP value for Timer 1 (16-bit timer)
  ICR1 = 199; // Adjust this value to change PWM frequency

  // Configure Timer 2 for PWM on pin 10
  TCCR2A |= _BV(COM2A1) | _BV(WGM20); // Non-inverting mode, fast PWM
  TCCR2B |= _BV(WGM22) | _BV(CS20);   // Set prescaler to 1

  // Set TOP value for Timer 2 (8-bit timer)
  OCR2A = 199; // Adjust this value to change PWM frequency

  // Set PWM output pins
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  pinMode(_pwmPin, OUTPUT);
  pinMode(_dirPin, OUTPUT);
 // setupPWM16();
}


void Motor::setSpeed(int speed)
{
  if (speed < 0){
    digitalWrite(_dirPin, 1 ^ _changeDir);
  }
  else{ 
    digitalWrite(_dirPin, 0 ^ _changeDir);
  }
  if (_pwmPin==9)
  {
    OCR1A = abs(speed);
  }

 if (_pwmPin==10)
  {
    OCR2A = abs(speed);
  }



}


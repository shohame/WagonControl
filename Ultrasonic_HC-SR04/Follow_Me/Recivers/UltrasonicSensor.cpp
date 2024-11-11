#include "UltrasonicSensor.h"

#include "Arduino.h"

UltrasonicSensor US_sensor;


void echo_interrupt_l() {
      US_sensor._duration_l = micros() - US_sensor._echo_start;
}

void echo_interrupt_r() {
  US_sensor._duration_r = micros() - US_sensor._echo_start;
}

UltrasonicSensor::UltrasonicSensor() {
  _echo_start = 0;
}

void UltrasonicSensor::setup(int trig_pin, int echo_pin_l, int echo_pin_r) {
  _trigPin = trig_pin;
  _echoPin_l = echo_pin_l;
  pinMode(_trigPin, OUTPUT);
  pinMode(_echoPin_l, INPUT);
  attachInterrupt(digitalPinToInterrupt(_echoPin_l), echo_interrupt_l, FALLING);
  attachInterrupt(digitalPinToInterrupt(_echoPin_r), echo_interrupt_r, FALLING);
}

void UltrasonicSensor::start_measurement() {
    if (_done_l && _done_r){
      _diff_duration = _duration_l - _duration_r;
      _done_l = 0;
      _done_r = 0;
      _echo_start = micros();
      digitalWrite(_trigPin, HIGH);
      delayMicroseconds(25);
      digitalWrite(_trigPin, LOW);
    }
    else{
      long duration = micros() - US_sensor._echo_start;
      if (duration>40){
        _done_l = 1;
        _done_r = 1;
      }

    }
  
}

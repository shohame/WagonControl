#include "UltrasonicSensor.h"
#include "Config.h"
#include "Arduino.h"

UltrasonicSensor US_sensor_l;
UltrasonicSensor US_sensor_r;


void echo_interrupt_l() {
  UltrasonicSensor* pUS = &US_sensor_l;
  if (digitalRead(pUS->_echoPin) == HIGH) {
    pUS->_echo_start = micros();
  } else {
      long duration = micros() - pUS->_echo_start;
      pUS->_distance_cm = duration * 0.034 / 2;
      pUS->_measurement_in_progress = false;
  }
}

void echo_interrupt_r() {
  UltrasonicSensor* pUS = &US_sensor_r;
  if (digitalRead(pUS->_echoPin) == HIGH) {
    pUS->_echo_start = micros();
  } else {
      long duration = micros() - pUS->_echo_start;
      pUS->_distance_cm = duration * 0.034 / 2;
      pUS->_measurement_in_progress = false;
  }
}

UltrasonicSensor::UltrasonicSensor() {
  _distance_cm = 0;
  _echo_start = 0;
  _echo_received = false;
  _measurement_in_progress = false;
}

void UltrasonicSensor::setup(int trig_pin, int echo_pin) {
  _trigPin = trig_pin;
  _echoPin = echo_pin;
  pinMode(_trigPin, OUTPUT);
  pinMode(_echoPin, INPUT);
  if (_echoPin == US_ECHO_PIN_L) {
    attachInterrupt(digitalPinToInterrupt(_echoPin), echo_interrupt_l, CHANGE);
  }
  else {
    attachInterrupt(digitalPinToInterrupt(_echoPin), echo_interrupt_r, CHANGE);
  }
}

void UltrasonicSensor::start_measurement() {
  if (!_measurement_in_progress) {
    _measurement_in_progress = true;
    // Clear the trigPin by setting it LOW
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);

    // Send a 10-microsecond pulse to the trigPin
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(20);
    digitalWrite(_trigPin, LOW);
  }
  else { // deals with the case when the echo is not received
    long distance_cm_local;
    long duration = micros() - _echo_start;
    distance_cm_local = duration * 0.034 / 2;
    if (distance_cm_local > 1100) {
      _measurement_in_progress = false;
    }
  }
}






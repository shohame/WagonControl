#include "UltrasonicSensor.h"

#include "Arduino.h"

UltrasonicSensor US_sensor;


void echo_interrupt() {
  if (digitalRead(US_sensor._echoPin) == HIGH) {
    US_sensor._echo_start = micros();
  } else {
      long duration = micros() - US_sensor._echo_start;
      US_sensor._distance_cm = duration * 0.034 / 2;
      US_sensor._measurement_in_progress = false;
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
  attachInterrupt(digitalPinToInterrupt(_echoPin), echo_interrupt, CHANGE);
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
  else {
    long distance_cm_local;
    long duration = micros() - US_sensor._echo_start;
    distance_cm_local = duration * 0.034 / 2;
    if (distance_cm_local > 1100) {
      _measurement_in_progress = false;
    }
  }
}

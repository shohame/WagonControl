#include "UltrasonicSensor.h"
#include "Arduino.h"

UltrasonicSensor US_sensor;


  void echo_interrupt() {
    if (digitalRead(US_sensor.echoPin) == HIGH) {
      US_sensor.echo_start = micros();
    } else {
        long duration = micros() - US_sensor.echo_start;
        US_sensor.distance = duration * 0.034 / 2;
        US_sensor.measurement_in_progress = false;
    }
  }

  UltrasonicSensor::UltrasonicSensor() {
    distance = 0;
    echo_start = 0;
    echo_received = false;
    measurement_in_progress = false;
  }

  void UltrasonicSensor::setup(int trig_pin, int echo_pin) {
    trigPin = trig_pin;
    echoPin = echo_pin;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(echoPin), echo_interrupt, CHANGE);
  }

  void UltrasonicSensor::start_measurement() {
    if (!measurement_in_progress) {
      measurement_in_progress = true;
      // Clear the trigPin by setting it LOW
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);

      // Send a 10-microsecond pulse to the trigPin
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
    }
  }






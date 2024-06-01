#ifndef UltrasonicSensor_h
#define UltrasonicSensor_h



class UltrasonicSensor {
  public:
    volatile long distance;
    unsigned long echo_start;
    bool echo_received;
    bool measurement_in_progress;
    int trigPin;
    int echoPin;

  public:
    UltrasonicSensor() ;

    void setup(int trig_pin, int echo_pin);

    void start_measurement();
    long get_distance() { return distance; }
};


extern   UltrasonicSensor US_sensor;










#endif
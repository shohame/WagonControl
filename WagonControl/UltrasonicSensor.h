#ifndef UltrasonicSensor_h
#define UltrasonicSensor_h



class UltrasonicSensor {
  public: // for interupt needs
    volatile long _distance_cm;
    unsigned long _echo_start;
    bool _echo_received;
    bool _measurement_in_progress;
    int _trigPin;
    int _echoPin;

  public:
    UltrasonicSensor() ;

    void setup(int trig_pin, int echo_pin);

    void start_measurement();
    long get_distance() { return _distance_cm; }
};


extern   UltrasonicSensor US_sensor;










#endif
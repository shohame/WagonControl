#ifndef UltrasonicSensor_h
#define UltrasonicSensor_h



class UltrasonicSensor {
  public: // for interupt needs
    long _duration_l;
    long _duration_r;
    long _diff_duration;
    unsigned long _echo_start;
    bool _echo_received;
    int _trigPin;
    int _echoPin_l;
    int _echoPin_r;
    int _done_l;
    int _done_r;

  public:
    UltrasonicSensor() ;

    void setup(int trig_pin, int echo_pin_l, int echo_pin_r);

    void start_measurement();

    long get_diff_duration() {return _diff_duration;}
};


extern   UltrasonicSensor US_sensor;

#endif
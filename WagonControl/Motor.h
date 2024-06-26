// Motor.h
#ifndef Motor_h
#define Motor_h




class Motor
{
  public:
    Motor(void);
    void setup(int pwmPin, int dirPin, int changeDir); 
    int setSpeed(int speed); // speed < 0 = backward
  private:
    int _pwmPin;
    int _dirPin;
    int _last_speed;
    int _changeDir;

};

extern Motor motorR;  
extern Motor motorL;  

#endif

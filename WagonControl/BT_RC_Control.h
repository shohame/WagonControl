#ifndef BT_RC_Control_h
#define BT_RC_Control_h


/*
  S - Stop
  F - Forward
  B - Backward
  R - Right
  L - Left
  I - FR 
  G - FL
  J - BR
  H - BL

  Ww - B light
  Uu - R light
  Vv - Sound
  Xx - Trungle
  0-9 - q    Speed q is the fastest

*/
class BT_RC_Control
{
  public:
    BT_RC_Control();
    void setup(); 
    void set_char(char dataByte); 
    int get_speed_r() {return _speed_r;}
    int get_speed_l() {return _speed_l;}
    
  private:
    int _speed_level;
    int _red_light;
    int _blue_light;
    int _speed_r;
    int _speed_l;
    unsigned long _last_data_millis;

};

#endif

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

  Ww - B light   (W - on; w - off)
  Uu - R light
  Vv - Sound
  Xx - Triangular
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
    char get_triangular() {return _triangular;}     
    int get_forward_speed() {return _forward_speed;}
    
  private:
    int _speed_level;
    int _red_light;
    int _blue_light;
    int _speed_r;
    int _speed_l;
    char _triangular;
    int _forward_speed;
    int _turn_speed;
    unsigned long _last_data_millis;
    void _set_char(char dataByte); 

};

#endif

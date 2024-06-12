#ifndef MD_Brake_h
#define MD_Brake_h

class MD_Brake
{
  public:
    MD_Brake();
    void setup();
    void open();
    void close();
	char is_open();
	char is_close();
	
  private:
    int _time_to_open_ms;
    int _time_to_close_ms;
    int _openPin;
    int _closePin;
    unsigned long _tic_;
};


#endif

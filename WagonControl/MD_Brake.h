#ifndef MD_Brake_h
#define MD_Brake_h


typedef enum {
    bClose,
    bOpen,
    bOnCloseProc,
    bOnOpenProc
  } eBrakeStat;


class MD_Brake
{
  public:
    MD_Brake();
    void setup(int openPin, int closePin, int openDuration_mS, int closeDuration_mS);
    void open();
    void close();
	char is_open();
	char is_close();
	
  private:
    unsigned long _time_to_open_ms;
    unsigned long _time_to_close_ms;
    int _openPin;
    int _closePin;

    char _statuse;
    unsigned long _tic_mS;
};

extern MD_Brake MD_brake;

#endif



#define __VERSION__ "0.0.8.0" 



// constants: (Do not change!!!)
#define eJOYSTICK 1
#define eBLUETOOTH 2
#define eSMALL_JOYSTICK 3
#define eBLUETOOTH_and_SMALL_JOYSTICK 10
// end of constance 

#define WC_CONTROLED_BY  eBLUETOOTH_and_SMALL_JOYSTICK     // eBLUETOOTH_and_SMALL_JOYSTICK or eJOYSTICK or eBLUETOOTH or eSMALL_JOYSTICK

#define DEBUG 0  // for printing debug information

// ######### Small Joystick configuration: #########
#define SMALL_JOYSTICK_UP_PIN       A2
#define SMALL_JOYSTICK_DOWN_PIN     A3
#define SMALL_JOYSTICK_LEFT_PIN     A4
#define SMALL_JOYSTICK_RIGHT_PIN    A5
#define SMALL_JOYSTICK_PUSH_PIN     8

#define SMALL_JOYSTICK_IDEL_TIME_TO_RETURN_TO_SLOW_mS 5000

#define SMALL_JOYSTICK_PUSH_TIME_TO_GO_FROWARD_mS 2000
#define SMALL_JOYSTICK_GO_FORWARD_SPEED 300 // upto 1000

#define SMALL_JOYSTICK_LOOP_DELAY_mS 50
#define BLUETOOTH_AND_SMALL_JOYSTICK_LOOP_DELAY_mS 20

#define SMALL_JOYSTICK_FAST_SPEED    700   // upto 1000
#define SMALL_JOYSTICK_SLOW_SPEED    400   // upto 1000

// ######### Joystick configuration: #########
#define JOYSTICK_X_PIN A0
#define JOYSTICK_Y_PIN A1


// ######### Brake control configuration: #########
// #define BRAKE_OPEN_PIN 3  // no need an open pin because the brake is a magnet
#define BRAKE_CLOSE_PIN 6

// #define BRAKE_OPEN_DURATION_mS  0
#define BRAKE_CLOSE_DURATION_mS  10000

// ######### Ultrasonic sensor configuration: #########

#define US_ECHO_PIN   2   // must be 2 or 3 for interrupt in UNO 
#define US_TRIG_PIN   7

#define US_MIN_RANG_cm 100
#define US_MAX_RANG_cm 250


// ######### Bluetooth configuration: #########

#define mSEC_OF_BT_IDEL_TO_STOP_CAR     300  // If bluetooth dosen't recive anithing for 300mSEC: Stop the car! 

#define BT_RX_PIN 5 // this pin is connected to TX on BT module 
#define BT_TX_PIN 4 // this pin is connected to RX on BT module 



// ######### Motor configuration: #########
#define SPEED_RANG 1000
#define SPEED_RESOLUTION 5

#define ADU_TOLERANCE 30  	// 512 + 30 = forward; 512 - 30 = backward
#define ADU_MID_VALUE 512

#define STOP_MOTOR_AT_ONCE 0

#define USE_MOTOR_DRIVER 1    // 1 - for the first driver or 0 - for the second driver

#if 1
#define MOTORS_MIN_PWM_VAL_SPEED (70)    // Do not change it
#define MOTORS_MAX_PWM_VAL_SPEED (200)   // 197 = (3.5V / 5) * 256
#define MOTORS_MAX_SPEED_REVERS (200)
#else
#define MOTORS_MIN_PWM_VAL_SPEED (100)    // Do not change it
#define MOTORS_MAX_PWM_VAL_SPEED (160)   // 197 = (3.5V / 5) * 256
#define MOTORS_MAX_SPEED_REVERS (160)
#endif

#define TURN_SPEED_FACTOR 2   // reduce revers speed

#define MOTOR_R_CHANGE_DIR 1    // can be 1 to 0
#define MOTOR_L_CHANGE_DIR 1    // can be 1 or 0

 // #define MOTOR_R_SPEED_PIN 9    // must be 9!!!
#define MOTOR_R_DIR_PIN   11    
// #define MOTOR_L_SPEED_PIN 10    // must be 10 !!!
#define MOTOR_L_DIR_PIN   12    

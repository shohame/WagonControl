

// constants: (Do not change!!!)
#define eJOYSTICK 1
#define eBLUETOOTH 2
// end of constance 


#define DEBUG 0  // for printing debug information

#define BT_RX_PIN 3 // this pin is connected to TX on BT module 
#define BT_TX_PIN 3 // this pin is connected to RX on BT module 

#define WC_CONTROLED_BY  eBLUETOOTH     // eJOYSTICK or eBLUETOOTH

#define ADU_TOLERANCE 30  	// 512 + 30 = forward; 512 - 30 = backward
#define ADU_MID_VALUE 512

#define MOTORS_MIN_PWM_VAL_SPEED (70)    // Do not change it
#define MOTORS_MAX_PWM_VAL_SPEED (200)   // 197 = (3.5V / 5) * 256
#define MOTORS_MAX_SPEED_REVERS (200)

#define TURN_SPEED_FACTOR 2   // reduce revers speed

#define MOTOR_R_CHANGE_DIR 1    // can be 1 to 0
#define MOTOR_L_CHANGE_DIR 1    // can be 1 or 0

 // #define MOTOR_R_SPEED_PIN 9    // must be 9!!!
#define MOTOR_R_DIR_PIN   11    
// #define MOTOR_L_SPEED_PIN 10    // must be 10 !!!
#define MOTOR_L_DIR_PIN   12    

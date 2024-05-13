#define ADU_TOLERANS 30  	// 512 + 30 = forward; 512 - 30 = backward
#define ADU_MID_VALUE 512

#define MOTORS_MIN_SPEED (0*1)
#define MOTORS_MAX_SPEED (100*1)
#define MOTORS_MAX_SPEED_REVERS (100*1)

#define TURN_SPEED_FACTOR 2   // reduce revers speed

#define MOTOR_R_CHANGE_DIR 1    // can be 1 to 0
#define MOTOR_L_CHANGE_DIR 1    // can be 1 or 0

#define MOTOR_R_SPEED_PIN 9    // can be 3, 5, 6, 9, 10 or 11
#define MOTOR_R_DIR_PIN   11    
#define MOTOR_L_SPEED_PIN 10    // can be 3, 5, 6, 9, 10 or 11
#define MOTOR_L_DIR_PIN   12    

/*****************************************************/
/*****************************************************/
/******** Author      : Mahmoud Elbadrawy    *********/
/******** Layer       : HAL                  *********/
/******** Component   : Servo                *********/
/******** version     : 1.0 V                *********/
/******** Date        : 3/5/2023             *********/
/*****************************************************/
/*****************************************************/


#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

/* channel selections*/
#define  SERVO_CHANNEL_A      1
#define  SERVO_CHANNEL_B      2
#define  SERVO_CHANNEL_A_B    3

/* servo angel*/

#define OPEN_0     90
#define OPEN_90    180
#define OPEN_180   0

void Servo_voidInit();
void Servo_void_Operate(u8 Local_u8Angel, u8 Copy_u8Channel);

#endif /* SERVO_INTERFACE_H_ */

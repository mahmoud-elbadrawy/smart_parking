/*****************************************************/
/*****************************************************/
/******** Author      : Mahmoud Elbadrawy    *********/
/******** Layer       : HAL                  *********/
/******** Component   : Servo                *********/
/******** version     : 1.0 V                *********/
/******** Date        : 3/5/2023             *********/
/*****************************************************/
/*****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "Timer1_interface.h"

#include "Servo_interface.h"
#include "Servo_config.h"

void Servo_voidInit()
{
#if SERVO_CHANNEL == SERVO_CHANNEL_A
	DIO_enum_SetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);
#elif SERVO_CHANNEL == SERVO_CHANNEL_B
	DIO_enum_SetPinDirection(DIO_PORTD, DIO_PIN4, DIO_PIN_OUTPUT);
#elif SERVO_CHANNEL == SERVO_CHANNEL_A_B
	DIO_enum_SetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_enum_SetPinDirection(DIO_PORTD, DIO_PIN4, DIO_PIN_OUTPUT);
#endif
	Timer1_void_Init();
	Timer1_void_SetICR1_Reg(19999);
	Timer1_voidSetprescalerby8();
}
void Servo_void_Operate(u8 Local_u8Angel, u8 Copy_u8Channel)
{
	u16 Local_u16OCR1 = ((Local_u8Angel * 1000UL) / 180) + 999;
	Timer1_void_SetOCR1_Reg(Local_u16OCR1, Copy_u8Channel);
}

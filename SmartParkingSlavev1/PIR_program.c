/*****************************************************/
/*****************************************************/
/******** Author      : Mahmoud Elbadrawy    *********/
/******** Layer       : HAL                  *********/
/******** Component   : PIR                  *********/
/******** version     : 1.0 V                *********/
/******** Date        : 24/4/2023            *********/
/*****************************************************/
/*****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"

#include "PIR_interface.h"

void PIR_voidIRInit(u8 Copy_u8PIRPort, u8 Copy_u8PIRPin)
{
	DIO_enum_SetPinDirection(Copy_u8PIRPort, Copy_u8PIRPin, DIO_PIN_INPUT);
}

void PIR_voidGetIRValue(u8 Copy_u8PIRPort, u8 Copy_u8PIRPin, u8* Copy_pu8IRValue)
{
	DIO_enum_GetPinValue(Copy_u8PIRPort, Copy_u8PIRPin, Copy_pu8IRValue);
}

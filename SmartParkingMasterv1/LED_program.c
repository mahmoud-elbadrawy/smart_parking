/*****************************************************/
/*****************************************************/
/******** Author      : Mahmoud Elbadrawy    *********/
/******** Layer       : HAL                  *********/
/******** Component   : LED                  *********/
/******** version     : 1.0 V                *********/
/******** Date        : 24/4/2023            *********/
/*****************************************************/
/*****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"

#include "LED_interface.h"

void LED_voidLEDInit(u8 Copy_u8LEDPort, u8 Copy_u8LEDPin)
{
	DIO_enum_SetPinDirection(Copy_u8LEDPort, Copy_u8LEDPin, DIO_PIN_OUTPUT);
}

void LED_voidTurnOn(u8 Copy_u8LEDPort, u8 Copy_u8LEDPin)
{
	DIO_enum_SetPinValue(Copy_u8LEDPort, Copy_u8LEDPin, DIO_PIN_HIGH);
}


void LED_voidTurnOff(u8 Copy_u8LEDPort, u8 Copy_u8LEDPin)
{
	DIO_enum_SetPinValue(Copy_u8LEDPort, Copy_u8LEDPin, DIO_PIN_LOW);
}

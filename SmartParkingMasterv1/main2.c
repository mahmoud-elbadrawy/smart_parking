/*
 * main.c
 *
 *  Created on: Mar 15, 2024
 *      Author: Administrator
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "Timer0_Interface.h"
#include "GI_Interface.h"
#include "UART_Interface.h"

#include "LCD_Interface.h"
#include "Servo_interface.h"
#include "LED_interface.h"
#include "PIR_interface.h"

void UpdateIRValue(void);
u8 Local_Au8irvalue[2] = {0};

int main()
{
	u8 Local_u8RecieveDate = 0;
	UART_void_Init();
	GI_void_Enable();
	Timer0_void_Init();

	LCD_void_4Bit_Init();
	LCD_void_SetCursor(0, 4);
	LCD_void_4Bit_WriteString((u8*)"Smart Parking");

	LCD_void_SetCursor(1, 0);
	LCD_void_4Bit_WriteString((u8*)"P1: Free");

	LCD_void_SetCursor(2, 0);
	LCD_void_4Bit_WriteString((u8*)"P2: Free");

	LCD_void_SetCursor(3, 0);
	LCD_void_4Bit_WriteString((u8*)"P3: Free");

	Servo_voidInit();
	Servo_void_Operate(OPEN_0,SERVO_CHANNEL_A);

	PIR_voidIRInit(PIR_PORTA, PIR_PIN0);
	PIR_voidIRInit(PIR_PORTA, PIR_PIN1);

	LED_voidLEDInit(LED_PORTA, LED_PIN2);
	LED_voidLEDInit(LED_PORTA, LED_PIN3);

	LED_voidTurnOff(LED_PORTA, LED_PIN2);
	LED_voidTurnOff(LED_PORTA, LED_PIN3);

	while(1)
	{
		/* recieve park details */
		UART_void_RecieveData(&Local_u8RecieveDate);
		if(Local_u8RecieveDate == 'E')
		{
			LCD_void_SetCursor(0, 4);
			LCD_void_4Bit_WriteString((u8*)"Smart Parking");

			LCD_void_SetCursor(1, 0);
			LCD_void_4Bit_WriteString((u8*)"P1: Free");

			LCD_void_SetCursor(2, 0);
			LCD_void_4Bit_WriteString((u8*)"P2: Free");

			LCD_void_SetCursor(3, 0);
			LCD_void_4Bit_WriteString((u8*)"P3: Free");
		}
		else if(Local_u8RecieveDate == 'F')
		{
			LCD_void_SetCursor(0, 4);
			LCD_void_4Bit_WriteString((u8*)"Smart Parking");

			LCD_void_SetCursor(1, 0);
			LCD_void_4Bit_WriteString((u8*)"P1: Full");

			LCD_void_SetCursor(2, 0);
			LCD_void_4Bit_WriteString((u8*)"P2: Full");

			LCD_void_SetCursor(3, 0);
			LCD_void_4Bit_WriteString((u8*)"P3: Full");
		}
		else if(Local_u8RecieveDate == '1')
		{
			LCD_void_SetCursor(0, 4);
			LCD_void_4Bit_WriteString((u8*)"Smart Parking");

			LCD_void_SetCursor(1, 0);
			LCD_void_4Bit_WriteString((u8*)"P1: Full");

			LCD_void_SetCursor(2, 0);
			LCD_void_4Bit_WriteString((u8*)"P2: Free");

			LCD_void_SetCursor(3, 0);
			LCD_void_4Bit_WriteString((u8*)"P3: Free");
		}
		else if(Local_u8RecieveDate == '2')
		{
			LCD_void_SetCursor(0, 4);
			LCD_void_4Bit_WriteString((u8*)"Smart Parking");

			LCD_void_SetCursor(1, 0);
			LCD_void_4Bit_WriteString((u8*)"P1: Free");

			LCD_void_SetCursor(2, 0);
			LCD_void_4Bit_WriteString((u8*)"P2: Full");

			LCD_void_SetCursor(3, 0);
			LCD_void_4Bit_WriteString((u8*)"P3: Free");
		}
		else if(Local_u8RecieveDate == '3')
		{
			LCD_void_SetCursor(0, 4);
			LCD_void_4Bit_WriteString((u8*)"Smart Parking");

			LCD_void_SetCursor(1, 0);
			LCD_void_4Bit_WriteString((u8*)"P1: Free");

			LCD_void_SetCursor(2, 0);
			LCD_void_4Bit_WriteString((u8*)"P2: Free");

			LCD_void_SetCursor(3, 0);
			LCD_void_4Bit_WriteString((u8*)"P3: Full");
		}
		else if(Local_u8RecieveDate == 'A')
		{
			LCD_void_SetCursor(0, 4);
			LCD_void_4Bit_WriteString((u8*)"Smart Parking");

			LCD_void_SetCursor(1, 0);
			LCD_void_4Bit_WriteString((u8*)"P1: Full");

			LCD_void_SetCursor(2, 0);
			LCD_void_4Bit_WriteString((u8*)"P2: Full");

			LCD_void_SetCursor(3, 0);
			LCD_void_4Bit_WriteString((u8*)"P3: Free");
		}
		else if(Local_u8RecieveDate == 'B')
		{
			LCD_void_SetCursor(0, 4);
			LCD_void_4Bit_WriteString((u8*)"Smart Parking");

			LCD_void_SetCursor(1, 0);
			LCD_void_4Bit_WriteString((u8*)"P1: Full");

			LCD_void_SetCursor(2, 0);
			LCD_void_4Bit_WriteString((u8*)"P2: Free");

			LCD_void_SetCursor(3, 0);
			LCD_void_4Bit_WriteString((u8*)"P3: Full");
		}
		else if(Local_u8RecieveDate == 'C')
		{
			LCD_void_SetCursor(0, 4);
			LCD_void_4Bit_WriteString((u8*)"Smart Parking");

			LCD_void_SetCursor(1, 0);
			LCD_void_4Bit_WriteString((u8*)"P1: Free");

			LCD_void_SetCursor(2, 0);
			LCD_void_4Bit_WriteString((u8*)"P2: Full");

			LCD_void_SetCursor(3, 0);
			LCD_void_4Bit_WriteString((u8*)"P3: Full");
		}

		/* sense if there are a car outside the garage */
		PIR_voidGetIRValue(PIR_PORTA, PIR_PIN0, &Local_Au8irvalue[0]);
		/* sense if there are a car inside the garage */
		PIR_voidGetIRValue(PIR_PORTA, PIR_PIN1, &Local_Au8irvalue[1]);

		/* open the gate */
		if ((Local_Au8irvalue[0] == 1) || (Local_Au8irvalue[1] == 1))
		{
			Servo_void_Operate(OPEN_90,SERVO_CHANNEL_A);
			TIMER0_void_AsynchronousStartTimer(1000,UpdateIRValue);
		}

		/* close the gate again */
		if ((Local_Au8irvalue[0] == 0) && (Local_Au8irvalue[1] == 0))
		{
			Servo_void_Operate(OPEN_0,SERVO_CHANNEL_A);
		}
	}

	return 0;
}


void UpdateIRValue(void)
{
	Local_Au8irvalue[0] = 0;
	Local_Au8irvalue[1] = 0;
}

/*
 * main.c
 *
 *  Created on: Mar 15, 2024
 *      Author: Administrator
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "UART_Interface.h"

#include "PIR_interface.h"


int main()
{
	u8 Local_Au8irvalue[3] = {0};
	UART_void_Init();
	PIR_voidIRInit(PIR_PORTA, PIR_PIN0);
	PIR_voidIRInit(PIR_PORTA, PIR_PIN1);
	PIR_voidIRInit(PIR_PORTA, PIR_PIN2);

	while(1)
	{
		/* Check if the garage is empty or not */
		PIR_voidGetIRValue(PIR_PORTA, PIR_PIN0, &Local_Au8irvalue[0]);
		PIR_voidGetIRValue(PIR_PORTA, PIR_PIN1, &Local_Au8irvalue[1]);
		PIR_voidGetIRValue(PIR_PORTA, PIR_PIN2, &Local_Au8irvalue[2]);

		/* all is full */
		if(Local_Au8irvalue[0] && Local_Au8irvalue[1] && Local_Au8irvalue[2])
		{
			UART_void_SendData('F');
		}
		/* all is empty */
		else if((Local_Au8irvalue[0] || Local_Au8irvalue[1] || Local_Au8irvalue[2]) == 0)
		{
			UART_void_SendData('E');
		}
		/* First is full but second and third are empty */
		else if((Local_Au8irvalue[0] == 1) && (Local_Au8irvalue[1] == 0) && (Local_Au8irvalue[2] == 0))
		{
			UART_void_SendData('1');
		}
		/* second is full but first and third are empty */
		else if((Local_Au8irvalue[0] == 0) && (Local_Au8irvalue[1] == 1) && (Local_Au8irvalue[2] == 0))
		{
			UART_void_SendData('2');
		}
		/* third is full but first and second are empty */
		else if((Local_Au8irvalue[0] == 0) && (Local_Au8irvalue[1] == 0) && (Local_Au8irvalue[2] == 1))
		{
			UART_void_SendData('3');
		}
		/* First and second are full but third is empty */
		else if((Local_Au8irvalue[0] == 1) && (Local_Au8irvalue[1] == 1) && (Local_Au8irvalue[2] == 0))
		{
			UART_void_SendData('A');
		}
		/* First and third are full but second is empty */
		else if((Local_Au8irvalue[0] == 1) && (Local_Au8irvalue[1] == 0) && (Local_Au8irvalue[2] == 1))
		{
			UART_void_SendData('B');
		}
		/* Second and third are full but First is empty */
		else if((Local_Au8irvalue[0] == 0) && (Local_Au8irvalue[1] == 1) && (Local_Au8irvalue[2] == 1))
		{
			UART_void_SendData('C');
		}
	}

	return 0;
}


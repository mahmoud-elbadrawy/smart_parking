/*****************************************************/
/*****************************************************/
/******** Author      : Mahmoud Elbadrawy    *********/
/******** Layer       : MCAL                 *********/
/******** Component   : UART                 *********/
/******** version     : 1.0 V                *********/
/******** Date        : 23/7/2023            *********/
/*****************************************************/
/*****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_Interface.h"
#include "UART_Registers.h"
#include "UART_Private.h"
#include "UART_Config.h"

void UART_void_Init(void)
{
	/* UCSRC Reg is byte access so I can't write bit by bit on it */
	u8 Local_u8_UCSRCTemp = 0;

	/* set the this bit to write on UCSRC Reg, cuz it shares the same location with another Reg */
	SET_BIT(Local_u8_UCSRCTemp, UCSRC_URSEL);

	/* Asynchronous mode selection */
	/* Note : we can select Synchronous mode by set this bit, in this case the transmitter/receiver relationship is master to slaves */
	CLR_BIT(Local_u8_UCSRCTemp, UCSRC_UMSEL);

	/* Parity mode selection , it is error checking mechanism */
#if PARITY_MODE == DISABLED
	CLR_BIT(Local_u8_UCSRCTemp, UCSRC_UPM0);
	CLR_BIT(Local_u8_UCSRCTemp, UCSRC_UPM1);

#elif PARITY_MODE == EVEN_PARITY
	CLR_BIT(Local_u8_UCSRCTemp, UCSRC_UPM0);
	SET_BIT(Local_u8_UCSRCTemp, UCSRC_UPM1);

#elif PARITY_MODE == ODD_PARITY
	SET_BIT(Local_u8_UCSRCTemp, UCSRC_UPM0);
	SET_BIT(Local_u8_UCSRCTemp, UCSRC_UPM1);

#endif

	/* Stop bit selection */
#if STOP_BIT == ONE_BIT
	CLR_BIT(Local_u8_UCSRCTemp, UCSRC_USBS);

#elif STOP_BIT == TWO_BIT
	SET_BIT(Local_u8_UCSRCTemp, UCSRC_USBS);

#endif

	/* Data Size selection */
#if DATA_SIZE == FIVE_BIT
	CLR_BIT(Local_u8_UCSRCTemp, UCSRC_UCSZ0);
	CLR_BIT(Local_u8_UCSRCTemp, UCSRC_UCSZ1);
	CLR_BIT(UART_u8_UCSRB, UCSRB_UCSZ2);

#elif DATA_SIZE == SIX_BIT
	SET_BIT(Local_u8_UCSRCTemp, UCSRC_UCSZ0);
	CLR_BIT(Local_u8_UCSRCTemp, UCSRC_UCSZ1);
	CLR_BIT(UART_u8_UCSRB, UCSRB_UCSZ2);

#elif DATA_SIZE == SEVEN_BIT
	CLR_BIT(Local_u8_UCSRCTemp, UCSRC_UCSZ0);
	SET_BIT(Local_u8_UCSRCTemp, UCSRC_UCSZ1);
	CLR_BIT(UART_u8_UCSRB, UCSRB_UCSZ2);

#elif DATA_SIZE == EIGHT_BIT
	SET_BIT(Local_u8_UCSRCTemp, UCSRC_UCSZ0);
	SET_BIT(Local_u8_UCSRCTemp, UCSRC_UCSZ1);
	CLR_BIT(UART_u8_UCSRB, UCSRB_UCSZ2);

#elif DATA_SIZE == NINE_BIT
	SET_BIT(Local_u8_UCSRCTemp, UCSRC_UCSZ0);
	SET_BIT(Local_u8_UCSRCTemp, UCSRC_UCSZ1);
	SET_BIT(UART_u8_UCSRB, UCSRB_UCSZ2);

#endif

	/* assign the value of temporary variable to the register */
	UART_u8_UCSRC = Local_u8_UCSRCTemp;

	/* Set The BaudRate To Be = 9600bps , u can change it if u want*/
	UART_u8_UBRRL = 51;

	/* UART receiver Enable */
	SET_BIT(UART_u8_UCSRB, UCSRB_RXEN);

	/* UART transmitter Enable */
	SET_BIT(UART_u8_UCSRB, UCSRB_TXEN);
}


void UART_void_SendData(u8 A_u8_Data)
{
	/* busy wait */
	while(GET_BIT(UART_u8_UCSRA, UCSRA_UDRE) == 0);
	UART_u8_UDR = A_u8_Data;
}

void UART_void_RecieveData(u8 * A_pu8_Data)
{
	/* busy wait */
	while(GET_BIT(UART_u8_UCSRA, UCSRA_RXC) == 0);
	*A_pu8_Data = UART_u8_UDR;
}

void UART_voidSendString(u8 * A_pu_String)
{
	u8 Local_u8_Counter = 0;
	if (A_pu_String != NULL)
	{
		while(A_pu_String[Local_u8_Counter]!= '\0')
		{
			UART_void_SendData(A_pu_String[Local_u8_Counter]);
			Local_u8_Counter++;
		}
	}
}

void UART_voidSendNumber(s32 A_s32_Number)
{
	u8 reserved[4];
		u8 LastDigit = 0;
		u8 i = 0;
		if(A_s32_Number < 0)
		{
			UART_void_SendData('-');
			A_s32_Number *= -1;
		}
		if (A_s32_Number == 0)
		{
			i = 1;
			reserved[0] = 0;
		}
		while(A_s32_Number != 0)
		{
		LastDigit = A_s32_Number % 10;
		reserved[i] = LastDigit;
		A_s32_Number /= 10;
		i++;
		}
		for(s8 j = (i - 1); j >= 0; j-- )
		{
			UART_void_SendData(reserved[j]+'0');
		}
}

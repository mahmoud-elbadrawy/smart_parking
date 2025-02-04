/*****************************************************/
/*****************************************************/
/******** Author      : Mahmoud Elbadrawy    *********/
/******** Layer       : HAL                  *********/
/******** Component   : LCD_Program          *********/
/******** version     : 1.0 V                *********/
/******** Date        : 3/5/2023             *********/
/*****************************************************/
/*****************************************************/

#include <util\delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"

#include "LCD_Interface.h"
#include "LCD_Config.h"
#include "LCD_Private.h"


void LCD_void_4Bit_Init()
{
	DIO_enum_SetPinDirection(LCD_CONTROL_PORT, LCD_RS, DIO_PIN_OUTPUT);
	DIO_enum_SetPinDirection(LCD_CONTROL_PORT, LCD_RW, DIO_PIN_OUTPUT);
	DIO_enum_SetPinDirection(LCD_CONTROL_PORT, LCD_EN, DIO_PIN_OUTPUT);

	DIO_enum_SetPinDirection(LCD_DATA_PORT, LCD_DATA_D4, DIO_PIN_OUTPUT);
	DIO_enum_SetPinDirection(LCD_DATA_PORT, LCD_DATA_D5, DIO_PIN_OUTPUT);
	DIO_enum_SetPinDirection(LCD_DATA_PORT, LCD_DATA_D6, DIO_PIN_OUTPUT);
	DIO_enum_SetPinDirection(LCD_DATA_PORT, LCD_DATA_D7, DIO_PIN_OUTPUT);
	_delay_ms(40);
	LCD_void_4Bit_WriteCommand(0x33);
	LCD_void_4Bit_WriteCommand(0x32);
	LCD_void_4Bit_WriteCommand(0x28);
	_delay_ms(1);
	LCD_void_4Bit_WriteCommand(0x0E);
	_delay_ms(1);
	LCD_void_4Bit_WriteCommand(0x01);
	_delay_ms(2);
}

void LCD_void_4Bit_WriteCommand(u8 Local_u8_command)
{
	/* For instructions (Set RS pin to LOW) */
	DIO_enum_SetPinValue(LCD_CONTROL_PORT, LCD_RS, DIO_PIN_LOW);
	/* Write operation (Set RW pin to LOW) */
	DIO_enum_SetPinValue(LCD_CONTROL_PORT, LCD_RW, DIO_PIN_LOW);
	/* Write upper nibble on Data port (D4 - D7) */
	DIO_enum_SetPinValue(LCD_CONTROL_PORT,LCD_DATA_D4,GET_BIT(Local_u8_command, 4));
	DIO_enum_SetPinValue(LCD_CONTROL_PORT,LCD_DATA_D5,GET_BIT(Local_u8_command, 5));
	DIO_enum_SetPinValue(LCD_CONTROL_PORT,LCD_DATA_D6,GET_BIT(Local_u8_command, 6));
	DIO_enum_SetPinValue(LCD_CONTROL_PORT,LCD_DATA_D7,GET_BIT(Local_u8_command, 7));
	/* make falling edge on EN pin to enable Writing */
	DIO_enum_SetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_enum_SetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_PIN_LOW);
	/* Write lower nibble on Data port (D4 - D7) */
	DIO_enum_SetPinValue(LCD_CONTROL_PORT,LCD_DATA_D4,GET_BIT(Local_u8_command, 0));
	DIO_enum_SetPinValue(LCD_CONTROL_PORT,LCD_DATA_D5,GET_BIT(Local_u8_command, 1));
	DIO_enum_SetPinValue(LCD_CONTROL_PORT,LCD_DATA_D6,GET_BIT(Local_u8_command, 2));
	DIO_enum_SetPinValue(LCD_CONTROL_PORT,LCD_DATA_D7,GET_BIT(Local_u8_command, 3));
	/* make falling edge on EN pin to enable Writing */
	DIO_enum_SetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_enum_SetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_PIN_LOW);

}

void LCD_void_4Bit_WriteCharacter(u8 Local_u8_Char)
{
	/* For instructions (Set RS pin to LOW) */
	DIO_enum_SetPinValue(LCD_CONTROL_PORT, LCD_RS, DIO_PIN_HIGH);
	/* Write operation (Set RW pin to LOW) */
	DIO_enum_SetPinValue(LCD_CONTROL_PORT, LCD_RW, DIO_PIN_LOW);
	/* Write upper nibble on Data port (D4 - D7) */
	DIO_enum_SetPinValue(LCD_DATA_PORT,LCD_DATA_D4,GET_BIT(Local_u8_Char, 4));
	DIO_enum_SetPinValue(LCD_DATA_PORT,LCD_DATA_D5,GET_BIT(Local_u8_Char, 5));
	DIO_enum_SetPinValue(LCD_DATA_PORT,LCD_DATA_D6,GET_BIT(Local_u8_Char, 6));
	DIO_enum_SetPinValue(LCD_DATA_PORT,LCD_DATA_D7,GET_BIT(Local_u8_Char, 7));
	/* make falling edge on EN pin to enable Writing */
	DIO_enum_SetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_enum_SetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_PIN_LOW);
	/* Write lower nibble on Data port (D4 - D7) */
	DIO_enum_SetPinValue(LCD_DATA_PORT,LCD_DATA_D4,GET_BIT(Local_u8_Char, 0));
	DIO_enum_SetPinValue(LCD_DATA_PORT,LCD_DATA_D5,GET_BIT(Local_u8_Char, 1));
	DIO_enum_SetPinValue(LCD_DATA_PORT,LCD_DATA_D6,GET_BIT(Local_u8_Char, 2));
	DIO_enum_SetPinValue(LCD_DATA_PORT,LCD_DATA_D7,GET_BIT(Local_u8_Char, 3));
	/* make falling edge on EN pin to enable Writing */
	DIO_enum_SetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_enum_SetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_PIN_LOW);

}

void LCD_void_4Bit_WriteString(u8 * Local_u8Ptr_ArrOfChar)
{
	u8 Local_u8_Counter = 0;
	while(Local_u8Ptr_ArrOfChar[Local_u8_Counter] != '\0')
	{
		LCD_void_4Bit_WriteCharacter(Local_u8Ptr_ArrOfChar[Local_u8_Counter]);
		Local_u8_Counter++;
	}
}

void LCD_void_SetCursor(u8 Local_u8_Raw, u8 Local_u8_Col)
{
	u8 Local_u8_Address = 0;
	if(Local_u8_Col < 16)
	{
		switch(Local_u8_Raw)
		{


		case 0:Local_u8_Address = Local_u8_Col;break;

		/* LCD_LINE_2 = LCD_LINE_1 + 0x40  that mean it can be written in second line after 40 locations */
		case 1:Local_u8_Address = Local_u8_Col + 0x40;break;
		case 2:Local_u8_Address = Local_u8_Col + 0x94;break;
		case 3:Local_u8_Address = Local_u8_Col + 0xD4;break;


		default:break;
		}
		/* Set bit number 7 for set DDRAM address command then send the command */
				/* LCD_LINE_1 = 10000000  that mean bit number 7 will be 1 */
		LCD_void_4Bit_WriteCommand(Local_u8_Address | 0x80);
	}
}

void LCD_void_4Bit_WriteCustomCharacter(u8 * Local_u8_Char, u8 Local_u8_CharNumber)
{
	/* calculate the CGRAM Address, each block consist of 8 bytes */
	u8 Local_u8_CGRAM_Address = Local_u8_CharNumber * 8;
	/* to Access CGRAM, Set Bit 6 to one  */
	LCD_void_4Bit_WriteCommand(Local_u8_CGRAM_Address + LCD_CGRAM);
	/*write data in CGRAM. CGRAM has 8 locations. each locations consist of 8 bytes. */
	for(u8 Local_u8_counter = 0; Local_u8_counter<8 ; Local_u8_counter++)
	{
		LCD_void_4Bit_WriteCharacter(Local_u8_Char[Local_u8_counter]);
	}
	// to access DDRAM
	LCD_void_4Bit_WriteCommand(LCD_DDRAM);
	/* Write the custom character,Send its location from 0 to 7*/
	LCD_void_4Bit_WriteCharacter(Local_u8_CharNumber);
}


void LCD_void_8Bit_Init()
{
	DIO_enum_SetPinDirection(LCD_CONTROL_PORT, LCD_RS, DIO_PIN_OUTPUT);
	DIO_enum_SetPinDirection(LCD_CONTROL_PORT, LCD_RW, DIO_PIN_OUTPUT);
	DIO_enum_SetPinDirection(LCD_CONTROL_PORT, LCD_EN, DIO_PIN_OUTPUT);
	DIO_enum_SetPortDirection(LCD_DATA_PORT, DIO_PORT_OUTPUT);
	_delay_ms(40);
	LCD_void_8Bit_WriteCommand(LCD_FUNCTION_SET);
	_delay_ms(1);
	LCD_void_8Bit_WriteCommand(LCD_DISPLAY_ON_OFF_CONTROL);
	_delay_ms(1);
	LCD_void_8Bit_WriteCommand(LCD_DISPLAY_CLEAR);
	_delay_ms(2);
	LCD_void_8Bit_WriteCommand(LCD_ENTRY_MODE_SET);
	_delay_ms(1);

}

void LCD_void_8Bit_WriteCommand(u8 Local_u8_command)
{
	/* For instructions (Set RS pin to LOW) */
	DIO_enum_SetPinValue(LCD_CONTROL_PORT, LCD_RS, DIO_PIN_LOW);
	/* Write operation (Set RW pin to LOW) */
	DIO_enum_SetPinValue(LCD_CONTROL_PORT, LCD_RW, DIO_PIN_LOW);
	/* Write Command on Data port (D0 - D7) */
	DIO_enum_SetPortValue(LCD_DATA_PORT,Local_u8_command);
	/* make falling edge on EN pin to enable Writing */
	DIO_enum_SetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_enum_SetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_PIN_LOW);
	_delay_ms(1);
	DIO_enum_SetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_PIN_HIGH);

}

void LCD_void_8Bit_WriteCharacter(u8 Local_u8_Char)
{
	/* For Data (Set RS pin to High) */
	DIO_enum_SetPinValue(LCD_CONTROL_PORT, LCD_RS, DIO_PIN_HIGH);
	/* Write operation (Set RW pin to LOW) */
	DIO_enum_SetPinValue(LCD_CONTROL_PORT, LCD_RW, DIO_PIN_LOW);
	/* Write Command on Data port (D0 - D7) */
	DIO_enum_SetPortValue(LCD_DATA_PORT,Local_u8_Char);
	/* make falling edge on EN pin to enable Writing */
	DIO_enum_SetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_enum_SetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_PIN_LOW);
	_delay_ms(1);
	DIO_enum_SetPinValue(LCD_CONTROL_PORT, LCD_EN, DIO_PIN_HIGH);
}

void LCD_void_8Bit_WriteString(u8 * Local_u8Ptr_ArrOfChar)
{
	u8 Local_u8_Counter = 0;
	while(Local_u8Ptr_ArrOfChar[Local_u8_Counter] != '\0')
	{
		LCD_void_8Bit_WriteCharacter(Local_u8Ptr_ArrOfChar[Local_u8_Counter]);
		Local_u8_Counter++;
	}
}

void LCD_void_8Bit_WriteCustomCharacter(u8 * Local_u8_Char,  u8 Local_u8_CharNumber)
{
	/* calculate the CGRAM Address, each block consist of 8 bytes */
	u8 Local_u8_CGRAM_Address = Local_u8_CharNumber * 8;
	/* to Access CGRAM, Set Bit 6 to one  */
	LCD_void_8Bit_WriteCommand(Local_u8_CGRAM_Address + LCD_CGRAM);
	/* write data in CGRAM. CGRAM has 8 locations. each locations consist of 8 bytes.*/
	for(u8 Local_u8_counter = 0; Local_u8_counter<8 ; Local_u8_counter++)
	{
		for(u8 Local_u8_counter = 0; Local_u8_counter<8 ; Local_u8_counter++)
		{
			LCD_void_8Bit_WriteCharacter(Local_u8_Char[Local_u8_counter]);
		}

	}
	/* to access DDRAM */
	LCD_void_8Bit_WriteCommand(LCD_DDRAM);
	/* Write the custom character,Send its location from 0 to 7*/
	LCD_void_8Bit_WriteCharacter(Local_u8_CharNumber);
}

void LCD_void_4Bit_Display_int(s16 number)
{
	u8 reserved[4];
	u8 LastDigit = 0;
	u8 i = 0;
	if(number < 0)
	{
		LCD_void_4Bit_WriteCharacter('-');
		number *= -1;
	}
	if (number == 0)
	{
		i = 1;
		reserved[0] = 0;
	}
	while(number != 0)
	{
	LastDigit = number % 10;
	reserved[i] = LastDigit;
	number /= 10;
	i++;
	}
	for(s8 j = (i - 1); j >= 0; j-- )
	{
		LCD_void_4Bit_WriteCharacter(reserved[j]+'0');
	}
}

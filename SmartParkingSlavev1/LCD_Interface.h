/*****************************************************/
/*****************************************************/
/******** Author      : Mahmoud Elbadrawy    *********/
/******** Layer       : HAL                  *********/
/******** Component   : LCD_Interface        *********/
/******** version     : 1.0 V                *********/
/******** Date        : 3/5/2023             *********/
/*****************************************************/
/*****************************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/* macros for LCD port */
#define LCD_PORTA 0
#define LCD_PORTB 1
#define LCD_PORTC 2
#define LCD_PORTD 3

/* macros for LCD pin */
#define LCD_PIN0	0
#define LCD_PIN1	1
#define LCD_PIN2	2
#define LCD_PIN3	3
#define LCD_PIN4	4
#define LCD_PIN5	5
#define LCD_PIN6	6
#define LCD_PIN7	7

/* macros for some instructions */
#define LCD_FUNCTION_SET               0b00111000
#define LCD_DISPLAY_ON_OFF_CONTROL     0b00001111
#define LCD_DISPLAY_CLEAR              0b00000001
#define LCD_ENTRY_MODE_SET             0b00000110


/* set CGRAM Address in Address counter */
#define LCD_CGRAM			64
/* set DDRAM Address in Address counter */
#define LCD_DDRAM			128

void LCD_void_SetCursor(u8 Local_u8_Raw, u8 Local_u8_Col);
/* prototypes of functions for LCD 4 bit mode  */
void LCD_void_4Bit_Init();
void LCD_void_4Bit_WriteCharacter(u8 Local_u8_Char);
void LCD_void_4Bit_WriteCommand(u8 Local_u8_command);
void LCD_void_4Bit_WriteString(u8 * Local_u8Ptr_ArrOfChar);
void LCD_void_4Bit_WriteCustomCharacter(u8 * Local_u8_Char, u8 Local_u8_CharNumber);
void LCD_void_4Bit_Display_int(s16 number);
/* prototypes of functions for LCD 8 bit mode  */
void LCD_void_8Bit_Init();
void LCD_void_8Bit_WriteCommand(u8 Local_u8_command);
void LCD_void_8Bit_WriteCharacter(u8 Local_u8_Char);
void LCD_void_8Bit_WriteString(u8 * Local_u8Ptr_ArrOfChar);
void LCD_void_8Bit_WriteCustomCharacter(u8 * Local_u8_Char,  u8 Local_u8_CharNumber);
#endif /* LCD_INTERFACE_H_ */

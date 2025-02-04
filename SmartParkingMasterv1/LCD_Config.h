/*****************************************************/
/*****************************************************/
/******** Author      : Mahmoud Elbadrawy    *********/
/******** Layer       : HAL                  *********/
/******** Component   : LCD_Configuration    *********/
/******** version     : 1.0 V                *********/
/******** Date        : 3/5/2023             *********/
/*****************************************************/
/*****************************************************/

/* file guard, the file will be called one time in .c      */
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_CONTROL_PORT    LCD_PORTC
#define LCD_RS		        LCD_PIN0
#define LCD_RW		        LCD_PIN1
#define LCD_EN		        LCD_PIN2

#define LCD_DATA_PORT		LCD_PORTC
/* for LCD 4 bit mode */
#define LCD_DATA_D4     LCD_PIN4
#define LCD_DATA_D5     LCD_PIN5
#define LCD_DATA_D6     LCD_PIN6
#define LCD_DATA_D7     LCD_PIN7

#endif /* LCD_CONFIG_H_ */

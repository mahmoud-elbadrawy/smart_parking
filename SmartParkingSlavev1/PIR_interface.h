/*****************************************************/
/*****************************************************/
/******** Author      : Mahmoud Elbadrawy    *********/
/******** Layer       : HAL                  *********/
/******** Component   : PIR                  *********/
/******** version     : 1.0 V                *********/
/******** Date        : 24/4/2023            *********/
/*****************************************************/
/*****************************************************/


#ifndef PIR_INTERFACE_H_
#define PIR_INTERFACE_H_

/*macros for PIR Ports*/
#define PIR_PORTA	0
#define PIR_PORTB	1
#define PIR_PORTC	2
#define PIR_PORTD	3

/*macros for PIR pins*/
#define PIR_PIN0	0
#define PIR_PIN1	1
#define PIR_PIN2	2
#define PIR_PIN3	3
#define PIR_PIN4	4
#define PIR_PIN5	5
#define PIR_PIN6	6
#define PIR_PIN7	7

void PIR_voidIRInit(u8 Copy_u8PIRPort, u8 Copy_u8PIRPin);
void PIR_voidGetIRValue(u8 Copy_u8PIRPort, u8 Copy_u8PIRPin, u8* Copy_pu8IRValue);

#endif /* PIR_INTERFACE_H_ */

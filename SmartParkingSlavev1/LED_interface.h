/*****************************************************/
/*****************************************************/
/******** Author      : Mahmoud Elbadrawy    *********/
/******** Layer       : HAL                  *********/
/******** Component   : LED                  *********/
/******** version     : 1.0 V                *********/
/******** Date        : 24/4/2023            *********/
/*****************************************************/
/*****************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


/*macros for LED Ports*/
#define LED_PORTA	0
#define LED_PORTB	1
#define LED_PORTC	2
#define LED_PORTD	3

/*macros for LED pins*/
#define LED_PIN0	0
#define LED_PIN1	1
#define LED_PIN2	2
#define LED_PIN3	3
#define LED_PIN4	4
#define LED_PIN5	5
#define LED_PIN6	6
#define LED_PIN7	7

void LED_voidLEDInit(u8 Copy_u8LEDPort, u8 Copy_u8LEDPin);
void LED_voidTurnOn(u8 Copy_u8LEDPort, u8 Copy_u8LEDPin);
void LED_voidTurnOff(u8 Copy_u8LEDPort, u8 Copy_u8LEDPin);

#endif /* LED_INTERFACE_H_ */

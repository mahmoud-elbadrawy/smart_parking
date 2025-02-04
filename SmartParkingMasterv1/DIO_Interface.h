/*****************************************************/
/*****************************************************/
/******** Author      : Mahmoud Elbadrawy    *********/
/******** Layer       : MCAL                 *********/
/******** Component   : DIO_Interface        *********/
/******** version     : 1.0 V                *********/
/******** Date        : 24/4/2023            *********/
/*****************************************************/
/*****************************************************/

/* file guard, the file will be called one time in c.   */
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*macros for DIO Ports*/
#define DIO_PORTA	0
#define DIO_PORTB	1
#define DIO_PORTC	2
#define DIO_PORTD	3

/*macros for DIO pins*/
#define DIO_PIN0	0
#define DIO_PIN1	1
#define DIO_PIN2	2
#define DIO_PIN3	3
#define DIO_PIN4	4
#define DIO_PIN5	5
#define DIO_PIN6	6
#define DIO_PIN7	7

/*macros for DIO Directions*/
#define DIO_PIN_INPUT	 0
#define DIO_PIN_OUTPUT	 1
#define DIO_PORT_INPUT   0x00
#define DIO_PORT_OUTPUT  0xff

/*macros for DIO Values*/
#define DIO_PIN_LOW		0
#define DIO_PIN_HIGH	1
#define DIO_PORT_LOW    0x00
#define DIO_PORT_HIGH   0xff

typedef enum
{
	DIO_PIN_NUM_INCORRECT,
	DIO_PORT_NUM_INCORRECT,
	DIO_DIR_TYPE_INCORRECT,
	DIO_VAL_TYPE_INCORRECT,
	DIO_NOK,
	DIO_OK
}DIO_Errors;

/* prototype of function to configure DIO */
void DIO_void_Init(void);

/* prototypes of pins functions */
DIO_Errors DIO_enum_SetPinDirection(u8 Local_u8_Port, u8 Local_u8_Pin, u8 Local_u8_Direction);

DIO_Errors DIO_enum_SetPinValue(u8 Local_u8_Port, u8 Local_u8_Pin, u8 Local_u8_Value);

DIO_Errors DIO_enum_TogglePin(u8 Local_u8_Port, u8 Local_u8_Pin);

DIO_Errors DIO_enum_GetPinValue(u8 Local_u8_Port, u8 Local_u8_Pin, u8 * Local_u8Ptr_PinValue);

/* prototypes of ports functions */
DIO_Errors DIO_enum_SetPortDirection(u8 Local_u8_Port, u8 Local_u8_Direction);

DIO_Errors DIO_enum_SetPortValue(u8 Local_u8_Port, u8 Local_u8_Value);

DIO_Errors DIO_enum_TogglePort(u8 Local_u8_Port);

DIO_Errors DIO_enum_GetPortValue(u8 Local_u8_Port,u8 * Local_u8Ptr_PortValue);


#endif /* MCAL_DIO_DIO_INTERFACE_H_ */

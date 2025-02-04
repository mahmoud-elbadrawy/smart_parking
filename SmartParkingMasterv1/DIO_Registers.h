/*****************************************************/
/*****************************************************/
/******** Author      : Mahmoud Elbadrawy    *********/
/******** Layer       : MCAL                 *********/
/******** Component   : DIO_Registers        *********/
/******** version     : 1.0 V                *********/
/******** Date        : 10/4/2023            *********/
/*****************************************************/
/*****************************************************/


/* file guard, the file will be called one time in .c      */
#ifndef DIO_REGISTERS_H_
#define DIO_REGISTERS_H_

#define HWREG8(X)        *((volatile u8*)(X))

/* macros for DIO PORTA registers */
#define DIO_PORTA_u8_REG	     HWREG8(0x3B)
#define DIO_DDRA_u8_REG	         HWREG8(0x3A)
#define DIO_PINA_u8_REG		     HWREG8(0x39)

/* macros for DIO PORTB registers */
#define DIO_PORTB_u8_REG	     HWREG8(0x38)
#define DIO_DDRB_u8_REG		     HWREG8(0x37)
#define DIO_PINB_u8_REG		     HWREG8(0x36)

/* macros for DIO PORTC registers */
#define DIO_PORTC_u8_REG	     HWREG8(0x35)
#define DIO_DDRC_u8_REG		     HWREG8(0x34)
#define DIO_PINC_u8_REG		     HWREG8(0x33)

/* macros for DIO PORTD registers */
#define DIO_PORTD_u8_REG	     HWREG8(0x32)
#define DIO_DDRD_u8_REG		     HWREG8(0x31)
#define DIO_PIND_u8_REG		     HWREG8(0x30)

#endif

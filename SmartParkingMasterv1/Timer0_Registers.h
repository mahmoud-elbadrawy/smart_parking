/*****************************************************/
/*****************************************************/
/******** Author      : Mahmoud Elbadrawy    *********/
/******** Layer       : MCAL                 *********/
/******** Component   : Timer0               *********/
/******** version     : 1.0 V                *********/
/******** Date        : 12/7/2023            *********/
/*****************************************************/
/*****************************************************/


#ifndef TIMER0_REGISTERS_H_
#define TIMER0_REGISTERS_H_
#define HWREG8(X)               *((volatile u8*)(X))
#define TIMER_TCCR0_u8_REG      HWREG8(0x53)
#define TCCR0_FOC0                   7
#define TCCR0_WGM00                  6
#define TCCR0_COM01                  5
#define TCCR0_COM00                  4
#define TCCR0_WGM01                  3
#define TCCR0_CS02                   2
#define TCCR0_CS01                   1
#define TCCR0_CS00                   0

#define TIMER_TCNT0_u8_REG      HWREG8(0x52)
#define TIMER_OCR0_u8_REG       HWREG8(0x5C)
#define TIMER_TIMSK_u8_REG      HWREG8(0x59)
#define TIMSK_OCIE0                  1
#define TIMSK_TOIE0                  0
#define TIMER_TIFR_u8_REG      HWREG8(0x58)
#define TIFR_OCF0                   1
#define TIFR_TOV0                   0

#endif /* TIMER0_REGISTERS_H_ */

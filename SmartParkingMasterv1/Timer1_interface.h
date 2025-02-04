/********************************************************************************
 * Author:          Mahmoud Elbadrawy
 * Creation Data:   14 Sep, 2023
 * Version:         v1.0
 * SWC :            Timer_1
 * Layer:           MCAL
 ********************************************************************************/
/********************************************************************************
 * Version      Date                  Author                  Description
 * v1.0         14 Sep, 2023     Mahmoud Elbadrawy          Initial Creation
 *********************************************************************************/

#ifndef TIMER1_INTERFACE_H
#define TIMER1_INTERFACE_H

#define TIMER1_CHANAL_A     1
#define TIMER1_CHANAL_B     2
#define TIMER1_CHANAL_A_B   3

/* Timer1 intit for Fast PWM Mode , Mode 14 */
void Timer1_void_Init();

/* Function to Set Duty cycle */
void Timer1_void_SetPWM(f32 Copy_u32_DutyCycle, u8 Copy_u8_Chanal);

/* Function to Set Duty cycle to Chanal A */
void Timer1_void_SetPWMChanal_A(f32 Copy_u32_DutyCycle);

/* Function to Set Duty cycle to Chanal A */
void Timer1_void_SetPWMChanal_B(f32 Copy_u32_DutyCycle);


/* Function to Set the maximum counts of timer */
void Timer1_void_SetICR1_Reg(u16 Copy_u16_Value);

void Timer1_void_SetOCR1_Reg(u16 Copy_u16_Value, u8 Copy_u8_Chanal);

void Timer1_voidSetprescalerby8();
#endif

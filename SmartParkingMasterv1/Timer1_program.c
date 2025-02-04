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

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Timer1_interface.h"
#include "Timer1_registers.h"
#include "Timer1_private.h"
#include "Timer1_config.h"


void Timer1_void_Init()
{
	/* Select Fast PWM Mode, Mode 14 */
	CLR_BIT(TIMER_u8_TCCR1A_REG, TCCR1A_WGM10);
	SET_BIT(TIMER_u8_TCCR1A_REG, TCCR1A_WGM11);
	SET_BIT(TIMER_u8_TCCR1B_REG, TCCR1B_WGM12);
	SET_BIT(TIMER_u8_TCCR1B_REG, TCCR1B_WGM13);

	/* Non inverting mode configuration */
#if PWM_OUTPUT == TIMER1_CHANAL_A
	CLR_BIT(TIMER_u8_TCCR1A_REG,TCCR1A_COM1A0);
	SET_BIT(TIMER_u8_TCCR1A_REG,TCCR1A_COM1A1);
#elif PWM_OUTPUT == TIMER1_CHANAL_B    
	CLR_BIT(TIMER_u8_TCCR1A_REG,TCCR1A_COM1B0);
	SET_BIT(TIMER_u8_TCCR1A_REG,TCCR1A_COM1B1);
#elif PWM_OUTPUT == TIMER1_CHANAL_A_B
	CLR_BIT(TIMER_u8_TCCR1A_REG,TCCR1A_COM1A0);
	SET_BIT(TIMER_u8_TCCR1A_REG,TCCR1A_COM1A1);
	CLR_BIT(TIMER_u8_TCCR1A_REG,TCCR1A_COM1B0);
	SET_BIT(TIMER_u8_TCCR1A_REG,TCCR1A_COM1B1);
#endif    
}

void Timer1_voidSetprescalerby8()
{
	/* Set prescaler to divide by 8 */
	CLR_BIT(TIMER_u8_TCCR1B_REG,TCCR1B_CS10);
	SET_BIT(TIMER_u8_TCCR1B_REG,TCCR1B_CS11);
	CLR_BIT(TIMER_u8_TCCR1B_REG,TCCR1B_CS12);
}
void Timer1_void_SetPWM(f32 Copy_u32_DutyCycle, u8 Copy_u8_Chanal)
{
	switch(Copy_u8_Chanal)
	{
	case TIMER1_CHANAL_A:
		TIMER_u16_OCR1A_REG = (u16)(((f32)Copy_u32_DutyCycle / 100.0) * TIMER_u16_ICR1_REG);
		break;

	case TIMER1_CHANAL_B:
		TIMER_u16_OCR1B_REG = (u16)(((f32)Copy_u32_DutyCycle / 100.0) * TIMER_u16_ICR1_REG);
		break;

	case TIMER1_CHANAL_A_B:
		TIMER_u16_OCR1A_REG = (u16)(((f32)Copy_u32_DutyCycle / 100.0) * TIMER_u16_ICR1_REG);
		TIMER_u16_OCR1B_REG = (u16)(((f32)Copy_u32_DutyCycle / 100.0) * TIMER_u16_ICR1_REG);
		break;
	}

	/* Set prescaler to divide by 8 */
	CLR_BIT(TIMER_u8_TCCR1B_REG,TCCR1B_CS10);
	SET_BIT(TIMER_u8_TCCR1B_REG,TCCR1B_CS11);
	CLR_BIT(TIMER_u8_TCCR1B_REG,TCCR1B_CS12);
}

void Timer1_void_SetPWMChanal_A(f32 Copy_u32_DutyCycle)
{
	TIMER_u16_OCR1A_REG = (u16)(((f32)Copy_u32_DutyCycle / 100.0) * TIMER_u16_ICR1_REG);
	/* Set prescaler to divide by 8 */
	CLR_BIT(TIMER_u8_TCCR1B_REG,TCCR1B_CS10);
	SET_BIT(TIMER_u8_TCCR1B_REG,TCCR1B_CS11);
	CLR_BIT(TIMER_u8_TCCR1B_REG,TCCR1B_CS12);
}

void Timer1_void_SetPWMChanal_B(f32 Copy_u32_DutyCycle)
{
	TIMER_u16_OCR1B_REG = (u16)(((f32)Copy_u32_DutyCycle / 100.0) * TIMER_u16_ICR1_REG);
	/* Set prescaler to divide by 8 */
	CLR_BIT(TIMER_u8_TCCR1B_REG,TCCR1B_CS10);
	SET_BIT(TIMER_u8_TCCR1B_REG,TCCR1B_CS11);
	CLR_BIT(TIMER_u8_TCCR1B_REG,TCCR1B_CS12);
}

void Timer1_void_SetICR1_Reg(u16 Copy_u16_Value)
{
	TIMER_u16_ICR1_REG = Copy_u16_Value;
}

void Timer1_void_SetOCR1_Reg(u16 Copy_u16_Value, u8 Copy_u8_Chanal)
{
	switch(Copy_u8_Chanal)
	{
	case TIMER1_CHANAL_A:
		TIMER_u16_OCR1A_REG = Copy_u16_Value;
		break;

	case TIMER1_CHANAL_B:
		TIMER_u16_OCR1B_REG = Copy_u16_Value;
		break;

	case TIMER1_CHANAL_A_B:
		TIMER_u16_OCR1A_REG = Copy_u16_Value;
		TIMER_u16_OCR1B_REG = Copy_u16_Value;
		break;
	}
}


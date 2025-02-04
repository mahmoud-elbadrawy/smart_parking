/*****************************************************/
/*****************************************************/
/******** Author      : Mahmoud Elbadrawy    *********/
/******** Layer       : MCAL                 *********/
/******** Component   : Timer0               *********/
/******** version     : 1.0 V                *********/
/******** Date        : 12/7/2023            *********/
/*****************************************************/
/*****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Timer0_Interface.h"
#include "Timer0_Registers.h"
#include "Timer0_Private.h"
#include "Timer0_Config.h"

u32 GLOBAL_u32_NUM_OVF = 0;
u32 GLOBAL_u32_PRELOAD = 0;
static void (*Global_PF_Timer0)(void) = NULL;
void Timer0_void_Init()
{
#if TIMER0_MODE == OVERFLOW_MODE
	/* Waveform Generation Mode */
	CLR_BIT(TIMER_TCCR0_u8_REG, TCCR0_WGM00);
	CLR_BIT(TIMER_TCCR0_u8_REG, TCCR0_WGM01);
	/* Peripheral Interrupt is enabled */
	SET_BIT(TIMER_TIMSK_u8_REG, TIMSK_TOIE0);
#elif TIMER0_MODE == COMPARE_MATCH_MODE
	/* Waveform Generation Mode */
	CLR_BIT(TIMER_TCCR0_u8_REG, TCCR0_WGM00);
	SET_BIT(TIMER_TCCR0_u8_REG, TCCR0_WGM01);
	/* Peripheral Interrupt is enabled */
	SET_BIT(TIMER_TIMSK_u8_REG, TIMSK_OCIE0);

#elif TIMER0_MODE == FAST_PWM_MODE
	/* Waveform Generation Mode */
	SET_BIT(TIMER_TCCR0_u8_REG, TCCR0_WGM00);
	SET_BIT(TIMER_TCCR0_u8_REG, TCCR0_WGM01);
#if PWM_MODE == NON_INVERTED_MODE
	CLR_BIT(TIMER_TCCR0_u8_REG, TCCR0_COM00);
	SET_BIT(TIMER_TCCR0_u8_REG, TCCR0_COM01);
#elif PWM_MODE == INVERTED_MODE
	SET_BIT(TIMER_TCCR0_u8_REG, TCCR0_COM00);
	SET_BIT(TIMER_TCCR0_u8_REG, TCCR0_COM01);
#endif

#elif TIMER0_MODE == PHASE_CORRECT_MODE
	/* Waveform Generation Mode */
	SET_BIT(TIMER_TCCR0_u8_REG, TCCR0_WGM00);
	CLR_BIT(TIMER_TCCR0_u8_REG, TCCR0_WGM01);
#if PWM_MODE == NON_INVERTED_MODE
	CLR_BIT(TIMER_TCCR0_u8_REG, TCCR0_COM00);
	SET_BIT(TIMER_TCCR0_u8_REG, TCCR0_COM01);
#elif PWM_MODE == INVERTED_MODE
	SET_BIT(TIMER_TCCR0_u8_REG, TCCR0_COM00);
	SET_BIT(TIMER_TCCR0_u8_REG, TCCR0_COM01);
#endif

#endif
}

/* function to set prescaler */
void TIMER0_void_SetPrescaler()
{
#if  PRESCALAR == No_PRESCALING
	SET_BIT (TIMER_TCCR0_u8_REG, TCCR0_CS00);
	CLR_BIT (TIMER_TCCR0_u8_REG, TCCR0_CS01);
	CLR_BIT (TIMER_TCCR0_u8_REG, TCCR0_CS02);
#elif PRESCALAR == DIVIDION_BY_8
	CLR_BIT (TIMER_TCCR0_u8_REG, TCCR0_CS00);
	SET_BIT (TIMER_TCCR0_u8_REG, TCCR0_CS01);
	CLR_BIT (TIMER_TCCR0_u8_REG, TCCR0_CS02);

#elif PRESCALAR == DIVIDION_BY_64
	SET_BIT (TIMER_TCCR0_u8_REG, TCCR0_CS00);
	SET_BIT (TIMER_TCCR0_u8_REG, TCCR0_CS01);
	CLR_BIT (TIMER_TCCR0_u8_REG, TCCR0_CS02);

#elif PRESCALAR == DIVIDION_BY_256
	CLR_BIT (TIMER_TCCR0_u8_REG, TCCR0_CS00);
	CLR_BIT (TIMER_TCCR0_u8_REG, TCCR0_CS01);
	SET_BIT (TIMER_TCCR0_u8_REG, TCCR0_CS02);

#elif PRESCALAR == DIVIDION_BY_1024
	SET_BIT (TIMER_TCCR0_u8_REG, TCCR0_CS00);
	CLR_BIT (TIMER_TCCR0_u8_REG, TCCR0_CS01);
	SET_BIT (TIMER_TCCR0_u8_REG, TCCR0_CS02);

#endif
}

void TIMER0_void_StopTimer()
{
	CLR_BIT (TIMER_TCCR0_u8_REG, TCCR0_CS00);
	CLR_BIT (TIMER_TCCR0_u8_REG, TCCR0_CS01);
	CLR_BIT (TIMER_TCCR0_u8_REG, TCCR0_CS02);
}

void TIMER0_void_SetCompareValue(u8 A_u8_CompareValue)
{
	TIMER_OCR0_u8_REG = A_u8_CompareValue;
}

void TIMER0_void_AsynchronousStartTimer(f32 A_f32_TIME_ms, void (*TIMER0_PF_Function)(void))
{
#if TIMER0_MODE == OVERFLOW_MODE
	/* set the function address to callback */
	Global_PF_Timer0 = TIMER0_PF_Function;
	/* Convert the number to microsec. */
	f32 Local_f32_TIME_US = A_f32_TIME_ms * 1000;
	/* get the tick time in microsec. */
	f32 Local_f32_TICK_TIME = (f32)PRESCALAR  / SYSTEM_CLCK;
	/* over flow time. */
	f32 Local_f32_OVF_TIME = Local_f32_TICK_TIME * RESOLUTION;
	/* no. of over flow.  */
	f32 Local_f32_NUM_OVF = Local_f32_TIME_US / Local_f32_OVF_TIME;
	GLOBAL_u32_NUM_OVF = Local_f32_NUM_OVF;
	/* preload fraction. */
	f32 Local_f32_Preload_Fraction = Local_f32_NUM_OVF - GLOBAL_u32_NUM_OVF;
	/* the part of resolution needed for the fraction of desired time. */
	u32 FRACTION_TICKS = Local_f32_Preload_Fraction * RESOLUTION;
	/* the preload that the system will start count from it. */
	GLOBAL_u32_PRELOAD = RESOLUTION - FRACTION_TICKS;
	/* set the clock to start the timer */
	TIMER0_void_SetPrescaler();
#elif TIMER0_MODE == COMPARE_MATCH_MODE
	/* set the function address to callback */
	Global_PF_Timer0 = TIMER0_PF_Function;
	/* Convert the number to microsec. */
	f32 Local_f32_TIME_US = A_f32_TIME_ms * 1000;
	/* get the tick time in microsec. */
	f32 Local_f32_TICK_TIME = (f32)PRESCALAR  / SYSTEM_CLCK;
	/* over flow time. */
	f32 Local_f32_OVF_TIME = Local_f32_TICK_TIME * TIMER_OCR0_u8_REG;
	/* no. of over flow.  */
	f32 Local_f32_NUM_OVF = Local_f32_TIME_US / Local_f32_OVF_TIME;
	GLOBAL_u32_NUM_OVF = Local_f32_NUM_OVF;
	/* preload fraction. */
	f32 Local_f32_Preload_Fraction = Local_f32_NUM_OVF - GLOBAL_u32_NUM_OVF;
	/* the part of resolution needed for the fraction of desired time. */
	u32 FRACTION_TICKS = Local_f32_Preload_Fraction * RESOLUTION;
	/* the preload that the system will start count from it. */
	GLOBAL_u32_PRELOAD = RESOLUTION - FRACTION_TICKS;
	/* set the clock to start the timer */
	TIMER0_void_SetPrescaler();
#endif

}


void TIMER0_void_BusyWaitStartTimer(f32 A_f32_TIME_ms)
{
#if TIMER0_MODE == OVERFLOW_MODE
	/* Peripheral Interrupt is disabled */
	CLR_BIT(TIMER_TIMSK_u8_REG, TIMSK_TOIE0);
	/* Convert the number to microsec. */
	f32 Local_f32_TIME_US = A_f32_TIME_ms * 1000;
	/* get the tick time in microsec. */
	f32 Local_f32_TICK_TIME = (f32)PRESCALAR  / SYSTEM_CLCK;
	/* over flow time. */
	f32 Local_f32_OVF_TIME = Local_f32_TICK_TIME * RESOLUTION;
	/* no. of over flow.  */
	f32 Local_f32_NUM_OVF = Local_f32_TIME_US / Local_f32_OVF_TIME;
	GLOBAL_u32_NUM_OVF = Local_f32_NUM_OVF;
	/* preload fraction. */
	f32 Local_f32_Preload_Fraction = Local_f32_NUM_OVF - GLOBAL_u32_NUM_OVF;
	/* the part of resolution needed for the fraction of desired time. */
	u32 FRACTION_TICKS = Local_f32_Preload_Fraction * RESOLUTION;
	/* the preload that the system will start count from it. */
	GLOBAL_u32_PRELOAD = RESOLUTION - FRACTION_TICKS;
	/* set the clock to start the timer */
	TIMER0_void_SetPrescaler();
	
	/*Busy wait until the flag is rised */
	u32 Local_u32_Counter = 0;
	while(Local_u32_Counter < GLOBAL_u32_NUM_OVF)
	{
		while(GET_BIT(TIMER_TIFR_u8_REG,TIFR_TOV0) == 0);
		Local_u32_Counter++;
		SET_BIT(TIMER_TIFR_u8_REG,TIFR_TOV0);
	}
	/* Stop timer */
	TIMER0_void_StopTimer();
#elif TIMER0_MODE == COMPARE_MATCH_MODE
	/* Peripheral Interrupt is disabled */
	CLR_BIT(TIMER_TIMSK_u8_REG, TIMSK_OCIE0);
	/* Convert the number to microsec. */
	f32 Local_f32_TIME_US = A_f32_TIME_ms * 1000;
	/* get the tick time in microsec. */
	f32 Local_f32_TICK_TIME = (f32)PRESCALAR  / SYSTEM_CLCK;
	/* over flow time. */
	f32 Local_f32_OVF_TIME = Local_f32_TICK_TIME * TIMER_OCR0_u8_REG;
	/* no. of over flow.  */
	f32 Local_f32_NUM_OVF = Local_f32_TIME_US / Local_f32_OVF_TIME;
	GLOBAL_u32_NUM_OVF = Local_f32_NUM_OVF;
	/* preload fraction. */
	f32 Local_f32_Preload_Fraction = Local_f32_NUM_OVF - GLOBAL_u32_NUM_OVF;
	/* the part of resolution needed for the fraction of desired time. */
	u32 FRACTION_TICKS = Local_f32_Preload_Fraction * RESOLUTION;
	/* the preload that the system will start count from it. */
	GLOBAL_u32_PRELOAD = RESOLUTION - FRACTION_TICKS;
	/* set the clock to start the timer */
	TIMER0_void_SetPrescaler();

	/*Busy wait until the flag is rised */
	u32 Local_u32_Counter = 0;
	while(Local_u32_Counter < GLOBAL_u32_NUM_OVF)
	{
		while(GET_BIT(TIMER_TIFR_u8_REG,TIFR_OCF0) == 0);
		Local_u32_Counter++;
		SET_BIT(TIMER_TIFR_u8_REG,TIFR_OCF0);
	}
	/* Stop timer */
	TIMER0_void_StopTimer();
#endif

}



void TIMER0_void_SetPWM(u32 Duty_Cycle)
{
#if TIMER0_MODE == FAST_PWM_MODE
#if PWM_MODE == NON_INVERTED_MODE
	TIMER_OCR0_u8_REG = (u8)(((f32)Duty_Cycle / 100.0) * (RESOLUTION - 1));
#elif PWM_MODE == INVERTED_MODE
	TIMER_OCR0_u8_REG = (u8) ((RESOLUTION - 1) - (((f32)Duty_Cycle / 100.0) * (RESOLUTION - 1)));
#endif
	//#elif TIMER0_MODE == PHASE_CORRECT_MODE
	TIMER0_void_SetPrescaler();
#endif
}

#if TIMER0_MODE == OVERFLOW_MODE
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	static u32 local_u32_Counter = 0;
	local_u32_Counter++;

	if (local_u32_Counter == GLOBAL_u32_NUM_OVF)
	{
		/*reset the system*/
		local_u32_Counter = 0;
		TIMER_TCNT0_u8_REG = GLOBAL_u32_PRELOAD;
		if(Global_PF_Timer0 != NULL)
		{
			Global_PF_Timer0();
		}
	}
}

#elif TIMER0_MODE == COMPARE_MATCH_MODE

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	static u32 local_u32_Counter = 0;
	local_u32_Counter++;

	if (local_u32_Counter == GLOBAL_u32_NUM_OVF)
	{
		/*reset the system*/
		local_u32_Counter = 0;
		TIMER_TCNT0_u8_REG = GLOBAL_u32_PRELOAD;
		if(Global_PF_Timer0 != NULL)
		{
			Global_PF_Timer0();
		}
	}
}
#endif



/*****************************************************/
/*****************************************************/
/******** Author      : Mahmoud Elbadrawy    *********/
/******** Layer       : MCAL                 *********/
/******** Component   : Timer0               *********/
/******** version     : 1.0 V                *********/
/******** Date        : 12/7/2023            *********/
/*****************************************************/
/*****************************************************/


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_


void Timer0_void_Init();
void TIMER0_void_SetPrescaler();
void TIMER0_void_SetCompareValue(u8 A_u8_CompareValue);
void TIMER0_void_StopTimer();
void TIMER0_void_AsynchronousStartTimer(f32 A_f32_TIME_ms, void (*TIMER0_PF_Function)(void));
void TIMER0_void_BusyWaitStartTimer(f32 A_f32_TIME_ms);
void TIMER0_void_SetPWM(u32 Duty_Cycle);
#endif /* TIMER0_INTERFACE_H_ */

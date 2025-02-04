/*
 * Timer0_Private.h
 *
 *  Created on: ???/???/????
 *      Author: Genius
 */

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

// 8 MHZ for the clock
#define SYSTEM_CLCK 	     8.0
#define RESOLUTION           256
#define RESOLUTION_OCR0_REG  1
/* Modes of timer0 */
#define OVERFLOW_MODE       1
#define COMPARE_MATCH_MODE  2
#define FAST_PWM_MODE       3
#define PHASE_CORRECT_MODE  4

#define NON_INVERTED_MODE   1  
#define INVERTED_MODE   2  

/* Prescaler Selections */
#define No_PRESCALING       1
#define DIVIDION_BY_8       8
#define DIVIDION_BY_64      64
#define DIVIDION_BY_256     256
#define DIVIDION_BY_1024    1024


#define NULL   0
#endif /* TIMER0_PRIVATE_H_ */

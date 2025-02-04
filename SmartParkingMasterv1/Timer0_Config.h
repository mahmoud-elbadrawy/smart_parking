/*****************************************************/
/*****************************************************/
/******** Author      : Mahmoud Elbadrawy    *********/
/******** Layer       : MCAL                 *********/
/******** Component   : Timer0               *********/
/******** version     : 1.0 V                *********/
/******** Date        : 12/7/2023            *********/
/*****************************************************/
/*****************************************************/


#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_
/* Select the timer mode */
/* Options :-
 *             1- OVERFLOW_MODE
 *             2- COMPARE_MATCH_MODE
 *             3- FAST_PWM_MODE
 *             4- PHASE_CORRECT_MODE
 */
#define TIMER0_MODE      OVERFLOW_MODE

/* Select PWM mode */
/*
 * Options :- 
 *            1- NON_INVERTED_MODE
 *            2- INVERTED_MODE
*/
#define PWM_MODE        NON_INVERTED_MODE

/* Select the timer Prescaler */
/* Options :-
 *             1- No_PRESCALING
 *             2- DIVIDION_BY_8
 *             3- DIVIDION_BY_64
 *             4- DIVIDION_BY_256
 *             5- DIVIDION_BY_1024
 */
#define PRESCALAR       DIVIDION_BY_8

#endif /* TIMER0_CONFIG_H_ */

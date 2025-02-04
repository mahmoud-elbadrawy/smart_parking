/*****************************************************/
/*****************************************************/
/******** Author      : Mahmoud Elbadrawy    *********/
/******** Layer       : MCAL                 *********/
/******** Component   : UART                 *********/
/******** version     : 1.0 V                *********/
/******** Date        : 23/7/2023            *********/
/*****************************************************/
/*****************************************************/

#ifndef UART_CONFIG_H
#define UART_CONFIG_H

/* Parity mode selection , it is error checking mechanism */
/* Options :-
 *             1- DISABLED
 *             2- EVEN_PARITY
 *             3- ODD_PARITY
 */
#define  PARITY_MODE  DISABLED

/* Stop bit selection */
/* Options :-
 *             1- ONE_BIT
 *             2- TWO_BIT
 */
#define STOP_BIT   ONE_BIT

/* Data Size Selection */
/* Options :-
 *             1- FIVE_BIT
 *             2- SIX_BIT
 *             3- SEVEN_BIT
 *             4- EIGHT_BIT
 *             5- NINE_BIT
 */
#define DATA_SIZE    EIGHT_BIT
#endif

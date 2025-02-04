/*****************************************************/
/*****************************************************/
/******** Author      : Mahmoud Elbadrawy    *********/
/******** Layer       : MCAL                 *********/
/******** Component   : UART                 *********/
/******** version     : 1.0 V                *********/
/******** Date        : 23/7/2023            *********/
/*****************************************************/
/*****************************************************/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void UART_void_Init(void);
void UART_void_SendData(u8 A_u8_Data);
void UART_void_RecieveData(u8 * A_pu8_Data);
void UART_voidSendString(u8 * A_pu_String);
void UART_voidSendNumber(s32 A_s32_Number);


#endif 

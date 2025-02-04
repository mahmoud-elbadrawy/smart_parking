/*****************************************************/
/*****************************************************/
/******** Author      : Mahmoud Elbadrawy    *********/
/******** Layer       : MCAL                 *********/
/******** Component   : UART                 *********/
/******** version     : 1.0 V                *********/
/******** Date        : 23/7/2023            *********/
/*****************************************************/
/*****************************************************/

#ifndef UART_REGISTERS_H
#define UART_REGISTERS_H

#define HWREG8(X)                      *((volatile u8*)(X)) 

// USART (I/O) Data Register
#define         UART_u8_UDR            HWREG8(0x2C)

// USART Control and Status Register A
#define         UART_u8_UCSRA          HWREG8(0x2B)          

// MultiProcessing Communication
#define         UCSRA_MPCM             0            

// USART Double Speed Mode Bit
#define         UCSRA_U2X              1            

// Parity Error Flag Bit
#define         UCSRA_PE               2            

// Data OverRun Flag Bit
#define         UCSRA_DOR              3            

// Frame Error Flag Bit
#define         UCSRA_FE               4            

// UDR Register Empty Flag Bit
#define         UCSRA_UDRE             5            

// Transmission Complete Flag Bit
#define         UCSRA_TXC              6            

// Receiption Complete Flag Bit
#define         UCSRA_RXC              7            

// USART Control and Status Register B
#define         UART_u8_UCSRB          HWREG8(0x2A)          

// Transmitted Data 9th Bit
#define         UCSRB_TXB8             0             

// Received Data 9th Bit
#define         UCSRB_RXB8             1            

// USART Character Size Select Bit 2
#define         UCSRB_UCSZ2            2            

// Transmiter Enable
#define         UCSRB_TXEN             3            

// Receive Enable
#define         UCSRB_RXEN             4           

// UDR Register Empty Interrupt Enable
#define         UCSRB_UDRIE            5            

// Transmission Complete Interrupt Enable
#define         UCSRB_TXCIE            6            

// Receiption Complete Interrupt Enable
#define         UCSRB_RXCIE            7            

// USART Control and Status Register C
#define         UART_u8_UCSRC          HWREG8(0x40)          

// USART Clock Polarity
#define         UCSRC_UCPOL            0            

// USART Character Size Select Bit 0
#define         UCSRC_UCSZ0            1           

// USART Character Size Select Bit 1
#define         UCSRC_UCSZ1            2            

// USART Stop Bit Select
#define         UCSRC_USBS             3           

// USART Parity Mode Select Bit 0
#define         UCSRC_UPM0             4            

// USART Parity Mode Select Bit 1
#define         UCSRC_UPM1             5            
									   
// USART Mode Select                   
#define         UCSRC_UMSEL            6            
									   
// USART Register Select               
#define         UCSRC_URSEL            7            
									   
// USART BaudRate Register Low         
#define         UART_u8_UBRRL          HWREG8(0x29)          
									   
// USART BaudRate Register High        
#define         UART_u8_UBRRH          HWREG8(0x40)          
									   
// USART Register Select               
#define         UBRRH_URSEL            7            


#endif

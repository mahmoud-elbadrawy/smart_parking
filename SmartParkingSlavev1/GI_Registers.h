/********************************************************************************
 * Author:          Mahmoud Elbadrawy
 * Creation Data:   1 Sep, 2023
 * Version:         v1.0
 * SWC :            Global Interrupt
 * Layer:           MCAL
 ********************************************************************************/
/********************************************************************************
 * Version      Date                  Author                  Description
 * v1.0         1 Sep, 2023     Mahmoud Elbadrawy          Initial Creation
 *********************************************************************************/

#ifndef GI_REGISTERS_H
#define GI_REGISTERS_H

#define HWR8(X)       *((u8*)(X))

#define GI_SREG       HWR8(0x5F)
#define SREG_I        7         

#endif

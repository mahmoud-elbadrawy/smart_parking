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

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GI_Interface.h"
#include "GI_Registers.h"

void GI_void_Enable()
{
	SET_BIT(GI_SREG, SREG_I);
}
void GI_void_Disable()
{
	CLR_BIT(GI_SREG, SREG_I);
}

/*****************************************************/
/*****************************************************/
/******** Author      : Mahmoud Elbadrawy    *********/
/******** Layer       : MCAL                 *********/
/******** Component   : DIO_Program          *********/
/******** version     : 1.0 V                *********/
/******** Date        : 24/4/2023            *********/
/*****************************************************/
/*****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "DIO_Registers.h"
#include "DIO_Config.h"

/* Function to configure DIO */
void DIO_void_Init(void)
{
	/* set port Direction */
	DIO_DDRA_u8_REG = CONCT_BIT(DIO_PORTA_PIN7_INIT_DIR,DIO_PORTA_PIN6_INIT_DIR,
			                    DIO_PORTA_PIN5_INIT_DIR,DIO_PORTA_PIN4_INIT_DIR,
			                    DIO_PORTA_PIN3_INIT_DIR,DIO_PORTA_PIN2_INIT_DIR,
								DIO_PORTA_PIN1_INIT_DIR,DIO_PORTA_PIN0_INIT_DIR);

	DIO_DDRB_u8_REG = CONCT_BIT(DIO_PORTB_PIN7_INIT_DIR,DIO_PORTB_PIN6_INIT_DIR,
								DIO_PORTB_PIN5_INIT_DIR,DIO_PORTB_PIN4_INIT_DIR,
								DIO_PORTB_PIN3_INIT_DIR,DIO_PORTB_PIN2_INIT_DIR,
								DIO_PORTB_PIN1_INIT_DIR,DIO_PORTB_PIN0_INIT_DIR);

	DIO_DDRC_u8_REG = CONCT_BIT(DIO_PORTC_PIN7_INIT_DIR,DIO_PORTC_PIN6_INIT_DIR,
								DIO_PORTC_PIN5_INIT_DIR,DIO_PORTC_PIN4_INIT_DIR,
								DIO_PORTC_PIN3_INIT_DIR,DIO_PORTC_PIN2_INIT_DIR,
								DIO_PORTC_PIN1_INIT_DIR,DIO_PORTC_PIN0_INIT_DIR);

	DIO_DDRD_u8_REG = CONCT_BIT(DIO_PORTD_PIN7_INIT_DIR,DIO_PORTD_PIN6_INIT_DIR,
								DIO_PORTD_PIN5_INIT_DIR,DIO_PORTD_PIN4_INIT_DIR,
								DIO_PORTD_PIN3_INIT_DIR,DIO_PORTD_PIN2_INIT_DIR,
								DIO_PORTD_PIN1_INIT_DIR,DIO_PORTD_PIN0_INIT_DIR);

	/* set port Value */
	DIO_PORTA_u8_REG = CONCT_BIT(DIO_PORTA_PIN7_INIT_VAL,DIO_PORTA_PIN6_INIT_VAL,
								 DIO_PORTA_PIN5_INIT_VAL,DIO_PORTA_PIN4_INIT_VAL,
								 DIO_PORTA_PIN3_INIT_VAL,DIO_PORTA_PIN2_INIT_VAL,
								 DIO_PORTA_PIN1_INIT_VAL,DIO_PORTA_PIN0_INIT_VAL);

	DIO_PORTB_u8_REG = CONCT_BIT(DIO_PORTB_PIN7_INIT_VAL,DIO_PORTB_PIN6_INIT_VAL,
								 DIO_PORTB_PIN5_INIT_VAL,DIO_PORTB_PIN4_INIT_VAL,
								 DIO_PORTB_PIN3_INIT_VAL,DIO_PORTB_PIN2_INIT_VAL,
								 DIO_PORTB_PIN1_INIT_VAL,DIO_PORTB_PIN0_INIT_VAL);

	DIO_PORTC_u8_REG = CONCT_BIT(DIO_PORTC_PIN7_INIT_VAL,DIO_PORTC_PIN6_INIT_VAL,
								 DIO_PORTC_PIN5_INIT_VAL,DIO_PORTC_PIN4_INIT_VAL,
								 DIO_PORTC_PIN3_INIT_VAL,DIO_PORTC_PIN2_INIT_VAL,
								 DIO_PORTC_PIN1_INIT_VAL,DIO_PORTC_PIN0_INIT_VAL);

	DIO_PORTD_u8_REG = CONCT_BIT(DIO_PORTD_PIN7_INIT_VAL,DIO_PORTD_PIN6_INIT_VAL,
								 DIO_PORTD_PIN5_INIT_VAL,DIO_PORTD_PIN4_INIT_VAL,
								 DIO_PORTD_PIN3_INIT_VAL,DIO_PORTD_PIN2_INIT_VAL,
								 DIO_PORTD_PIN1_INIT_VAL,DIO_PORTD_PIN0_INIT_VAL);
}

/* Function to set the pin direction */
DIO_Errors DIO_enum_SetPinDirection(u8 Local_u8_Port, u8 Local_u8_Pin, u8 Local_u8_Direction)
{
	u8 Local_u8_ErrorState = DIO_OK;
	if(Local_u8_Pin >= DIO_PIN0 && Local_u8_Pin <= DIO_PIN7)
	{
		if(Local_u8_Direction == DIO_PIN_INPUT)
		{
			switch(Local_u8_Port)
			{
			case DIO_PORTA: CLR_BIT(DIO_DDRA_u8_REG, Local_u8_Pin); break;
			case DIO_PORTB: CLR_BIT(DIO_DDRB_u8_REG, Local_u8_Pin); break;
			case DIO_PORTC: CLR_BIT(DIO_DDRC_u8_REG, Local_u8_Pin); break;
			case DIO_PORTD: CLR_BIT(DIO_DDRD_u8_REG, Local_u8_Pin); break;
			/* report error the port is incorrect  */
			default: Local_u8_ErrorState = DIO_PORT_NUM_INCORRECT; break;
			}                                                        
		}                                                            
		else if(Local_u8_Direction == DIO_PIN_OUTPUT)
		{                                                            
			switch(Local_u8_Port)                                    
			{                                                        
			case DIO_PORTA: SET_BIT(DIO_DDRA_u8_REG, Local_u8_Pin); break;
			case DIO_PORTB: SET_BIT(DIO_DDRB_u8_REG, Local_u8_Pin); break;
			case DIO_PORTC: SET_BIT(DIO_DDRC_u8_REG, Local_u8_Pin); break;
			case DIO_PORTD: SET_BIT(DIO_DDRD_u8_REG, Local_u8_Pin); break;
			/* report error the port is incorrect  */
			default: Local_u8_ErrorState = DIO_PORT_NUM_INCORRECT; break;
			}
		}
		else
		{
			/* report error the Direction is incorrect  */
			Local_u8_ErrorState = DIO_DIR_TYPE_INCORRECT;
		}

	}
	else
	{
		/* report error the pin number is incorrect */
		Local_u8_ErrorState = DIO_PIN_NUM_INCORRECT;
	}
	return Local_u8_ErrorState;
}

/* Function to set the pin value */
DIO_Errors DIO_enum_SetPinValue(u8 Local_u8_Port, u8 Local_u8_Pin, u8 Local_u8_Value)
{
	u8 Local_u8_ErrorState = DIO_OK;
	if(Local_u8_Pin >= DIO_PIN0 && Local_u8_Pin <=DIO_PIN7)
	{
		if(Local_u8_Value == DIO_PIN_LOW)
		{
			switch(Local_u8_Port)
			{
			case DIO_PORTA: CLR_BIT(DIO_PORTA_u8_REG, Local_u8_Pin); break;
			case DIO_PORTB: CLR_BIT(DIO_PORTB_u8_REG, Local_u8_Pin); break;
			case DIO_PORTC: CLR_BIT(DIO_PORTC_u8_REG, Local_u8_Pin); break;
			case DIO_PORTD: CLR_BIT(DIO_PORTD_u8_REG, Local_u8_Pin); break;
			/* report error the port is incorrect */
			default: Local_u8_ErrorState = DIO_PORT_NUM_INCORRECT; break;
			}
		}
		else if (Local_u8_Value == DIO_PIN_HIGH)
		{
			switch(Local_u8_Port)
			{
			case DIO_PORTA: SET_BIT(DIO_PORTA_u8_REG, Local_u8_Pin); break;
			case DIO_PORTB: SET_BIT(DIO_PORTB_u8_REG, Local_u8_Pin); break;
			case DIO_PORTC: SET_BIT(DIO_PORTC_u8_REG, Local_u8_Pin); break;
			case DIO_PORTD: SET_BIT(DIO_PORTD_u8_REG, Local_u8_Pin); break;
			/* report error the port is incorrect */
			default: Local_u8_ErrorState = DIO_PORT_NUM_INCORRECT; break;
			}
		}
		else
		{
			/* report error the Value is incorrect  */
			Local_u8_ErrorState = DIO_VAL_TYPE_INCORRECT;
		}
	}
	else
	{
		/* report error the pin number is incorrect */
		Local_u8_ErrorState = DIO_PIN_NUM_INCORRECT;
	}
	return Local_u8_ErrorState;
}

/* Function to get pin value  */
DIO_Errors DIO_enum_GetPinValue(u8 Local_u8_Port, u8 Local_u8_Pin, u8 * Local_u8Ptr_PinValue)
{
	u8 Local_u8_ErrorState = DIO_OK;
	if(Local_u8_Pin >= DIO_PIN0 && Local_u8_Pin <= DIO_PIN7)
	{
		switch(Local_u8_Port)
		{
		case DIO_PORTA: *Local_u8Ptr_PinValue = GET_BIT(DIO_PINA_u8_REG, Local_u8_Pin); break;
		case DIO_PORTB: *Local_u8Ptr_PinValue = GET_BIT(DIO_PINB_u8_REG, Local_u8_Pin); break;
		case DIO_PORTC: *Local_u8Ptr_PinValue = GET_BIT(DIO_PINC_u8_REG, Local_u8_Pin); break;
		case DIO_PORTD: *Local_u8Ptr_PinValue = GET_BIT(DIO_PIND_u8_REG, Local_u8_Pin); break;
		/* report error the port is incorrect */
		default: Local_u8_ErrorState = DIO_PORT_NUM_INCORRECT; break;
		}
	}
	else
	{
		/* report error the pin number is incorrect */
		Local_u8_ErrorState = DIO_PIN_NUM_INCORRECT;
	}
	return Local_u8_ErrorState;
}

/* Function to toggle the pin value  */
DIO_Errors DIO_enum_TogglePin(u8 Local_u8_Port, u8 Local_u8_Pin)
{
	u8 Local_u8_ErrorState = DIO_OK;
	if(Local_u8_Pin >= DIO_PIN0 && Local_u8_Pin <= DIO_PIN7)
	{
		switch(Local_u8_Port)
		{
		case DIO_PORTA: TOG_BIT(DIO_PORTA_u8_REG, Local_u8_Pin); break;
		case DIO_PORTB: TOG_BIT(DIO_PORTB_u8_REG, Local_u8_Pin); break;
		case DIO_PORTC: TOG_BIT(DIO_PORTC_u8_REG, Local_u8_Pin); break;
		case DIO_PORTD: TOG_BIT(DIO_PORTD_u8_REG, Local_u8_Pin); break;
		/* report error the port is incorrect */
		default: Local_u8_ErrorState = DIO_PORT_NUM_INCORRECT; break;
		}
	}
	else
	{
		/* report error the pin number is incorrect */
		Local_u8_ErrorState = DIO_PIN_NUM_INCORRECT;
	}
	return Local_u8_ErrorState;
}

/* function to set the port Direction */
DIO_Errors DIO_enum_SetPortDirection(u8 Local_u8_Port, u8 Local_u8_Direction)
{
	u8 Local_u8_ErrorState = DIO_OK;
	switch(Local_u8_Port)
	{
		case DIO_PORTA: DIO_DDRA_u8_REG = Local_u8_Direction; break;
		case DIO_PORTB: DIO_DDRB_u8_REG = Local_u8_Direction; break;
		case DIO_PORTC: DIO_DDRC_u8_REG = Local_u8_Direction; break;
		case DIO_PORTD: DIO_DDRD_u8_REG = Local_u8_Direction; break;
		/* report error the port is incorrect */
		default: Local_u8_ErrorState = DIO_PORT_NUM_INCORRECT; break;
	}
	return Local_u8_ErrorState;
}

/* Function to set the port value */
DIO_Errors DIO_enum_SetPortValue(u8 Local_u8_Port, u8 Local_u8_Value)
{
	u8 Local_u8_ErrorState = DIO_OK;
	switch(Local_u8_Port)
	{
		case DIO_PORTA: DIO_PORTA_u8_REG = Local_u8_Value; break;
		case DIO_PORTB: DIO_PORTB_u8_REG = Local_u8_Value; break;
		case DIO_PORTC: DIO_PORTC_u8_REG = Local_u8_Value; break;
		case DIO_PORTD: DIO_PORTD_u8_REG = Local_u8_Value; break;
		/* report error the port is incorrect */
		default: Local_u8_ErrorState = DIO_PORT_NUM_INCORRECT; break;
	}
	return Local_u8_ErrorState;
}

/* Function to toggle the port value */
DIO_Errors DIO_enum_TogglePort(u8 Local_u8_Port)
{
	u8 Local_u8_ErrorState = DIO_OK;
	switch(Local_u8_Port)
	{
		case DIO_PORTA: TOG_REG(DIO_PORTA_u8_REG); break;
		case DIO_PORTB: TOG_REG(DIO_PORTB_u8_REG); break;
		case DIO_PORTC: TOG_REG(DIO_PORTC_u8_REG); break;
		case DIO_PORTD: TOG_REG(DIO_PORTD_u8_REG); break;
		/* report error the port is incorrect */
		default: Local_u8_ErrorState = DIO_PORT_NUM_INCORRECT; break;
	}
	return Local_u8_ErrorState;
}

/* Function to get the port value */
DIO_Errors DIO_enum_GetPortValue(u8 Local_u8_Port,u8 * Local_u8Ptr_PortValue)
{
	u8 Local_u8_ErrorState = DIO_OK;
	switch(Local_u8_Port)
	{
		case DIO_PORTA: *Local_u8Ptr_PortValue = DIO_PINA_u8_REG; break;
		case DIO_PORTB: *Local_u8Ptr_PortValue = DIO_PINB_u8_REG; break;
		case DIO_PORTC: *Local_u8Ptr_PortValue = DIO_PINC_u8_REG; break;
		case DIO_PORTD: *Local_u8Ptr_PortValue = DIO_PIND_u8_REG; break;
		/* report error the port is incorrect */
		default: Local_u8_ErrorState = DIO_PORT_NUM_INCORRECT; break;
	}
	return Local_u8_ErrorState;
}

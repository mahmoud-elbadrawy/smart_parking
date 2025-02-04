//***************************************************/
/***************************************************/
/******** Author      : Mahmoud Elbadrawy  *********/
/******** Date        : 1/10/2023          *********/
/******** version     : 1.0 V              *********/
/******** Description : Standard Types lib *********/ 
/***************************************************/
/***************************************************/

/* guard of file will call one time in .c      **/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,n) (reg|=(1<<n))
#define CLR_BIT(reg,n) (reg&=~(1<<n))
#define TOG_BIT(reg,n) (reg^=(1<<n))
#define GET_BIT(reg,n) (((reg)>>(n))&1)


#define GET_REG(reg)	(reg)
#define SET_REG(reg)	((reg)=0xFF)
#define CLR_REG(reg)	((reg)=0x00)
#define TOG_REG(reg)	((reg)^=0xFF)
#define ASSIGN_REG(reg,value)	((reg)=value)

#define CONCT_BIT(b7,b6,b5,b4,b3,b2,b1,b0)   CONCT_HELP(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONCT_HELP(b7,b6,b5,b4,b3,b2,b1,b0)  0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif

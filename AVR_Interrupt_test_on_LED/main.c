#include "STD_TYPES.h"
#include "BIT_MATH.H"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "EXTI_interface.h"
#include "INTGLB_interface.h"

void Led_On(void)
{
	setPinValue('B',0,1);
}
void Led_Off(void)
{
	setPinValue('B',0,0);
}
void main(void)
{
	portInit();
	EXTI_voidInit();
	INT_voidEnableGlobal();
	EXTI_errEnable(0);
	EXTI_errEnable(1);
	EXTI_errSetCallBack(0,Led_On);
	EXTI_errSetCallBack(1,Led_Off);
	while(1)
	{

	}
}

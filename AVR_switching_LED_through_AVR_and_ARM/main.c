#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "SWITCH_interface.h"

void main(void)
{
	portInit();
	while(1)
	{
		if(getSwitchState(0)==1)
		{
			setPinValue('A',1,1);
		}
		else
		{
			setPinValue('A',1,0);
		}
	}
}

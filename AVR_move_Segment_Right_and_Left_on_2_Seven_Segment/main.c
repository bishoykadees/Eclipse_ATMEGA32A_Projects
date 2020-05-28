
#define F_CPU 8000000UL

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "SWITCH_interface.h"
#include "SevenSegment_interface.h"

#include <util/delay.h>

void main(void)
{
	u8 counter=1;
	u8 flag=0;

	portInit();

	SEVENSEG_Enable(0);
	SEVENSEG_setSegment(counter);

	while(1)
	{

		while(flag==0)
		{
			if(getSwitchState(0)==0x01)
			{
				if(counter==8)
				{
					counter=1;
				}
				else
				{
					counter++;
				}

				flag=1;
			}
			else if(getSwitchState(1)==0x01)
			{
				if(counter==1)
				{
					counter=8;
				}
				else
				{
					counter--;
				}
				flag=1;
			}
		}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if((counter>=1)&&(counter<=4))
		{
			SEVENSEG_Disable(0);
			SEVENSEG_Disable(1);
			SEVENSEG_Enable(0);
			SEVENSEG_setSegment(counter);
		}
		else if((counter>=5)&&(counter<=8))
		{
			SEVENSEG_Disable(0);
			SEVENSEG_Disable(1);
			SEVENSEG_Enable(1);
			SEVENSEG_setSegment(counter);
		}
		while(!((getSwitchState(0)==0x00)&&(getSwitchState(1)==0x00)));
		flag=0;
	}
}

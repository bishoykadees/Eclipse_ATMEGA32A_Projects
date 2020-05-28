#define F_CPU 8000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "SWITCH_interface.h"

#include <util/delay.h>

void main(void)
{
	u8 i=0;
	portInit();
	while(1)
	{
		if(getSwitchState(0)==1)
		{
			setPinValue('D',0,0);
			setPinValue('D',7,1);
			_delay_us(50);
			setPinValue('D',7,0);
			_delay_us(50);
		}
		if(getSwitchState(1)==1)
		{
			setPinValue('D',0,1);
			for(i=0;i<2;i++)
			{
				setPinValue('D',7,1);
				_delay_us(50);
				setPinValue('D',7,0);
				_delay_us(50);
			}
		}
		if(getSwitchState(2)==1)
		{

			for(i=0;i<3;i++)
			{
				setPinValue('D',7,1);
				_delay_us(50);
				setPinValue('D',7,0);
				_delay_us(50);
			}
		}
		if(getSwitchState(3)==1)
		{
			for(i=0;i<4;i++)
			{
				setPinValue('D',7,1);
				_delay_us(50);
				setPinValue('D',7,0);
				_delay_us(50);
			}
		}
		if(getSwitchState(4)==1)
		{
			for(i=0;i<5;i++)
			{
				setPinValue('D',7,1);
				_delay_us(50);
				setPinValue('D',7,0);
				_delay_us(50);
			}
		}
		if(getSwitchState(5)==1)
		{
			for(i=0;i<6;i++)
			{
				setPinValue('D',7,1);
				_delay_us(50);
				setPinValue('D',7,0);
				_delay_us(50);
			}
		}
		if(getSwitchState(6)==1)
		{
			for(i=0;i<7;i++)
			{
				setPinValue('D',7,1);
				_delay_us(50);
				setPinValue('D',7,0);
				_delay_us(50);
			}
		}
		if(getSwitchState(7)==1)
		{
			for(i=0;i<8;i++)
			{
				setPinValue('D',7,1);
				_delay_us(50);
				setPinValue('D',7,0);
				_delay_us(50);
			}
		}

	}
}

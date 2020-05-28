
#define F_CPU 8000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"

void main(void)
{
	u8 i;
	u8 arr[5]={'B','i','s','h','o'};
	portInit();
	CLCD_voidInitialize();


	while(1)
	{
		for(i=0;i<5;i++)
		{
			CLCD_voidWriteData(arr[i]);
		}
		_delay_ms(500);

		CLCD_voidWriteCmd(0x01);
		for(i=0;i<45;i++)
		{
			CLCD_voidWriteCmd(0x14);
		}

		for(i=0;i<5;i++)
		{
			CLCD_voidWriteData(arr[i]);
		}
		_delay_ms(500);

		CLCD_voidWriteCmd(0x01);
		for(i=0;i<10;i++)
		{
			CLCD_voidWriteCmd(0x14);
		}
		for(i=0;i<5;i++)
		{
			CLCD_voidWriteData(arr[i]);
		}
		_delay_ms(500);
		CLCD_voidWriteCmd(0x01);
		for(i=0;i<45;i++)
		{
			CLCD_voidWriteCmd(0x14);
		}

		for(i=0;i<5;i++)
		{
			CLCD_voidWriteData(arr[i]);
		}
		_delay_ms(500);

		CLCD_voidWriteCmd(0x01);
	}


}

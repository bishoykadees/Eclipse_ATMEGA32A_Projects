
#define F_CPU 8000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"
#include "SWITCH_interface.h"

void main(void)
{
	portInit();
	CLCD_voidInitialize();
	u8 X_Position=0, Y_Position=0, flag=0;
	CLCD_voidWriteString("Bisho");
	while(1)
	{
		while((getSwitchState(0)==1||getSwitchState(1)==1||getSwitchState(2)==1||getSwitchState(3)==1)&&(flag==0))
		{
			if(getSwitchState(0)==1)
			{
				if(Y_Position!=0)
				{
					Y_Position--;
					CLCD_voidWriteCmd(0x01);
					CLCD_voidGoToXYPos(X_Position,Y_Position);
					CLCD_voidWriteString("Bisho");
				}
				flag=1;
			}
			if(getSwitchState(1)==1)
			{
				if(X_Position!=11)
				{
					X_Position++;
					CLCD_voidWriteCmd(0x01);
					CLCD_voidGoToXYPos(X_Position,Y_Position);
					CLCD_voidWriteString("Bisho");
				}
				flag=1;
			}
			if(getSwitchState(2)==1)
			{
				if(Y_Position!=1)
				{
					Y_Position++;
					CLCD_voidWriteCmd(0x01);
					CLCD_voidGoToXYPos(X_Position,Y_Position);
					CLCD_voidWriteString("Bisho");
				}
				flag=1;
			}
			if(getSwitchState(3)==1)
			{
				if(X_Position!=0)
				{
					X_Position--;
					CLCD_voidWriteCmd(0x01);
					CLCD_voidGoToXYPos(X_Position,Y_Position);
					CLCD_voidWriteString("Bisho");
				}
				flag=1;
			}

			while((getSwitchState(0)==1)||(getSwitchState(1)==1)||(getSwitchState(2)==1)||(getSwitchState(3)==1));
		}
		flag=0;
	}
	/*
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

*/
}

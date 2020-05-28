
#define F_CPU 8000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"

void main(void)
{
	portInit();
	CLCD_voidInitialize();
	CLCD_voidWriteCmd(0b01000000);

	CLCD_voidWriteData(0b00000000);
	CLCD_voidWriteData(0b00000000);
	CLCD_voidWriteData(0b00000100);
	CLCD_voidWriteData(0b00001110);
	CLCD_voidWriteData(0b00011111);
	CLCD_voidWriteData(0b00001110);
	CLCD_voidWriteData(0b00000100);
	CLCD_voidWriteData(0b00000000);

	CLCD_voidWriteData(0b00000011);
	CLCD_voidWriteData(0b00000010);
	CLCD_voidWriteData(0b00011011);
	CLCD_voidWriteData(0b00010001);
	CLCD_voidWriteData(0b00011111);
	CLCD_voidWriteData(0b00000000);
	CLCD_voidWriteData(0b00000000);
	CLCD_voidWriteData(0b00000000);

	CLCD_voidWriteData(0b00000000);
	CLCD_voidWriteData(0b00000000);
	CLCD_voidWriteData(0b00000100);
	CLCD_voidWriteData(0b00001010);
	CLCD_voidWriteData(0b00011111);
	CLCD_voidWriteData(0b00000001);
	CLCD_voidWriteData(0b00000010);
	CLCD_voidWriteData(0b00011100);

	CLCD_voidWriteData(0b00000100);
	CLCD_voidWriteData(0b00001010);
	CLCD_voidWriteData(0b00010101);
	CLCD_voidWriteData(0b00010101);
	CLCD_voidWriteData(0b00011111);
	CLCD_voidWriteData(0b00000000);
	CLCD_voidWriteData(0b00000000);
	CLCD_voidWriteData(0b00000000);

	CLCD_voidWriteData(0b00000000);
	CLCD_voidWriteData(0b00000001);
	CLCD_voidWriteData(0b00000001);
	CLCD_voidWriteData(0b00011111);
	CLCD_voidWriteData(0b00000000);
	CLCD_voidWriteData(0b00001010);
	CLCD_voidWriteData(0b00000000);
	CLCD_voidWriteData(0b00000000);

	CLCD_voidWriteData(0b00000000);
	CLCD_voidWriteData(0b00000010);
	CLCD_voidWriteData(0b00000010);
	CLCD_voidWriteData(0b00011110);
	CLCD_voidWriteData(0b00000000);
	CLCD_voidWriteData(0b00000100);
	CLCD_voidWriteData(0b00000000);
	CLCD_voidWriteData(0b00000000);



	CLCD_voidWriteCmd(0b10000000);

	CLCD_voidGoToXYPos(6,0);
	CLCD_voidWriteData(0);
	CLCD_voidWriteData(1);
	CLCD_voidWriteData(2);
	CLCD_voidWriteData(3);
	CLCD_voidWriteData(4);
	CLCD_voidWriteData(5);
	while(1);
	/*
	u8 arr1[4]={1,1,1,1};
	u8 arr2[4];
	u8 counter=0;
	u8 counter1=1;
	u8 flag=0;
	portInit();
	CLCD_voidInitialize();
	CLCD_voidWriteString("Enter Password");
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while(flag==0)
	{
		while(getSwitchState(0)==1||getSwitchState(1)==1||getSwitchState(2)==1||getSwitchState(3)==1)
		{
			if(getSwitchState(0)==1)
			{
				CLCD_voidGoToXYPos(counter,1);
				CLCD_voidWriteString("*");
				arr2[counter]=1;
				counter++;
			}
			if(getSwitchState(1)==1)
			{
				CLCD_voidGoToXYPos(counter,1);
				CLCD_voidWriteString("*");
				arr2[counter]=2;
				counter++;
			}
			if(getSwitchState(2)==1)
			{
				CLCD_voidGoToXYPos(counter,1);
				CLCD_voidWriteString("*");
				arr2[counter]=3;
				counter++;
			}
			if(getSwitchState(3)==1)
			{
				CLCD_voidGoToXYPos(counter,1);
				CLCD_voidWriteString("*");
				arr2[counter]=4;
				counter++;
			}
			if(counter>=4)
			{
				flag=1;
			}
			while((getSwitchState(0)==1)||(getSwitchState(1)==1)||(getSwitchState(2)==1)||(getSwitchState(3)==1));
		}
	}
	for(counter=0;counter<4;counter++)
	{
		if(arr1[counter]!=arr2[counter])
		{
			flag=0;
		}
	}
////////////////////////////////////////////////////////////////////////////
	if(flag==0)
	{
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		for(;counter1<4;(counter1)++)
		{
			CLCD_voidWriteCmd(0x01);
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if(flag==0)
			{
				CLCD_voidWriteString("Try Again");
				counter=0;
				while(flag==0)
				{
					while(getSwitchState(0)==1||getSwitchState(1)==1||getSwitchState(2)==1||getSwitchState(3)==1)
					{
						if(getSwitchState(0)==1)
						{
							CLCD_voidGoToXYPos(counter,1);
							CLCD_voidWriteString("*");
							arr2[counter]=1;
							counter++;
						}
						if(getSwitchState(1)==1)
						{
							CLCD_voidGoToXYPos(counter,1);
							CLCD_voidWriteString("*");
							arr2[counter]=2;
							counter++;
						}
						if(getSwitchState(2)==1)
						{
							CLCD_voidGoToXYPos(counter,1);
							CLCD_voidWriteString("*");
							arr2[counter]=3;
							counter++;
						}
						if(getSwitchState(3)==1)
						{
							CLCD_voidGoToXYPos(counter,1);
							CLCD_voidWriteString("*");
							arr2[counter]=4;
							counter++;
						}
						if(counter>=4)
						{
							flag=1;
						}
						while((getSwitchState(0)==1)||(getSwitchState(1)==1)||(getSwitchState(2)==1)||(getSwitchState(3)==1));
					}
				}
				for(counter=0;counter<4;counter++)
				{
					if(arr1[counter]!=arr2[counter])
					{
						flag=0;
					}
				}
			}
			else if(flag==1)
			{
				CLCD_voidWriteString("Successful Login");
				setPinValue('D',3,1);
			}
		}

	}
	if(flag==1)
	{
		CLCD_voidWriteCmd(0x01);
		CLCD_voidWriteString("Successful Login");
		setPinValue('D',3,1);
	}
	else
	{
		CLCD_voidWriteCmd(0x01);
		CLCD_voidWriteString("Login Failed");
		setPinValue('C',7,1);
	}
	*/
}

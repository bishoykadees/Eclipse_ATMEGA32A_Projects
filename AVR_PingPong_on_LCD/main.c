
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
	u8 PlayerOnePos=0;
	u8 PlayerTwoPos=0;
	u8 counter=1;

	portInit();
	CLCD_voidInitialize();

	/* go to CGRAM address 0 */
	CLCD_voidWriteCmd(0b01000000);

	/* write character */
	CLCD_voidWriteData(0b00000000);
	CLCD_voidWriteData(0b00000000);
	CLCD_voidWriteData(0b00000100);
	CLCD_voidWriteData(0b00001110);
	CLCD_voidWriteData(0b00011111);
	CLCD_voidWriteData(0b00001110);
	CLCD_voidWriteData(0b00000100);
	CLCD_voidWriteData(0b00000000);

	CLCD_voidWriteData(0b00000001);
	CLCD_voidWriteData(0b00000001);
	CLCD_voidWriteData(0b00000001);
	CLCD_voidWriteData(0b00000001);
	CLCD_voidWriteData(0b00000001);
	CLCD_voidWriteData(0b00000001);
	CLCD_voidWriteData(0b00000001);
	CLCD_voidWriteData(0b00000001);

	CLCD_voidWriteData(0b00010000);
	CLCD_voidWriteData(0b00010000);
	CLCD_voidWriteData(0b00010000);
	CLCD_voidWriteData(0b00010000);
	CLCD_voidWriteData(0b00010000);
	CLCD_voidWriteData(0b00010000);
	CLCD_voidWriteData(0b00010000);
	CLCD_voidWriteData(0b00010000);

	CLCD_voidWriteData(0b00000000);
	CLCD_voidWriteData(0b00000000);
	CLCD_voidWriteData(0b00000000);
	CLCD_voidWriteData(0b00000000);
	CLCD_voidWriteData(0b00000000);
	CLCD_voidWriteData(0b00000000);
	CLCD_voidWriteData(0b00000000);
	CLCD_voidWriteData(0b00000000);

	/* go to DDRAM address 0 */
	CLCD_voidWriteCmd(0b10000000);

	CLCD_voidGoToXYPos(0,0);
	CLCD_voidWriteData(1);
	CLCD_voidGoToXYPos(15,0);
	CLCD_voidWriteData(2);
	while(1)
	{
		while(counter<15)
		{
			_delay_ms(150);
			if(counter!=1)
			{
				CLCD_voidGoToXYPos(counter-1,0);
				CLCD_voidWriteData(3);
			}
			CLCD_voidGoToXYPos(counter,0);
			CLCD_voidWriteData(0);
			counter++;

			if(getSwitchState(0)==1)
			{
				CLCD_voidGoToXYPos(0,PlayerOnePos);
				CLCD_voidWriteData(3);
				PlayerOnePos^=1;
				CLCD_voidGoToXYPos(0,PlayerOnePos);
				CLCD_voidWriteData(1);
			}
			if(getSwitchState(1)==1)
			{
				CLCD_voidGoToXYPos(15,PlayerTwoPos);
				CLCD_voidWriteData(3);
				PlayerTwoPos^=1;
				CLCD_voidGoToXYPos(15,PlayerTwoPos);
				CLCD_voidWriteData(2);
			}
		}
		if(PlayerTwoPos==1)
		{
			CLCD_voidWriteCmd(0b00000001);
			CLCD_voidWriteString("Player One Wins");
			break;
		}

		counter-=2;

		while(counter>0)
		{
			_delay_ms(150);

			CLCD_voidGoToXYPos(counter+1,0);
			CLCD_voidWriteData(3);
			CLCD_voidGoToXYPos(counter,0);
			CLCD_voidWriteData(0);
			counter--;

			if(getSwitchState(0)==1)
			{
				CLCD_voidGoToXYPos(0,PlayerOnePos);
				CLCD_voidWriteData(3);
				PlayerOnePos^=1;
				CLCD_voidGoToXYPos(0,PlayerOnePos);
				CLCD_voidWriteData(1);
			}
			if(getSwitchState(1)==1)
			{
				CLCD_voidGoToXYPos(15,PlayerTwoPos);
				CLCD_voidWriteData(3);
				PlayerTwoPos^=1;
				CLCD_voidGoToXYPos(15,PlayerTwoPos);
				CLCD_voidWriteData(2);
			}
		}

		if(PlayerOnePos==1)
		{
			CLCD_voidWriteCmd(0b00000001);
			CLCD_voidWriteString("Player Two Wins");
			break;
		}
		counter=1;
	}
}

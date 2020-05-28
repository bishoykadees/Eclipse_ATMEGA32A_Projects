
#define F_CPU 8000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"




void main(void)
{

	u8 counter;

	portInit();
	CLCD_voidInitialize();

	/* go to CGRAM address 0 */
	CLCD_voidWriteCmd(0b01000000);

	/* write character */
	CLCD_voidWriteData(0b00001110);
	CLCD_voidWriteData(0b00010001);
	CLCD_voidWriteData(0b00001110);
	CLCD_voidWriteData(0b00000100);
	CLCD_voidWriteData(0b00001110);
	CLCD_voidWriteData(0b00000100);
	CLCD_voidWriteData(0b00001010);
	CLCD_voidWriteData(0b00010001);

	CLCD_voidWriteData(0b00001110);
	CLCD_voidWriteData(0b00010001);
	CLCD_voidWriteData(0b00001110);
	CLCD_voidWriteData(0b00000100);
	CLCD_voidWriteData(0b00001110);
	CLCD_voidWriteData(0b00000100);
	CLCD_voidWriteData(0b00001011);
	CLCD_voidWriteData(0b00010001);

	CLCD_voidWriteData(0b00001110);
	CLCD_voidWriteData(0b00010001);
	CLCD_voidWriteData(0b00001110);
	CLCD_voidWriteData(0b00000100);
	CLCD_voidWriteData(0b00001110);
	CLCD_voidWriteData(0b00000101);
	CLCD_voidWriteData(0b00001010);
	CLCD_voidWriteData(0b00010001);

	CLCD_voidWriteData(0b00001110);
	CLCD_voidWriteData(0b00010001);
	CLCD_voidWriteData(0b00001110);
	CLCD_voidWriteData(0b00000100);
	CLCD_voidWriteData(0b00001110);
	CLCD_voidWriteData(0b00000100);
	CLCD_voidWriteData(0b00011111);
	CLCD_voidWriteData(0b00000000);

	/* go to DDRAM address 0 */
	CLCD_voidWriteCmd(0b10000000);


	CLCD_voidGoToXYPos(5,0);
	CLCD_voidWriteString("Hello");

	CLCD_voidGoToXYPos(7,1);
	CLCD_voidWriteData(0);

	_delay_ms(1500);
	CLCD_voidWriteCmd(0b00000001);
	CLCD_voidWriteString("I'm Sharafanta7");
	CLCD_voidGoToXYPos(7,1);
	CLCD_voidWriteData(0);

	_delay_ms(1500);
	CLCD_voidWriteCmd(0b00000001);
	CLCD_voidGoToXYPos(2,0);
	CLCD_voidWriteString("I can play");
	CLCD_voidGoToXYPos(7,1);
	CLCD_voidWriteData(1);

	_delay_ms(1000);
	for(counter=0;counter<6;counter++)
	{
		_delay_ms(500);
		CLCD_voidWriteCmd(0b00000001);
		CLCD_voidGoToXYPos(4,0);
		CLCD_voidWriteString("Football");
		CLCD_voidGoToXYPos(7,1);
		CLCD_voidWriteData(1);

		_delay_ms(500);
		CLCD_voidWriteCmd(0b00000001);
		CLCD_voidGoToXYPos(4,0);
		CLCD_voidWriteString("Football");
		CLCD_voidGoToXYPos(7,1);
		CLCD_voidWriteData(2);
	}


	for(counter=0;counter<6;counter++)
	{
		_delay_ms(500);
		CLCD_voidWriteCmd(0b00000001);
		CLCD_voidGoToXYPos(2,0);
		CLCD_voidWriteString("I can dance");
		CLCD_voidGoToXYPos(7,1);
		CLCD_voidWriteData(0);

		_delay_ms(500);
		CLCD_voidWriteCmd(0b00000001);
		CLCD_voidGoToXYPos(2,0);
		CLCD_voidWriteString("I can dance");
		CLCD_voidGoToXYPos(7,1);
		CLCD_voidWriteData(3);
	}

	_delay_ms(500);
	CLCD_voidWriteCmd(0b00000001);
	CLCD_voidGoToXYPos(3,0);
	CLCD_voidWriteString("Thank You");
	CLCD_voidGoToXYPos(7,1);
	CLCD_voidWriteData(0);
}


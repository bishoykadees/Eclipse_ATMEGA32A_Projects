/*
 * main.c
 *
 *  Created on: Dec 10, 2019
 *      Author: Lenovo
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

void main(void)
{
	u8 switchState;

	/* set A0 Direction to input*/
	setPinDir('A',0,0);

	/* set A1 Direction to output*/
	setPinDir('A',1,1);


	while(1)
	{
		switchState=getSwitchState();
		if(switchState==0)
		{
			setLedOff();
		}
		else
		{
			setLedOn();
		}
	}
}

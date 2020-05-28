/*
 * main.c
 *
 *  Created on: Dec 10, 2019
 *      Author: Lenovo
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "LED_interface.h"
#include "SWITCH_interface.h"
#include "DIO_register.h"

void main(void)
{
	u8 switchState;

	/* initializing the PORTS*/
	portInit();

	while(1)
	{
		switchState=getSwitchState();
		if(switchState==0)
		{
			setLedOn();
		}
		else
		{
			setLedOff();
		}
	}
}

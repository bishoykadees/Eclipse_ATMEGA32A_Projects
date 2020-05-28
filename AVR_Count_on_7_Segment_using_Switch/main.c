/*
 * main.c
 *
 *  Created on: Dec 19, 2019
 *      Author: Nada
 */

#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
//#include "DELAY_MS_interface.h"
#include "DIO_interface.h"

#include "PORT_interface.h"

#include "SWITCH_interface.h"

#include "SevenSegment_interface.h"
#include <util/delay.h>
void main()
{
	s8 counter=0;
	PortInitialize();
	SEVENSEG_Enable(0);

	while(1)
	{
		while(getSwitchState()==0x01);
		SEVENSEG_SetNumber(++counter);
		while(getSwitchState()==0x00);
		if(counter==9)
		{
			counter=-1;
		}
	}


}

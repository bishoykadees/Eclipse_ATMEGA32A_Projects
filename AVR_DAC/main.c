#define F_CPU 8000000UL
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "PORT_register.h"
void main(void)
{
	u8 counter=0;

	portInit();

	while(1)
	{
	for(counter=0;counter<255;counter++)
	{
		PORTB=counter;
	}
	for(counter=0;counter<255;counter++)
	{
		PORTB=255-counter;
	}
	}
}

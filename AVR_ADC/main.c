#define F_CPU 8000000UL
#include <stdlib.h>
#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "ADC_interface.h"

void main(void)
{
	char *a;
	u8 Local_u8Data = '0';
	portInit();
	CLCD_voidInitialize();
	ADC_voidInit();

	while(1)
	{
		_delay_ms(500);
		Local_u8Data = ADC_u8GetChannelReading(0);
		Local_u8Data = (((f32)Local_u8Data)/(f32)255)*(f32)25;
		Local_u8Data = Local_u8Data + 2;
		itoa(Local_u8Data,a,10);
		CLCD_voidWriteCmd(1);
		CLCD_voidWriteString(a);

	}
}

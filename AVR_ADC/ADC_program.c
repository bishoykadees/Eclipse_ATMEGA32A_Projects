#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "ADC_interface.h"
#include "ADC_interface.h"
#include "ADC_register.h"
void ADC_voidInit (void)
{
	/*8-bits mode AVCC ref voltage, Polling (not interrupt)*/

	/*AVCC reference voltage*/
	CLR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);
	/*Activate Left adjustment mode*/
	SET_BIT(ADMUX,5);
	/*ADC Enable*/
	SET_BIT(ADCSRA,7);
	/*slowest ADC clk (maximum prescaler value=128) */
	SET_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);
}
u8 ADC_u8GetChannelReading (u8 channel)
{

	ADMUX&=0b11100000;
	ADMUX |=channel;
	/*start conversion*/
	SET_BIT(ADCSRA,6);
	while (!(GET_BIT(ADCSRA,4)));
	/*clear flag*/
	SET_BIT(ADCSRA,4);
	/*get result*/
	return ADCH;
}


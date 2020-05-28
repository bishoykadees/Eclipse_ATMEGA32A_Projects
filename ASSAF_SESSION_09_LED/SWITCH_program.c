#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SWITCH_interface.h"
#include "SWITCH_private.h"
#include "SWITCH_config.h"

u8 getSwitchState(void)
{
	u8 result;
	result=getPinValue(SWITCH_PORT,SWITCH_PIN);
	#if RELEASE_STATE==0
	{
		return result;
	}
	#else
	{
		return result^0x01;
	}
	#endif
}

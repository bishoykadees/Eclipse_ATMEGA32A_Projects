#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SWITCH_interface.h"
#include "SWITCH_private.h"
#include "SWITCH_config.h"

u8 SWITCH_Port_Arr[]={SWITCH_ONE_PORT,SWITCH_TWO_PORT,SWITCH_THREE_PORT,SWITCH_FOUR_PORT};
u8 SWITCH_Pin_Arr[]={SWITCH_ONE_PIN,SWITCH_TWO_PIN,SWITCH_THREE_PIN,SWITCH_FOUR_PIN};

u8 getSwitchState(u8 SWITCH_Number)
{
	u8 result;
	result=getPinValue(SWITCH_Port_Arr[SWITCH_Number],SWITCH_Pin_Arr[SWITCH_Number]);
	#if RELEASE_STATE==1
	{
		return result;
	}
	#else
	{
		return result^0x01;
	}
	#endif
}

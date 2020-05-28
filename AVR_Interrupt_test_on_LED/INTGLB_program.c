#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "INTGLB_reg.h"
#include "INTGLB_interface.h"

void INT_voidEnableGlobal(void)
{
	SET_BIT(SREG,SREG_I);
}
void INT_voidDisableGlobal(void)
{
	CLR_BIT(SREG,SREG_I);
}

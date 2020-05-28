#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "UART_interface.h"

void main(void)
{
	portInit();
	UART_voidInitialize();

}

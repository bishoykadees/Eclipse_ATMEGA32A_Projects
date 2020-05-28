#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"UART_interface.h"
#include"UART_register.h"
#include"UART_private.h"
#include"UART_config.h"

const u8 BaudRateValue[3][3] =
{
	/* 4800 , 9600 , 115200 */
	{  0x67 , 0x33 ,   0x03  }, /* clock system 0 = 8MHz */
	{  154  ,  77  ,     6   }, /* clock system 1 = 12MHz */
	{  0xCF , 0x67 ,   0x08  }  /* clock system 2 = 16MHz */
};

void (*EndOfTransmitCB)(void);
void (*EndOfReceiveCB)(u8);

void UART_voidInit(void)
{
	/* U2X = 0 */
	CLR_BIT(UCSRA,1);

	/* Disable all UART interrupts */
	/* Enable RX and TX */
	/* character size 8 bits */
	UCSRB = 0x18;

	/* Asynchronous Mode  */
	/* character size 8 bits */
	/*  */
	UCSRC = ((1<<7)|(UART_U8_PARITY<<4)|(UART_U8_STOP_BITS<<3)|(3<<1));

	/* Assign Baud Rate */
	UBRRL = BaudRateValue[UART_U8_SYS_FREQ][UART_U8_BAUD_RATE];

}

u8 UART_voidTransmitDataSynch(u8 Copy_u8Data)
{
	u32 Local_u32Timeout = 0;
	u8 Local_u8Error = OK;

	/* send data on UDR */
	UDR_T = Copy_u8Data;

	/* wait till flag is raised */
	while((GET_BIT(UCSRA,6) == 0)&&(Local_u32Timeout < UART_U32_TIME_OUT_TH))
	{
		Local_u32Timeout++;
	}

	/* timeout happened */
	if(Local_u32Timeout >= UART_U32_TIME_OUT_TH)
	{
		Local_u8Error = NOK;
	}
	else
	{
		/* clear flag */
		SET_BIT(UCSRA,6);
	}
	return Local_u8Error;
}

void UART_voidTransmitDataAsynch(u8 Copy_u8Data, void(*Copy_ptr)(void))
{
	/* enable TX interrupt */
	SET_BIT(UCSRB,6);

	/* set received data to UDR */
	UDR_T = Copy_u8Data;

	/* save the call back address */
	EndOfTransmitCB = Copy_ptr;
}
u8 UART_u8RecieveSynch(u8* Copy_pu8Data)
{
	u32 Local_u32Timeout = 0;
	u8 Local_u8Error = OK;

	/* wait till flag is raised */
	while((GET_BIT(UCSRA,7) == 0)&&(Local_u32Timeout < UART_U32_TIME_OUT_TH))
	{
		Local_u32Timeout++;
	}

	/* timeout happened */
	if(Local_u32Timeout >= UART_U32_TIME_OUT_TH)
	{
		Local_u8Error = NOK;
	}
	else
	{
		/* set data to received pointer */
		*Copy_pu8Data = UDR_R;
	}
	return Local_u8Error;
}

void UART_u8RecieveSynch(void(*Copy_ptr)(u8))
{
	/* check if there is data to receive */
	if(GET_BIT(UCSRA,7) == 1)
	{
		Copy_ptr(UDR);
	}
	/* nothing to receive now, enable receive interrupt */
	else
	{
		/* enable RX interrupt */
		SET_BIT(UCSRB,7);

		/* save call back in global variable */
		EndOfReceiveCB = Copy_ptr;
	}





}

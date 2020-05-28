/*****************************************************************/
/* Author    : Ahmed Assaf                                       */
/* Date      : 9 March 2020                                      */
/* Version   : V01                                               */
/*****************************************************************/
#ifndef _UART_INTERFACE_H
#define _UART_INTERFACE_H

void   UART_voidInitialize(void);
u8     UART_u8TransmitDataSynch   (u8 Copy_u8Data);
void UART_voidTransmitDataAsynch  (u8 Copy_u8Data, void(*Copy_ptr)(void));

u8     UART_u8ReceiveSynch  (u8* Copy_pu8Data);
void   UART_u8ReceiveAsynch ( void(*Copy_ptr)(u8) );

#endif

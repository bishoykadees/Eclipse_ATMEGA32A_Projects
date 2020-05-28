#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void UART_voidInit(void);
void UART_voidTransmitDataSynch(u8 Copy_u8Data);
void UART_voidTransmitDataAsynch(u8 Copy_u8Data, void(*Copy_ptr)(void));
u8 UART_u8RecieveSynch(u8* Copy_pu8Data);
void UART_u8RecieveSynch(void(*Copy_ptr)(u8));

#endif

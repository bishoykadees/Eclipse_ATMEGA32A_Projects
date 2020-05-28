/**************************************************************/
/* Author  : Bishoy Nabil                                     */
/* Version : V01                                              */
/* Date    : 14 Jan 2020                                      */
/**************************************************************/

/* Description: This API shall intialize LCD */
void CLCD_voidInitialize(void);

/* Description: This API shall display data on LCD */
void CLCD_voidWriteData(u8 Copy_u8Data);

/* Description: This API shall execute command on LCD */
void CLCD_voidWriteCmd(u8 Copy_u8Cmd);
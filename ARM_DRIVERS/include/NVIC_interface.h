/********************************************************************************/
/* Author  : Bishoy Nabil                                                       */
/* Date    : 2 Feb 2020                                                         */
/* Version : V01                                                                */
/********************************************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

typedef struct
{
	u8 ID;                  /* 0 - 239 */
	u8 EnableBit;           /* 1->Enable, 0->Disable */
	u8 PendingFlag;         /* 1->Enable, 0->Disable */
	u8 ActiveStatus;        /* 1->Active, 0->NotActive */
	u8 Priority;            /* 0x00 - 0xFF */
	u8 PriorityGroupzbits;
}NVIC_t;

#define WWDG                              0
#define PVD                               1
#define TAMPER                            2
#define RTC                               3
#define FLASH                             4
#define RCC                               5
#define EXTI0                             6
#define EXTI1                             7
#define EXTI2                             8
#define EXTI3                             9
#define EXTI4                             10
#define DMA1_CHANNEL1                     11
#define DMA1_CHANNEL2                     12
#define DMA1_CHANNEL3                     13
#define DMA1_CHANNEL4                     14
#define DMA1_CHANNEL5                     15
#define DMA1_CHANNEL6                     16
#define DMA1_CHANNEL7                     17
#define ADC1_2                            18
#define CAN1_TX                           19
#define CAN1_RX0                          20
#define CAN1_RX1                          21
#define CAN1_SCE                          22
#define EXTI9_5                           23
#define TIM1_BRK                          24
#define TIM1_UP                           25
#define TIM1_TRG_COM                      26
#define TIM1_CC                           27
#define TIM2                              28
#define TIM3                              29
#define TIM4                              30
#define I2C1_EV                           31
#define I2C1_ER                           32
#define I2C2_EV                           33
#define I2C2_ER                           34
#define SPI1                              35
#define SPI2                              36
#define USART1                            37
#define USART2                            38
#define USART3                            39
#define EXTI15_10                         40
#define RTCALARM                          41
#define OTG_FS_WKUP                       42
#define TIM5                              50
#define SPI3                              51
#define UART4                             52
#define UART5                             53
#define TIM6                              54
#define TIM7                              55
#define DMA2_CHANNEL1                     56
#define DMA2_CHANNEL2                     57
#define DMA2_CHANNEL3                     58
#define DMA2_CHANNEL4                     59
#define DMA2_CHANNEL5                     60
#define ETH                               61
#define ETH_WKUP                          62
#define CAN2_TX                           63
#define CAN2_RX0                          64
#define CAN2_RX1                          65
#define CAN2_SCE                          66
#define OTG_FS                            67

#define ENABLE                            1
#define DISABLE                           0

#define PRIORITYGROUPEQUALS_0             0x00000000
#define PRIORITYGROUPEQUALS_1             0x00000100
#define PRIORITYGROUPEQUALS_2             0x00000200
#define PRIORITYGROUPEQUALS_3             0x00000300
#define PRIORITYGROUPEQUALS_4             0x00000400
#define PRIORITYGROUPEQUALS_5             0x00000500
#define PRIORITYGROUPEQUALS_6             0x00000600
#define PRIORITYGROUPEQUALS_7             0x00000700


ErrorStatus NVIC_ControlEnableInterrupt   (NVIC_t *Copy_NVICStruct);
ErrorStatus NVIC_ControlPendingFlag       (NVIC_t *Copy_NVICStruct);
ErrorStatus NVIC_InterruptActiveStatus    (NVIC_t *Copy_NVICStruct);
ErrorStatus NVIC_SetInterruptPriority     (NVIC_t *Copy_NVICStruct);
ErrorStatus NVIC_GetInterruptPriority     (NVIC_t *Copy_NVICStruct);
ErrorStatus NVIC_SetPriorityGroupBits     (NVIC_t *Copy_NVICStruct);
ErrorStatus NVIC_ControlAllInterrupts     (NVIC_t *Copy_NVICStruct);
ErrorStatus NVIC_ControlAllFaults         (NVIC_t *Copy_NVICStruct);
ErrorStatus NVIC_SetPriorityFilter        (NVIC_t *Copy_NVICStruct);
ErrorStatus NVIC_GenerateSoftwareInterrupt(NVIC_t *Copy_NVICStruct);




void NVIC_voidEnableExtInt (u8 copy_u8Idx);
void NVIC_voidDisableExtInt (u8 copy_u8Idx);

void NVIC_voidSetPendingFlag (u8 copy_u8Idx);
void NVIC_voidClrPendingFlag (u8 copy_u8Idx);

u8 NVIC_u8GetActiveFlag (u8 copy_u8Idx);

#endif

/*tarteeb el inclusion:
el libraries
el layers ely ta7tya
el files bt3ty
*/

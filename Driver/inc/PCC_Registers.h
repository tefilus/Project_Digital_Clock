/****************************************************************************************************
*   @file    PCC_Registers.h
*   @author  Ma Hien Nhan
*   @brief   Header File of Peripheral Clock Controller(PCC) module. 
*   @version 1.0.0
*   @date    2024-8-26
****************************************************************************************************/

/*==================================================================================================
==================================================================================================*/
#ifndef PCC_REGISTER_H
#define PCC_REGISTER_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Utilitie.h"

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** Peripheral Clock Controller base address */
#define PCC_BASE                               (0x40065000u + 0x80)

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          struct name demo_t
* @details        This structure is .....
*
*/

/** PCC - Register Layout Typedef */
typedef struct {
    volatile uint32 PCC_FTFC;            /*!< PCC FTFC Register,                         Address offset: 0x80 */
	volatile uint32 PCC_DMAMUX;          /*!< PCC DMAMUX Register,                       Address offset: 0x84 */
    uint32 RESERVED_1[2];                /*!< Reserved, 0x88-0x8C */
	volatile uint32 PCC_FlexCAN0;        /*!< PCC FlexCAN0 Register,                     Address offset: 0x90 */
	volatile uint32 PCC_FlexCAN1;        /*!< PCC FlexCAN1 Register,                     Address offset: 0x94 */
    volatile uint32 PCC_FTM3;            /*!< PCC FTM3 Register,                         Address offset: 0x98 */
	volatile uint32 PCC_ADC1;            /*!< PCC ADC1 Register,                         Address offset: 0x9C */
    uint32 RESERVED_2[3];                /*!< Reserved, 0xA0-0xA8 */
    volatile uint32 PCC_FlexCAN2;        /*!< PCC FlexCAN2 Register,                     Address offset: 0xAC */
	volatile uint32 PCC_LPSPIO;          /*!< PCC LPSPIO Register,                       Address offset: 0xB0 */
    volatile uint32 PCC_LPSPI1;          /*!< PCC LPSPI1 Register,                       Address offset: 0xB4 */
	volatile uint32 PCC_LPSPI2;          /*!< PCC LPSPI2 Register,                       Address offset: 0xB8 */
    uint32 RESERVED_3[2];                /*!< Reserved, 0xBC - 0xC0 */
    volatile uint32 PCC_PDB1;            /*!< PCC PDB1 Register,                         Address offset: 0xC4 */
	volatile uint32 PCC_CRC;             /*!< PCC CRC Register,                          Address offset: 0xC8 */
    uint32 RESERVED_4[3];                /*!< Reserved, 0xCC - 0xD4 */
    volatile uint32 PCC_PDB0;            /*!< PCC PDB0 Register,                         Address offset: 0xD8 */
	volatile uint32 PCC_LPIT;            /*!< PCC LPIT Register,                         Address offset: 0xDC */
    volatile uint32 PCC_FTM0;            /*!< PCC FTM0 Register,                         Address offset: 0xE0 */
	volatile uint32 PCC_FTM1;            /*!< PCC FTM1 Register,                         Address offset: 0xE4 */
    volatile uint32 PCC_FTM2;            /*!< PCC FTM2 Register,                         Address offset: 0xE8 */
	volatile uint32 PCC_ADC0;            /*!< PCC ADC0 Register,                         Address offset: 0xEC */
    uint32 RESERVED_5[1];                /*!< Reserved, 0xF0 */
    volatile uint32 PCC_RTC;             /*!< PCC RTC Register,                          Address offset: 0xF4 */
    uint32 RESERVED_6[2];                /*!< Reserved, 0xF8 - 0xFC */
	volatile uint32 PCC_LPTMR0;          /*!< PCC LPTMR0 Register,                       Address offset: 0x100 */
    uint32 RESERVED_7[8];                /*!< Reserved, 0x104 - 0x120 */
    volatile uint32 PCC_PORTA;           /*!< PCC PORTA Register,                        Address offset: 0x124 */
    volatile uint32 PCC_PORTB;           /*!< PCC PORTB Register,                        Address offset: 0x128 */
    volatile uint32 PCC_PORTC;           /*!< PCC PORTC Register,                        Address offset: 0x12C */
    volatile uint32 PCC_PORTD;           /*!< PCC PORTD Register,                        Address offset: 0x130 */
    volatile uint32 PCC_PORTE;           /*!< PCC PORTE Register,                        Address offset: 0x134 */
    uint32 RESERVED_8[6];                /*!< Reserved, 0x138 - 0x14C */
    volatile uint32 PCC_SAI0;            /*!< PCC SAI0 Register,                         Address offset: 0x150 */
    volatile uint32 PCC_SAI1;            /*!< PCC SAI1 Register,                         Address offset: 0x154 */
    uint32 RESERVED_9[4];                /*!< Reserved, 0x158 - 0x164 */
    volatile uint32 PCC_FlexIO;          /*!< PCC FlexIO Register,                       Address offset: 0x168 */
    uint32 RESERVED_10[6];               /*!< Reserved, 0x16C - 0x180 */
	volatile uint32 PCC_EWM;             /*!< PCC EWM Register,                          Address offset: 0x184 */
    uint32 RESERVED_11[4];               /*!< Reserved, 0x188 - 0x194 */
    volatile uint32 PCC_LPI2C0;          /*!< PCC LPI2C0 Register,                       Address offset: 0x198 */
    volatile uint32 PCC_LPI2C1;          /*!< PCC LPI2C1 Register,                       Address offset: 0x19C */
    uint32 RESERVED_12[2];               /*!< Reserved, 0x1A0 - 0x1A4*/
    volatile uint32 PCC_LPUART0;         /*!< PCC LPUART0 Register,                      Address offset: 0x1A8 */
    volatile uint32 PCC_LPUART1;         /*!< PCC LPUART1 Register,                      Address offset: 0x1AC */
    volatile uint32 PCC_LPUART2;         /*!< PCC LPUART2 Register,                      Address offset: 0x1B0 */
    uint32 RESERVED_13[1];               /*!< Reserved, 0x1B4 */
    volatile uint32 PCC_FTM4;            /*!< PCC FTM4 Register,                         Address offset: 0x1B8 */
    volatile uint32 PCC_FTM5;            /*!< PCC FTM5 Register,                         Address offset: 0x1BC */
    volatile uint32 PCC_FTM6;            /*!< PCC FTM6 Register,                         Address offset: 0x1C0 */
    volatile uint32 PCC_FTM7;            /*!< PCC FTM7 Register,                         Address offset: 0x1C4 */
    uint32 RESERVED_14[1];               /*!< Reserved, 0x1C8 */
    volatile uint32 PCC_CMP0;            /*!< PCC CMP0 Register,                         Address offset: 0x1CC */
    uint32 RESERVED_15[2];               /*!< Reserved, 0x1D0 - 0x1D4 */
    volatile uint32 PCC_QSPI;            /*!< PCC QSPI Register,                         Address offset: 0x1D8 */
    uint32 RESERVED_16[2];               /*!< Reserved, 0x1DC - 0x1E0 */
    volatile uint32 PCC_ENET;            /*!< PCC ENET Register,                         Address offset: 0x1E4 */
} PCC_Type;

/** Peripheral Clock Controller base pointer */
#define PCC    ((PCC_Type *)PCC_BASE)

#endif /* PCC_REGISTER_H */





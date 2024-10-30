/****************************************************************************************************
* @file     Port_Registers.h
* @author   Ma Hien Nhan
* @brief    This file contains the structure definition for PORT_Type, representing the Port 
*           registers in ARM Cortex-M microcontrollers.
* @details  The PORT_Type structure is used to manage GPIO (General Purpose Input/Output) 
*           settings, including data direction, output data, input data, and interrupt 
*           configuration for the GPIO pins.
* @version  1.0.0
* @date     2024-09-18
****************************************************************************************************/


/*==================================================================================================
==================================================================================================*/
#ifndef PORT_REGISTER_H
#define PORT_REGISTER_H


/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Utilitie.h"


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/****** Represent a state where a feature or functionality ******/
/** PORT - Size of Registers Arrays */
#define PORT_PCR_COUNT                           32u

/** Peripheral PORT base address */
#define PORTA_BASE                               (0x40049000u)        /** Peripheral PORTC base address */
#define PORTB_BASE                               (0x4004A000u)        /** Peripheral PORTC base address */
#define PORTC_BASE                               (0x4004B000u)        /** Peripheral PORTC base address */
#define PORTD_BASE                               (0x4004C000u)        /** Peripheral PORTD base address */
#define PORTE_BASE                               (0x4004D000u)        /** Peripheral PORTC base address */


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief     PORT - Register Layout Typedef
 * @details   This structure represents the General Purpose Input/Output (GPIO) 
 *            registers for the PORT in ARM Cortex-M microcontrollers. It includes 
 *            Pin Control Registers that allow for configuration of GPIO pins, 
 *            including setting the pin mode, pull-up/pull-down settings, and 
 *            interrupt configurations.
 */
typedef struct {
    volatile unsigned int PCR[PORT_PCR_COUNT];  /**< Pin Control Register n, array offset: 0x0, array step: 0x4 */
} PORT_Type;

/** Peripheral PORT base pointer */
#define PORTA       ((PORT_Type *)PORTA_BASE)
#define PORTB       ((PORT_Type *)PORTB_BASE)
#define PORTC       ((PORT_Type *)PORTC_BASE)
#define PORTD       ((PORT_Type *)PORTD_BASE)
#define PORTE       ((PORT_Type *)PORTE_BASE)

/**
 * @brief     PORT_PCR_REG - Register Layout Typedef
 * @details   This structure represents individual Pin Control Registers (PCR) for each GPIO pin,
 *            allowing for configuration of pin settings such as pin mode and interrupt configurations.
 */
typedef struct {
			volatile unsigned int PCR0;             /**< Pin Control Register 0 */
			volatile unsigned int PCR1;             /**< Pin Control Register 1 */
			volatile unsigned int PCR2;             /**< Pin Control Register 2 */
			volatile unsigned int PCR3;             /**< Pin Control Register 3 */
			volatile unsigned int PCR4;             /**< Pin Control Register 4 */
			volatile unsigned int PCR5;             /**< Pin Control Register 5 */
			volatile unsigned int PCR6;             /**< Pin Control Register 6 */
			volatile unsigned int PCR7;             /**< Pin Control Register 7 */
			volatile unsigned int PCR8;             /**< Pin Control Register 8 */
			volatile unsigned int PCR9;             /**< Pin Control Register 9 */
			volatile unsigned int PCR10;            /**< Pin Control Register 10 */
			volatile unsigned int PCR11;            /**< Pin Control Register 11 */
			volatile unsigned int PCR12;            /**< Pin Control Register 12 */
			volatile unsigned int PCR13;            /**< Pin Control Register 13 */
			volatile unsigned int PCR14;            /**< Pin Control Register 14 */
			volatile unsigned int PCR15;            /**< Pin Control Register 15 */
			volatile unsigned int PCR16;            /**< Pin Control Register 16 */
			volatile unsigned int PCR17;            /**< Pin Control Register 17 */
			volatile unsigned int PCR18;            /**< Pin Control Register 18 */
			volatile unsigned int PCR19;            /**< Pin Control Register 19 */
			volatile unsigned int PCR20;            /**< Pin Control Register 20 */
			volatile unsigned int PCR21;            /**< Pin Control Register 21 */
			volatile unsigned int PCR22;            /**< Pin Control Register 22 */
			volatile unsigned int PCR23;            /**< Pin Control Register 23 */
			volatile unsigned int PCR24;            /**< Pin Control Register 24 */
			volatile unsigned int PCR25;            /**< Pin Control Register 25 */
			volatile unsigned int PCR26;            /**< Pin Control Register 26 */
			volatile unsigned int PCR27;            /**< Pin Control Register 27 */
			volatile unsigned int PCR28;            /**< Pin Control Register 28 */
			volatile unsigned int PCR29;            /**< Pin Control Register 29 */
			volatile unsigned int PCR30;            /**< Pin Control Register 30 */
			volatile unsigned int PCR31;            /**< Pin Control Register 31 */
} PORT_PCR_REG;

/** Peripheral PORT_PCR base pointer */
#define PORTA_PCR    ((PORT_PCR_REG *)PORTA_BASE)
#define PORTB_PCR    ((PORT_PCR_REG *)PORTB_BASE)
#define PORTC_PCR    ((PORT_PCR_REG *)PORTC_BASE)
#define PORTD_PCR    ((PORT_PCR_REG *)PORTD_BASE)
#define PORTE_PCR    ((PORT_PCR_REG *)PORTE_BASE)

#endif  /* PORT_REGISTER_H */

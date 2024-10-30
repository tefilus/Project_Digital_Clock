/****************************************************************************************************
*   @file    Gpio_Registers.h
*   @author  Ma Hien Nhan
*   @brief   Header File of Gpio_Registers. 
*   @version 1.0.0
*   @date    2024-8-30
****************************************************************************************************/

/*==================================================================================================
==================================================================================================*/
#ifndef GPIO_REGISTER_H
#define GPIO_REGISTER_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Utilitie.h"

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/****** Represent a state where a feature or functionality ******/
/** Peripheral GPIO base address */
#define GPIOA_BASE           (0x400FF000u)
#define GPIOB_BASE           (0x400FF040u)
#define GPIOC_BASE           (0x400FF080u)
#define GPIOD_BASE           (0x400FF0C0u)
#define GPIOE_BASE           (0x400FF100u)

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          struct name GPIO_Type
* @details        This structure is GPIO - Register Layout Typedef
*
*/
typedef struct {
    volatile unsigned int PDOR;					/*!< Port Data Output Register,                 Address offset: 0x0 */
		volatile unsigned int PSOR;					/*!< Port Set Output Register,                  Address offset: 0x4 */
		volatile unsigned int PCOR;					/*!< Port Clear Output Register,                Address offset: 0x8 */
		volatile unsigned int PTOR;					/*!< Port Toggle Output Register,               Address offset: 0xC */
		volatile const unsigned int PDIR;		/*!< Port Data Input Register,                  Address offset: 0x10 */
		volatile unsigned int PDDR;					/*!< Port Data Direction Register,              Address offset: 0x14 */
		volatile unsigned int PIDR;					/*!< Port Input Disable Register,               Address offset: 0x18 */
} GPIO_Type;

/** Peripheral GPIO base pointer */
#define GPIOA    ((GPIO_Type *)GPIOA_BASE)
#define GPIOB    ((GPIO_Type *)GPIOB_BASE)
#define GPIOC    ((GPIO_Type *)GPIOC_BASE)
#define GPIOD    ((GPIO_Type *)GPIOD_BASE)
#define GPIOE    ((GPIO_Type *)GPIOE_BASE)

#endif /* Gpio_Registers */









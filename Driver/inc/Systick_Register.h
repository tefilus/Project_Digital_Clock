/****************************************************************************************************
* @file     Systick_Registers.h
* @author   Ma Hien Nhan
* @brief    Header file for SYSTICK peripheral registers.
* @details  This header file contains the definitions, macros, and structures for interfacing with 
*           the SYSTICK timer peripheral in ARM Cortex-M microcontrollers.
* @version  1.0.0
* @date     2024-10-05
****************************************************************************************************/

/*==================================================================================================
==================================================================================================*/
#ifndef SYSTICK_REG_H
#define SYSTICK_REG_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Utilitie.h"


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*** Peripheral SYSTICK base address ***/
#define SYSTICK_BASE_ADDRESS                    (0xE000E010u)


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief SYSTICK Register Structure.
 * 
 * This structure represents the SYSTICK timer registers, providing a way to access and control 
 * the SYSTICK timer functionality.
 */
typedef struct {
			volatile unsigned int CSR;          /**< Control and Status Register */
			volatile unsigned int RVR;          /**< Reload Value Register */
			volatile unsigned int CVR;          /**< Current Value Register */
			volatile unsigned int CALIB;        /**< Calibration Value Register */
} SYST_Type;

/** Peripheral SYSTICK base pointer */
#define SYST ((SYST_Type *)SYSTICK_BASE_ADDRESS)

#endif  /* SYSTICK_REG_H */  

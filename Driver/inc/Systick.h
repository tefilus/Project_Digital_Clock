/****************************************************************************************************
* @file     Systick.h
* @author   Ma Hien Nhan
* @brief    Header file for SYSTICK timer functionality.
* @details  This header file contains the definitions, structures, and function prototypes for 
*           initializing and controlling the SYSTICK timer in ARM Cortex-M microcontrollers.
* @version  1.0.0
* @date     2024-10-05
****************************************************************************************************/

/*==================================================================================================
==================================================================================================*/
#ifndef SYSTICK_H
#define SYSTICK_H
/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Systick_Register.h"


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*** Define function for Current Value Register ***/
#define CLEAR_SYST_CVR			(0u)             /* Clear the Current Value Register (CVR) */

/*** Define reset value for execution timing  ***/
#define RESET_TIMES_EXECUTE     (0)              /*  Reset value for timing execution, typically used for initializing counters */  

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief   SYSTICK Configuration structure.
 * 
 * @details This structure holds configuration parameters for the SYSTICK timer, including the clock 
 *          frequency, timer period, and interrupt enable status.
 * @note 		When initialize fSystick will be must divided 1000 (Hz -> kHz)
 */
typedef struct
{
			unsigned int fSystick;                      /*!< F clock source (kHz) */
			unsigned int period;                        /*!< Period of timer (ms) */
			unsigned char isInterruptEnabled;           /*!< Enable SysTick exception request */
			unsigned char RESERVE1[3];
} Systick_ConfigType;


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/*!
 * @brief Initializes the SYSTICK timer.
 * 
 * This function configures the SYSTICK timer based on the provided configuration structure. 
 * It sets the timer's period and enables the interrupt if specified.
 * 
 * @param[in] ConfigPtr Pointer to the Systick configuration structure.
 * @return void.
 * @note Ensure that the configuration settings are valid before calling this function.
 */
void Systick_Init(const Systick_ConfigType* ConfigPtr);

/*!
 * @brief Starts the SYSTICK timer.
 * 
 * This function enables the SYSTICK timer to start counting down from the configured value.
 * 
 * @return void.
 * @note Ensure that the SYSTICK timer has been initialized before calling this function.
 */
void Systick_Start(void);

/*!
 * @brief Stops the SYSTICK timer.
 * 
 * This function disables the SYSTICK timer, halting its operation.
 * 
 * @return void.
 * @note Ensure that the SYSTICK timer is running before calling this function to stop it.
 */
void Systick_Stop(void);

/*!
 * @brief Retrieves the current value of the SYSTICK counter.
 * 
 * This function returns the current value in the SYSTICK counter.
 * 
 * @return Current value of the SYSTICK counter.
 * @note The returned value may be affected by the timer's running state.
 */
unsigned int Systick_GetCounter(void);

/*!
 * @brief Delays for a specified number of milliseconds.
 * 
 * This function creates a blocking delay by using the SYSTICK timer for the specified duration.
 * 
 * @param[in] ms Delay duration in milliseconds.
 * @return void.
 * @note This function blocks the execution for the specified duration.
 * 		 Initializes the SysTick timer have value RELOAD = fSystick/1000 (~ period = 1ms)
 */
void Delay_Timer(unsigned int ms);

#endif   /* SYSTICK_H */

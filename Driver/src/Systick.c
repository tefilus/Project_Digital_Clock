/****************************************************************************************************
* @file    Systick.c
* @author  Ma Hien Nhan
* @brief   Implementation of SysTick timer functions.
* @details This file provides functions to initialize, start, stop, and use the SysTick timer.
* @version 1.0.0
* @date    2024-10-05
* @note    Ensure that the appropriate hardware configuration is set before calling these functions.
****************************************************************************************************/


/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Systick.h"


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*!
 * @brief Initializes the SysTick timer.
 * 
 * This function configures the SysTick timer based on the provided configuration structure.
 * 
 * @param[in] ConfigPtr Pointer to the SysTick configuration structure.
 * @return void.
 * @note Ensure that the appropriate clock source and settings are configured before calling this function.
 * 		 	 Tval (RELOAD) <= 16,777,215
 */
void Systick_Init(const Systick_ConfigType* ConfigPtr)
{
			unsigned int Tval;		/* RELOAD */
			/*** Step 1. Check parameter ***/
			
			/*** Step 2. Configuration for SysTick timer ***/
				/* Step 2.1. Disable the SysTick timer */
				SYST->CSR &= ~(ENABLEMENT << BIT0);
			
				/* Step 2.2. Setting the reload value */
					/*! Calculate RVR !*/
					if(ConfigPtr->period != 0)
					{
						Tval = (ConfigPtr->period * ConfigPtr->fSystick);		/* Convert seconds (ms) to clock ticks */
						SYST->RVR = Tval; 											/* Set the RELOAD value register */
					} else 
					{
						SYST->RVR = 0xFFFFFFu;
					}
			
				/* Step 2.3. Clear the current value */
				SYST->CVR = CLEAR_SYST_CVR;

				/* Step 2.4. Check whether timeout interrupt is set ?*/
				if (ConfigPtr->isInterruptEnabled != 0) 
				{
						SYST->CSR |= (ENABLEMENT << BIT1);  		/* Enable the SysTick interrupt */
				} else 
				{
						SYST->CSR &= ~(ENABLEMENT << BIT1);  		/* Disable the SysTick interrupt */
				}
}

/*!
 * @brief Starts the SYSTICK timer.
 * 
 * This function enables the SYSTICK timer to start counting down from the configured value.
 * 
 * @return void.
 * @note Ensure that the SYSTICK timer has been initialized before calling this function.
 */
void Systick_Start(void)
{
			/* Step 1. Enable the SysTick counter */
			SYST->CSR |= (ENABLEMENT << BIT0); 	 	/* Set the ENABLE bit to start the timer */
}

/*!
 * @brief Stops the SYSTICK timer.
 * 
 * This function disables the SysTick timer to stop counting., halting its operation.
 * 
 * @return void.
 * @note Ensure that the SYSTICK timer is running before calling this function to stop it.
 */
void Systick_Stop(void)
{
			/* Step 1. Disable the SysTick counter */
			SYST->CSR &= ~(ENABLEMENT << BIT0); 	 /* Clear the ENABLE bit to stop the timer */
}

/*!
 * @brief Retrieves the current value of the SYSTICK counter.
 * 
 * This function returns the current value in the SYSTICK counter.
 * 
 * @return Current value of the SYSTICK counter.
 * @note The returned value may be affected by the timer's running state.
 */
unsigned int Systick_GetCounter(void)
{
			/* Return the current value of the SysTick counter */
			return SYST->CVR;  		/* Read and return the current value from the Current Value Register */
}

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
void Delay_Timer(unsigned int ms)
{
			unsigned int count = 0;			/* Numbers of execute systick timer */
			while (1)
			{
					if ((CHECK_BIT(SYST->CSR, BIT16)))
					{
							count++;
					}
					if (count == ms)
					{
							count = RESET_TIMES_EXECUTE; 	/* Reset count after delay */
							break;
					}
			}
}

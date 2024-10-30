/****************************************************************************************************
*   @file    Nvic.c
*   @author  Ma Hien Nhan
*   @brief   This file contains the implementation of NVIC-related functions. 
*   @details This file provides functions for configuring and controlling the Nested Vectored Interrupt Controller (NVIC) 
*            on ARM Cortex-M microcontrollers. Functions include enabling/disabling interrupts, setting priorities, and more.
*   @version 1.0.0
*   @date    2024-9-13
*	@note 	 Make sure to include the CMSIS header file corresponding to your microcontroller to use the NVIC functions.
****************************************************************************************************/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Nvic.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief Enables a specified interrupt in the NVIC.
 *
 * This function enables the interrupt corresponding to the given IRQ number
 * by setting the appropriate bit in the NVIC Interrupt Set-enable Registers (ISER).
 *
 * @param[in] IRQ_number The IRQ number of the interrupt to be enabled.
 * @return None
 * 
 * @pre          The IRQ_number must be valid and within the range supported by the NVIC 
 * 
 * @api			This function is apart of API to control NVIC
 */
void NVIC_EnableInterrupt(IRQn_Type IRQ_number)
{
	/* Check parameter */
	NVIC_ISER->ISER[IRQ_number/32] = (1<<(IRQ_number%32));
}

/**
 * @brief Disables a specified interrupt in the NVIC.
 *
 * This function disables the interrupt corresponding to the given IRQ number
 * by clearing the appropriate bit in the NVIC Interrupt Clear-enable Registers (ICER).
 *
 * @param[in] IRQ_number The IRQ number of the interrupt to be disabled.
 * @return None
 * 
 * @pre          The IRQ_number must be valid and within the range supported by the NVIC 
 * 
 * @api			This function is apart of API to control NVIC
 */
void NVIC_DisableInterrupt(IRQn_Type IRQ_number)
{
	/* Check parameter */
	NVIC_ICER->ICER[IRQ_number/32] = (1<<(IRQ_number%32));
}

/**
 * @brief Clears the pending flag for a specified interrupt in the NVIC.
 *
 * This function clears the pending state for the interrupt corresponding
 * to the given IRQ number by writing to the appropriate bit in the NVIC
 * Interrupt Clear-pending Registers (ICPR).
 *
 * @param[in] IRQ_number The IRQ number of the interrupt whose pending flag
 *                       is to be cleared.
 * @return None
 * 
 * @pre          The IRQ_number must be valid and within the range supported by the NVIC 
 * 
 * @api			This function is apart of API to control NVIC
 */
void NVIC_ClearPendingFlag(IRQn_Type IRQ_number)
{
	/* Check parameter */
	NVIC_ICPR->ICPR[IRQ_number/32] = (1<<(IRQ_number%32));
}


/**
 * @brief Sets the priority of a specified interrupt in the NVIC.
 *
 * This function configures the priority level of the interrupt specified
 * by the IRQ number. The priority value is shifted into the appropriate
 * position in the Interrupt Priority Register (IPR).
 *
 * @param[in] IRQ_number The IRQ number of the interrupt whose priority
 *                       is to be set.
 * @param[in] priority The priority level to be assigned to the interrupt,
 *                     where a lower value indicates a higher priority. (0->15)
 * @return None
 * 
 * @pre          The IRQ_number must be valid and within the range supported by the NVIC 
 * 
 * @api			This function is apart of API to control NVIC
 */
void NVIC_SetPriority(IRQn_Type IRQ_number, unsigned char priority)
{
	/* Check parameter */
	NVIC_IPR->IPR[IRQ_number / 4] = ((priority & 0xFFu) << ((IRQ_number % 4) * 8 + 4));
}


/**
 * @brief Configures the settings for a specified interrupt in the NVIC.
 *
 * This function disables the specified interrupt, clears any pending flags,
 * sets the priority, and then enables the interrupt. It is useful for
 * initializing the interrupt's settings in one call while ensuring that
 * previous states do not interfere.
 *
 * @param[in] IRQ_number The IRQ number of the interrupt to configure.
 * @param[in] priority The priority level to assign to the interrupt,
 *                     where a lower value indicates a higher priority.
 * @return None
 */
void NVIC_Settings(IRQn_Type IRQ_number, unsigned char priority)
{
	NVIC_DisableInterrupt(IRQ_number);
	NVIC_ClearPendingFlag(IRQ_number);
	NVIC_SetPriority(IRQ_number, priority);
	NVIC_EnableInterrupt(IRQ_number);
}

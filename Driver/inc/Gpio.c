/****************************************************************************************************
*   @file    Gpio.c
*   @author  Ma Hien Nhan
*   @brief   Gpio. 
*   @version 1.0.0
*   @date    2024-9-03
****************************************************************************************************/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Gpio.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief Initializes the pins with the given configuration structure
 *
 * This function configures the pins with the options provided in the
 * provided structure.
 *
 * @param[in] pinCount The number of configured pins in structure
 * @param[in] config The configuration structure
 * @return None
 */
void Gpio_Init(const Gpio_ConfigType* ConfigPtr)
{
    /* Check parameter */
		/* Configure the pin as input or output */
		if (ConfigPtr->GPIO_PinMode == OUTPUT) 
		{
			/* Set pin as output */
			SET_BIT(ConfigPtr->base->PDDR, ENABLEMENT, ConfigPtr->GPIO_PinNumber);
			//ConfigPtr->base->PDDR |= (ENABLEMENT << ConfigPtr->GPIO_PinNumber);
		} 
		else 
		{
			/* Set pin as input */
			CLEAR_BIT(ConfigPtr->base->PDDR, ENABLEMENT, ConfigPtr->GPIO_PinNumber);
		}
}

/**
 * @brief          Writes a value to a specified GPIO output pin.
 * 
 * This function writes either a HIGH (1) or LOW (0) value to the given GPIO pin.
 * 
 * @param[in]      pGPIOx Pointer to the GPIO base address.
 * @param[in]      PinNumber The number of the pin to write to.
 * @param[in]      value The value to write to the pin (e.g., HIGH or LOW).
 * @return None
 */
void GPIO_WriteToOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber, unsigned char value)
{
    /* Check parameter */
    if (value) 
		{
        /* Set pin HIGH */
        SET_BIT(pGPIOx->PDOR, ENABLEMENT, PinNumber);
		} 
		else 
		{
        /* Set pin LOW */
        CLEAR_BIT(pGPIOx->PDOR, ENABLEMENT, PinNumber);
		}
}

/**
 * @brief          Sets a specified GPIO output pin to HIGH.
 * @param[in]      pGPIOx Pointer to the GPIO base address.
 * @param[in]      PinNumber The number of the pin to set.
 * @return None
 */
void GPIO_SetOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber)
{
    /* Check parameter */

    /* Set pin HIGH */
    pGPIOx->PSOR = (ENABLEMENT << PinNumber);
}

/**
 * @brief          Resets a specified GPIO output pin to LOW.
 * @param[in]      pGPIOx Pointer to the GPIO base address.
 * @param[in]      PinNumber The number of the pin to reset.
 * @return None
 */
void GPIO_ResetOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber)
{
    /* Check parameter */

    /* Set pin LOW */
    pGPIOx->PCOR = (ENABLEMENT << PinNumber);
}

/**
 * @brief          Toggles the state of a specified GPIO output pin.
 * 
 * This function toggles the current state of the GPIO pin.
 * 
 * @param[in]      pGPIOx Pointer to the GPIO base address.
 * @param[in]      PinNumber The number of the pin to toggle.
 * @return None
 */
void GPIO_ToggleOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber)
{
    /* Check parameter */
    
    /* Toggle pin */
    /* pGPIOx->PDOR ^= (ENABLEMENT << PinNumber); */
    pGPIOx->PTOR = (ENABLEMENT << PinNumber);
}

/**
 * @brief          Reads the value from a specified GPIO input pin.
 * 
 * This function reads the state of the GPIO input pin.
 * 
 * @param[in]      pGPIOx Pointer to the GPIO base address.
 * @param[in]      PinNumber The number of the pin to read from.
 * @return         The value read from the pin (e.g., HIGH or LOW).
 */
unsigned char GPIO_ReadFromInputPin(GPIO_Type *pGPIOx, unsigned char PinNumber)
{
    /* Check parameter */

    /* Read the pin value */
	unsigned int pinState = pGPIOx->PDIR;

	/* Check if the specific pin is set */
	if (pinState & (ENABLEMENT << PinNumber))
	{
		return HIGH;  /* Return 1 if the pin is set high (logic level 1) */
	}
	else
	{
		return LOW;  /* Return 0 if the pin is not set (logic level 0) */ 
	}
}

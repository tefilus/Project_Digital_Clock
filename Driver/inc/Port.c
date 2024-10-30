/****************************************************************************************************
* @file    Port.c
* @author  Ma Hien Nhan
* @brief   Implementation of GPIO port initialization functions.
* @details This file contains functions to initialize GPIO port pins based on a given 
*          configuration structure. The configuration includes settings for pull resistors, 
*          drive strength, multiplexing, and interrupt generation conditions.
* @version 1.0.0
* @date    2024-09-19
* @note    Ensure that the appropriate hardware configuration is set before calling these functions.
****************************************************************************************************/


/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Port.h"


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*!
 * @brief Initializes the pins with the given configuration structure.
 *
 * This function configures the pins based on the settings provided in the 
 * configuration structure.
 *
 * @param[in] ConfigPtr Pointer to the configuration structure.
 * @return PORT_OK on success, PORT_ERR_PARA on parameter error.
 */
Port_ret_t Port_Init(const Port_ConfigType* ConfigPtr)
{
		Port_ret_t ret = PORT_OK;
		unsigned int regValue = ConfigPtr->base->PCR[ConfigPtr->pinPortIdx];
	
		/* Check parameter */
		if (ConfigPtr == NULL || ConfigPtr->pinPortIdx >= PORT_PCR_COUNT)
		{
					return PORT_ERR_PARA;  /* Return error if parameters are invalid */
		}
		
		/* 1. Internal resistor pull feature selection. */
		switch (ConfigPtr->pullConfig)
		{
			case PORT_NO_PULL_UP_DOWN:
				{
						regValue &= ~(ENABLEMENT << BIT1);
				}
				break;
			case PORT_PULL_DOWN:
				{
						regValue &= ~(ENABLEMENT << BIT0);
						regValue |= (ENABLEMENT << BIT1);
				}
				break;
			case PORT_PULL_UP:
				{
						regValue |= (ENABLEMENT << BIT0);
						regValue |= (ENABLEMENT << BIT1);
				}
				break;
		}

		/* 2. Configures the drive strength.*/
		if (ConfigPtr->driveSelect == PORT_LOW_DRV_STRENGTH)
		{
				regValue &= ~(ENABLEMENT << BIT6);
		}
		else if (ConfigPtr->driveSelect == PORT_HIGH_DRV_STRENGTH)
		{
				regValue &= ~(ENABLEMENT << BIT6);
				regValue |= (ENABLEMENT << BIT6);
		}

		/* 3. Mux selection. */
		regValue &= ~((ENABLEMENT << BIT8)|(ENABLEMENT << BIT9)|(ENABLEMENT << BIT10));
		regValue |= (unsigned int) (ConfigPtr->mux << BIT8);
		
		/* 4. Interrupt generation condition. */
		regValue &= ~((ENABLEMENT << BIT16)|(ENABLEMENT << BIT17)|(ENABLEMENT << BIT18)|(ENABLEMENT << BIT19));
		regValue |= (unsigned int) (ConfigPtr->intConfig << BIT16);

		/* Write the configured value back to the PCR register. */
		ConfigPtr->base->PCR[ConfigPtr->pinPortIdx] = regValue;
		
		/* Port Return Status Type */
		return ret;
}

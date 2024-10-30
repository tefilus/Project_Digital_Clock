/****************************************************************************************************
* @file    Clock.c
* @author  Ma Hien Nhan
* @brief   Implementation of clock configuration functions.
* @details This file provides functions to configure various clock sources and dividers for the
*          microcontroller system.
* @version 1.0.0
* @date    2024-10-01
* @note    Ensure that the appropriate hardware configuration is set before calling these functions.
****************************************************************************************************/


/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Clock.h"


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*!
 * @brief Set Peripheral Clock Control (PCC) configuration.
 * 
 * This function configures the Peripheral Clock Control (PCC) settings based on the provided 
 * configuration structure. It disables the peripheral clock, and if the clock gate control 
 * is enabled, it sets the appropriate peripheral clock source and re-enables the clock.
 * 
 * @param[in] ConfigPtr Pointer to the PCC configuration structure.
 * @return void.
 * @note Ensure that the appropriate clock source and settings are configured before calling this function.
 */
void Clock_SetPccConfig(const Pcc_ConfigType* ConfigPtr)
{
		/* 1. Disable the peripheral clock */
		PCC->PCCn[ConfigPtr->clockName] &=~ (ENABLEMENT << PCC_CGC_SHIFT);
		
		/* 2. Check whether Clock Gate Control is enable or disable */
		if( ConfigPtr->clkGate == CLK_GATE_ENABLE )
		{
			/* 2.1. Check whether Peripheral Clock Source Select is off or set */
			if(ConfigPtr->clkSrc != CLK_SRC_OFF)
			{
				/* Set Peripheral Clock Source Select */
				PCC->PCCn[ConfigPtr->clockName] |= ((unsigned int)ConfigPtr->clkSrc << PCC_PCS_SHIFT);
			}
			
			/* 2.2. Enable the peripheral clock */
			PCC->PCCn[ConfigPtr->clockName] |= (ENABLEMENT << PCC_CGC_SHIFT);
		}
}

/*!
 * @brief Set FIRC configuration.
 * 
 * This function configures the Fast Internal Reference Clock (FIRC) settings based on the provided 
 * configuration structure. It sets the clock dividers to control the frequency of the FIRC output.
 * 
 * @param[in] ConfigPtr Pointer to the FIRC configuration structure.
 * @return void.
 * @note Ensure that the FIRC settings are appropriate for your application before calling this function.
 */
void Clock_SetScgFircConfig(const Scg_Firc_ConfigType * ConfigPtr)
{
		/* Step 1. Setup dividers 1. */
		SCG->FIRCDIV |= ((unsigned int)(ConfigPtr->div1)<< SCG_FIRCDIV_FIRCDIV1_SHIFT);
		
		/* Step 2. Setup dividers 2. */
		SCG->FIRCDIV |= ((unsigned int)(ConfigPtr->div2)<< SCG_FIRCDIV_FIRCDIV2_SHIFT);
}

/*!
 * @brief Set SIRC configuration.
 * 
 * This function configures the Slow Internal Reference Clock (SIRC) settings based on the provided 
 * configuration structure. It sets the clock dividers to control the frequency of the SIRC output.
 * 
 * @param[in] ConfigPtr Pointer to the SIRC configuration structure.
 * @return void.
 * @note Ensure that the SIRC settings are appropriate for your application before calling this function.
 */
void Clock_SetScgSircConfig(const Scg_Sirc_ConfigType * ConfigPtr)
{
		/* Step 1. Setup dividers 1 */
		SCG->SIRCDIV |= ((unsigned int)(ConfigPtr->div1)<< SCG_SIRCDIV_SIRCDIV1_SHIFT);
		
		/* Step 2. Setup dividers 2. */
		SCG->SIRCDIV |= ((unsigned int)(ConfigPtr->div2)<< SCG_SIRCDIV_SIRCDIV2_SHIFT);
}

/*!
 * @brief Set SOSC configuration.
 * 
 * This function configures the System Oscillator (SOSC) settings based on the provided 
 * configuration structure. It sets the clock dividers and the range for the SOSC, enabling it for use.
 * 
 * @param[in] ConfigPtr Pointer to the SOSC configuration structure.
 * @return void.
 * @note Ensure that the SOSC settings are appropriate for your application before calling this function.
 */
void Clock_SetScgSoscConfig(const Scg_Sosc_ConfigType * ConfigPtr)
{
		/* Step 1. Setup dividers 1 */
		SCG->SOSCDIV |= ((unsigned int)(ConfigPtr->div1) << SCG_SOSCDIV_SOSCDIV1_SHIFT);
		
		/* Step 2. Setup dividers 2. */
		SCG->SOSCDIV |= ((unsigned int)(ConfigPtr->div2) << SCG_SOSCDIV_SOSCDIV2_SHIFT);
		
		/* Step 3. Set SOSC configuration. */
		SCG->SOSCCFG = ((unsigned int)(ConfigPtr->range) << SCG_SOSCCFG_RANGE_SHIFT)|(SCG_SOSCCFG_EREFS_IOSC << SCG_SOSCCFG_EREFS_SHIFT);
		
		/* Step 4. Clear Lock Register */
		SCG->SOSCCSR &= ((unsigned int) ~(ENABLEMENT << SCG_CSR_LK_SHIFT));
		
		/* Step 5. Enable SOSC clock*/
		SCG->SOSCCSR |= ((unsigned int)ENABLEMENT << BIT0);
		
		/* Step 6. Wait for System OSC to initialize */
		while(((SCG->SOSCCSR >> SCG_CSR_VLD_SHIFT) & VALUE_CHECK_BIT) != VALUE_CHECK_BIT)
		{
			/* Empty */
		}
}

/*!
 * @brief Set SPLL configuration.
 * 
 * This function configures the System PLL (SPLL) settings based on the provided 
 * configuration structure. It sets the reference clock divider, multiplier, and enables the PLL.
 * 
 * @param[in] ConfigPtr Pointer to the SPLL configuration structure.
 * @return void.
 * @note Ensure that the SPLL settings are appropriate for your application before calling this function.
 */
void Clock_SetScgSpllConfig(const Scg_Spll_ConfigType * ConfigPtr)
{
		/* Step 1. Disable SPLL */
		SCG->SPLLCSR &= (unsigned int) ~(ENABLEMENT);

		/* Step 2. Setup dividers 1 */
		SCG->SPLLDIV |= ((unsigned int)(ConfigPtr->div1) << SCG_SPLLDIV_SPLLDIV1_SHIFT);
		
		/* Step 2. Setup dividers 2. */
		SCG->SPLLDIV |= ((unsigned int)(ConfigPtr->div2) << SCG_SPLLDIV_SPLLDIV2_SHIFT);
		
		/* Step 3. Set PLL configuration. */
		SCG->SPLLCFG |= ((unsigned int)(ConfigPtr->src) << SCG_SPLLCFG_SOURCE_SHIFT);			/* System PLL source. */

		SCG->SPLLCFG |= ((unsigned int)(ConfigPtr->prediv) << SCG_SPLLCFG_PREDIV_SHIFT);	/* PLL Reference Clock Divider. */

		SCG->SPLLCFG |= ((unsigned int)(ConfigPtr->mult)  << SCG_SPLLCFG_MULT_SHIFT);		/* System PLL Multiplier. */

		/* Step 4. Clear Lock Register */
		SCG->SPLLCSR &= ((unsigned int) ~(ENABLEMENT << SCG_CSR_LK_SHIFT));

		/* Step 5. Enable SOSC clock*/
		SCG->SPLLCSR |= ((unsigned int)ENABLEMENT << BIT0);
		
		/* Step 6. Wait for SPLL to initialize */
		while(((SCG->SPLLCSR >> SCG_CSR_VLD_SHIFT) & VALUE_CHECK_BIT) != VALUE_CHECK_BIT)
		{
			/* Empty */
		}
}

/*!
 * @brief Set Run Mode configuration.
 * 
 * This function configures the Run Mode settings for the system clock based on the provided 
 * configuration structure. It sets the system clock source and dividers for core, bus, and slow clocks.
 * 
 * @param[in] ConfigPtr Pointer to the Run Mode configuration structure.
 * @return void.
 * @note Ensure that the Run Mode settings are appropriate for your application before calling this function.
 */
void Clock_SetScgRunModeConfig(const Scg_RunMode_ConfigType * ConfigPtr)
{
		/*** Step1. Sets the RUN clock control (system clock source, bus, core and slow dividers ***/
		unsigned int value = 0;
		
			/* Step1.1. Set system clock source */
			value |= ((unsigned int)ConfigPtr->sys_clk_src << SCG_RCCR_SCS_SHIFT);
		
			/* Step1.2. Set Core Clock Divide Ratio */
			value |= ((unsigned int)ConfigPtr->core_div << SCG_RCCR_DIVCORE_SHIFT);
		
			/* Step1.3. Set Bus Clock Divide Ratio */
			value |= ((unsigned int)ConfigPtr->bus_div << SCG_RCCR_DIVBUS_SHIFT);

			/* Step1.4. Set Slow Clock Divide Ratio */
			value |= ((unsigned int)ConfigPtr->slow_div << SCG_RCCR_DIVSLOW_SHIFT);
		
		SCG->RCCR = value;
		
		/*** Step 2. Cormfirm: System Clock Source as config ***/
		while(SCG->RCCR != value)
		{
			/* Empty */
		}
}

/*!
 * @brief Set High Speed Run Mode configuration.
 * 
 * This function configures the High Speed Run Mode settings for the system clock based on the provided 
 * configuration structure. It sets the system clock source and dividers for core, bus, and slow clocks.
 * 
 * @param[in] ConfigPtr Pointer to the High Speed Run Mode configuration structure.
 * @return void.
 * @note Ensure that the High Speed Run Mode settings are appropriate for your application before calling this function.
 */
void Clock_SetScgHSRunModeConfig(const Scg_HSRunMode_ConfigType * ConfigPtr)
{
		/*** Step1. Sets the HSRUN clock control (system clock source, bus, core and slow dividers ***/
		unsigned int value = 0;
		
			/* Step1.1. Set system clock source */
			value |= ((unsigned int)ConfigPtr->sys_clk_src << SCG_HCCR_SCS_SHIFT);
		
			/* Step1.2. Set Core Clock Divide Ratio */
			value |= ((unsigned int)ConfigPtr->core_div << SCG_HCCR_DIVCORE_SHIFT);
		
			/* Step1.3. Set Bus Clock Divide Ratio */
			value |= ((unsigned int)ConfigPtr->bus_div << SCG_HCCR_DIVBUS_SHIFT);

			/* Step1.4. Set Slow Clock Divide Ratio */
			value |= ((unsigned int)ConfigPtr->slow_div << SCG_HCCR_DIVSLOW_SHIFT);
		
		SCG->HCCR = value;
		
		/*** Step 2. Cormfirm: System Clock Source as config ***/
		while(SCG->HCCR != value)
		{
			/* Empty */
		}
}

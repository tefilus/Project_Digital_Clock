/****************************************************************************************************
* @file     Clock.h
* @author   Ma Hien Nhan
* @brief    Header file for clock configuration.
* @details  This header file contains definitions for clock sources, divide ratios, and functions 
*           to configure clocks for various peripherals.
* @version  1.0.0
* @date     2024-09-30
****************************************************************************************************/

/*==================================================================================================
==================================================================================================*/
#ifndef CLOCK_H
#define CLOCK_H


/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Clock_Registers.h"


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/***  Function for SCG_SOSC ***/
#define SCG_SOSCCFG_EREFS_ERC              (0u)               /* External reference clock selected */
#define SCG_SOSCCFG_EREFS_IOSC             (1u)               /* Internal crystal oscillator of OSC selected */


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
 * @brief   System clock sources.
 * @details Enumeration for the available system clock sources.
 */
typedef enum {
	    SOSC_CLK = 1u,              /*!< SOSC clock */
	    SIRC_CLK = 2u,              /*!< SIRC clock */
			FIRC_CLK = 3u,              /*!< FIRC clock */  
			SPLL_CLK = 6u,              /*!< SPLL clock */
}system_clock_source_t;


/**
 * @brief   System clock sources for HSRun.
 * @details Enumeration for the available system clock sources.
 */
typedef enum {
			HSRUN_FIRC_CLK = 3u,              /*!< FIRC clock */  
			HSRUN_SPLL_CLK = 6u,              /*!< SPLL clock */
}system_hsrun_clock_source_t;


/**
 * @brief   Core clock divide ratios.
 * @details Enumeration for different core clock divide ratios.
 */
typedef enum {
			CORE_CLK_DIV_BY_1     = 0u,          /*!< Divide-by-1 */
			CORE_CLK_DIV_BY_2     = 1u,          /*!< Divide-by-2 */
			CORE_CLK_DIV_BY_3     = 2u,          /*!< Divide-by-3 */
			CORE_CLK_DIV_BY_4     = 3u,          /*!< Divide-by-4 */
			CORE_CLK_DIV_BY_5     = 4u,          /*!< Divide-by-5 */
			CORE_CLK_DIV_BY_6     = 5u,          /*!< Divide-by-6 */
			CORE_CLK_DIV_BY_7     = 6u,          /*!< Divide-by-7 */
			CORE_CLK_DIV_BY_8     = 7u,          /*!< Divide-by-8 */
			CORE_CLK_DIV_BY_9     = 8u,          /*!< Divide-by-9 */
			CORE_CLK_DIV_BY_10    = 9u,          /*!< Divide-by-10 */
			CORE_CLK_DIV_BY_11    = 10u,         /*!< Divide-by-11 */
			CORE_CLK_DIV_BY_12    = 11u,         /*!< Divide-by-12 */
			CORE_CLK_DIV_BY_13    = 12u,         /*!< Divide-by-13 */
			CORE_CLK_DIV_BY_14    = 13u,         /*!< Divide-by-14 */
			CORE_CLK_DIV_BY_15    = 14u,         /*!< Divide-by-15 */
			CORE_CLK_DIV_BY_16    = 15u,         /*!< Divide-by-16 */
}core_clock_divide_ratio_t;


/**
 * @brief   Bus clock divide ratios.
 * @details Enumeration for different bus clock divide ratios.
 */
typedef enum {
			BUS_CLK_DIV_BY_1     = 0u,          /*!< Divide-by-1 */
			BUS_CLK_DIV_BY_2     = 1u,          /*!< Divide-by-2 */
			BUS_CLK_DIV_BY_3     = 2u,          /*!< Divide-by-3 */
			BUS_CLK_DIV_BY_4     = 3u,          /*!< Divide-by-4 */
			BUS_CLK_DIV_BY_5     = 4u,          /*!< Divide-by-5 */
			BUS_CLK_DIV_BY_6     = 5u,          /*!< Divide-by-6 */
			BUS_CLK_DIV_BY_7     = 6u,          /*!< Divide-by-7 */
			BUS_CLK_DIV_BY_8     = 7u,          /*!< Divide-by-8 */
			BUS_CLK_DIV_BY_9     = 8u,          /*!< Divide-by-9 */
			BUS_CLK_DIV_BY_10    = 9u,          /*!< Divide-by-10 */
			BUS_CLK_DIV_BY_11    = 10u,         /*!< Divide-by-11 */
			BUS_CLK_DIV_BY_12    = 11u,         /*!< Divide-by-12 */
			BUS_CLK_DIV_BY_13    = 12u,         /*!< Divide-by-13 */
			BUS_CLK_DIV_BY_14    = 13u,         /*!< Divide-by-14 */
			BUS_CLK_DIV_BY_15    = 14u,         /*!< Divide-by-15 */
			BUS_CLK_DIV_BY_16    = 15u,         /*!< Divide-by-16 */
}bus_clock_divide_ratio_t;


/**
 * @brief   Slow clock divide ratios.
 * @details Enumeration for different slow clock divide ratios.
 */
typedef enum {
			SLOW_CLK_DIV_BY_1    = 0u,          /*!< Divide-by-1 */
			SLOW_CLK_DIV_BY_2    = 1u,          /*!< Divide-by-2 */
			SLOW_CLK_DIV_BY_3    = 2u,          /*!< Divide-by-3 */
			SLOW_CLK_DIV_BY_4    = 3u,          /*!< Divide-by-4 */
			SLOW_CLK_DIV_BY_5    = 4u,          /*!< Divide-by-5 */
			SLOW_CLK_DIV_BY_6    = 5u,          /*!< Divide-by-6 */
			SLOW_CLK_DIV_BY_7    = 6u,          /*!< Divide-by-7 */
			SLOW_CLK_DIV_BY_8    = 7u,          /*!< Divide-by-8 */
}slow_clock_divide_ratio_t;


/**
 * @brief   Peripheral clock names.
 * @details Enumeration for the names of peripheral clocks.
 */
typedef enum {
			/* PCC clocks */
			LPSPI0_CLK                   = 44u,     	/*!< LPSPI0 clock source */
			LPSPI1_CLK                   = 45u,     	/*!< LPSPI1 clock source */
			LPSPI2_CLK                   = 46u,      	/*!< LPSPI2 clock source */
			LPIT0_CLK                    = 55u,      	/*!< LPIT0 clock source */
			ADC0_CLK                     = 59u,      	/*!< ADC0 clock source */
			PORTA_CLK                    = 73u,      	/*!< PORTA clock source */
			PORTB_CLK                    = 74u,      	/*!< PORTB clock source */
			PORTC_CLK                    = 75u,      	/*!< PORTC clock source */
			PORTD_CLK                    = 76u,      	/*!< PORTD clock source */
			PORTE_CLK                    = 77u,      	/*!< PORTE clock source */
			LPUART0_CLK                  = 106u,      /*!< LPUART0 clock source */
			LPUART1_CLK                  = 107u,      /*!< LPUART1 clock source */
			LPUART2_CLK                  = 108u,      /*!< LPUART2 clock source */
} clock_names_t;


/**
 * @brief   Peripheral clock sources.
 * @details Enumeration for different clock source options for peripherals.
 */
typedef enum {
			CLK_SRC_OFF                  = 0u,      /*!< Clock is off */
			CLK_SRC_OP_1                 = 1u,      /*!< Clock option 1 */
			CLK_SRC_OP_2                 = 2u,      /*!< Clock option 2 */
			CLK_SRC_OP_3                 = 3u,      /*!< Clock option 3 */
			CLK_SRC_OP_4                 = 4u,      /*!< Clock option 4 */
			CLK_SRC_OP_5                 = 5u,      /*!< Clock option 5 */
			CLK_SRC_OP_6                 = 6u,      /*!< Clock option 6 */
			CLK_SRC_OP_7                 = 7u,      /*!< Clock option 7 */
} peripheral_clock_source_t;


/**
 * @brief   Clock gate control.
 * @details Enumeration for enabling or disabling clock gates.
 */
typedef enum {
			CLK_GATE_DISABLE  = 0u,             /*!< Disable Clock Gate */
			CLK_GATE_ENABLE   = 1u,             /*!< Enable Clock Gate */
} clock_gate_t;


/**
 * @brief   SCG asynchronous clock division.
 * @details Enumeration for SCG async clock division options.
 */
typedef enum
{
			SCG_CLOCK_DISABLE   = 0U,        /*!< Clock output is disabled. */
			SCG_CLOCK_DIV_BY_1  = 1U,        /*!< Divided by 1. */
			SCG_CLOCK_DIV_BY_2  = 2U,        /*!< Divided by 2. */
			SCG_CLOCK_DIV_BY_4  = 3U,        /*!< Divided by 4. */
			SCG_CLOCK_DIV_BY_8  = 4U,        /*!< Divided by 8. */
			SCG_CLOCK_DIV_BY_16 = 5U,        /*!< Divided by 16. */
			SCG_CLOCK_DIV_BY_32 = 6U,        /*!< Divided by 32. */
			SCG_CLOCK_DIV_BY_64 = 7U,        /*!< Divided by 64. */
} scg_async_clock_div_t;


/**
 * @brief SCG SOSC Configuration Range
 * @details This enumeration defines the frequency ranges for the System Clock Generator (SCG) 
 *          when configuring the crystal oscillator.
 */
typedef enum {
			SCG_RANGE_LCS   = 1u,             /*!< Low frequency range selected for the crystal oscillator */
			SCG_RANGE_MCS   = 2u,             /*!< Medium frequency range selected for the crytstal oscillator */
			SCG_RANGE_HCS   = 3u,             /*!< High frequency range selected for the crystal oscillator */
} scg_sosc_cfg_range;


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief   Configuration structure for PCC clocks.
 * @details This structure holds configuration for peripheral clock settings.
 */
typedef struct
{
			clock_names_t clockName;               /* The name of the peripheral clock */
			clock_gate_t clkGate;                  /*!< Peripheral clock gate. */
			peripheral_clock_source_t clkSrc;      /*!< Peripheral clock source. */
} Pcc_ConfigType;


/**
 * @brief   Configuration structure for FIRC clock.
 * @details This structure holds configuration for FIRC clock settings.
 */
typedef struct
{
			scg_async_clock_div_t div1;        /*!<  Clock Divide 1 */
			scg_async_clock_div_t div2;        /*!<  Clock Divide 2 */
} Scg_Firc_ConfigType;


/**
 * @brief   Configuration structure for SIRC clock.
 * @details This structure holds configuration for SIRC clock settings.
 */
typedef struct
{
			scg_async_clock_div_t div1;       /*!<  Clock Divide 1 */
			scg_async_clock_div_t div2;       /*!<  Clock Divide 2 */
} Scg_Sirc_ConfigType;


/**
 * @brief   Configuration structure for SOSC clock.
 * @details This structure holds configuration for SOSC clock settings.
 */
typedef struct
{
			scg_sosc_cfg_range range;         /*!<  System OSC Range Select */
			scg_async_clock_div_t div1;       /*!<  Clock Divide 1 */
			scg_async_clock_div_t div2;       /*!<  Clock Divide 2 */
} Scg_Sosc_ConfigType;


/**
 * @brief   Configuration structure for SPLL clock.
 * @details This structure holds configuration for SPLL clock settings.
 */
typedef struct
{
			unsigned char  prediv;               /*!< PLL reference clock divider. */
			unsigned char  mult;                 /*!< System PLL multiplier. */
			unsigned char  src;                  /*!< System PLL source. */
			scg_async_clock_div_t div1;          /*!<  Clock Divide 1 */
			scg_async_clock_div_t div2;          /*!<  Clock Divide 2 */
} Scg_Spll_ConfigType;


/**
 * @brief   Configuration structure for Run Mode clock settings.
 * @details This structure holds configuration for Run mode clock settings.
 */
typedef struct
{
			system_clock_source_t      sys_clk_src;         /*!<  System Clock Source */
			core_clock_divide_ratio_t  core_div;            /*!<  Core Clock Divide Ratio */
			bus_clock_divide_ratio_t   bus_div;             /*!<  Bus Clock Divide Ratio */
			slow_clock_divide_ratio_t  slow_div;            /*!<  Slow Clock Divide Ratio */
			scg_async_clock_div_t      div1;                /*!<  Clock Divide 1 */
			scg_async_clock_div_t      div2;                /*!<  Clock Divide 2 */
} Scg_RunMode_ConfigType;


/**
 * @brief   Configuration structure for HSRun Mode clock settings.
 * @details This structure holds configuration for HSRun mode clock settings.
 */
typedef struct
{
			system_hsrun_clock_source_t      sys_clk_src;         /*!<  System Clock Source */
			core_clock_divide_ratio_t        core_div;            /*!<  Core Clock Divide Ratio */
			bus_clock_divide_ratio_t         bus_div;             /*!<  Bus Clock Divide Ratio */
			slow_clock_divide_ratio_t        slow_div;            /*!<  Slow Clock Divide Ratio */
			scg_async_clock_div_t            div1;                /*!<  Clock Divide 1 */
			scg_async_clock_div_t            div2;                /*!<  Clock Divide 2 */
} Scg_HSRunMode_ConfigType;


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
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
void Clock_SetPccConfig(const Pcc_ConfigType* ConfigPtr);

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
void Clock_SetScgFircConfig(const Scg_Firc_ConfigType * ConfigPtr);

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
void Clock_SetScgSircConfig(const Scg_Sirc_ConfigType * ConfigPtr);

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
void Clock_SetScgSoscConfig(const Scg_Sosc_ConfigType * ConfigPtr);

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
void Clock_SetScgSpllConfig(const Scg_Spll_ConfigType * ConfigPtr);

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
void Clock_SetScgRunModeConfig(const Scg_RunMode_ConfigType * ConfigPtr);

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
void Clock_SetScgHSRunModeConfig(const Scg_HSRunMode_ConfigType * ConfigPtr);

#endif  /* CLOCK_H */

/****************************************************************************************************
* @file     Port.h
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
#ifndef PORT_H
#define PORT_H


/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Port_Registers.h"

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
 * @brief     Port Return Status Type
 * @details   This enumeration defines the return status values for PORT operations.
 *            It indicates the success or failure of a function call related to 
 *            GPIO port operations.
 */
typedef enum
{
			PORT_OK        = 0U,  				/**< Operation completed successfully. */
			PORT_ERR_PARA  = 1U,  				/**< Parameter error */
} Port_ret_t;

/**
 * @brief     Port Pull Configuration Type
 * @details   This enumeration defines the pull-up and pull-down resistor configurations 
 *            for GPIO pins. It indicates whether a pull-up, pull-down, or no resistor 
 *            is enabled for the specified port.
 */
typedef enum
{
			PORT_NO_PULL_UP_DOWN   = 0U,  		/*!< internal pull-down or pull-up resistor is not enabled. */
			PORT_PULL_DOWN  			 = 1U,  		/*!< internal pull-down resistor is enabled. */
			PORT_PULL_UP    			 = 2U   		/*!< internal pull-up resistor is enabled. */
} Port_pull_config_t;


/**
 * @brief     Port Drive Strength Configuration Type
 * @details   This enumeration defines the drive strength settings for GPIO pins. 
 *            It specifies whether a low or high drive strength is configured for 
 *            the specified port, affecting the output current capability of the pin.
 */
typedef enum
{
			PORT_LOW_DRV_STRENGTH  = 0U,    /*!< low drive strength is configured. */
			PORT_HIGH_DRV_STRENGTH = 1U     /*!< high drive strength is configured. */
} Port_drive_strength_t;


/**
 * @brief     Port Multiplexing Configuration Type
 * @details   This enumeration defines the pin multiplexing options for GPIO pins. 
 *            It specifies how each pin can be configured, including whether it is 
 *            disabled or assigned to a specific function, such as GPIO or an alternate 
 *            peripheral function.
 */
typedef enum
{
			PORT_PIN_DISABLED      = 0U,  /**< Corresponding pin is disabled; used as an analog pin. */
			PORT_MUX_AS_GPIO       = 1U,  /**< Corresponding pin is configured as a GPIO. */
			PORT_MUX_ALT2          = 2U,  /**< Chip-specific alternate function 2. */
			PORT_MUX_ALT3          = 3U,  /**< Chip-specific alternate function 3. */
			PORT_MUX_ALT4          = 4U,  /**< Chip-specific alternate function 4. */
			PORT_MUX_ALT5          = 5U,  /**< Chip-specific alternate function 5. */
			PORT_MUX_ALT6          = 6U,  /**< Chip-specific alternate function 6. */
			PORT_MUX_ALT7          = 7U   /**< Chip-specific alternate function 7. */
} Port_mux_t;


/**
 * @brief     Port Interrupt Generation Configuration Type
 * @details   This enumeration defines the conditions under which interrupts or DMA 
 *            requests are generated for GPIO pins. It specifies various edge and logic 
 *            conditions that can trigger an interrupt or DMA event.
 */
typedef enum
{
			PORT_DMA_INT_DISABLED  = 0x0U,  /**< Interrupt/DMA request is disabled. */
			PORT_DMA_RISING_EDGE   = 0x1U,  /**< DMA request on rising edge. */
			PORT_DMA_FALLING_EDGE  = 0x2U,  /**< DMA request on falling edge. */
			PORT_DMA_EITHER_EDGE   = 0x3U,  /**< DMA request on either edge. */
			PORT_INT_LOGIC_ZERO    = 0x8U,  /**< Interrupt when logic level is 0. */
			PORT_INT_RISING_EDGE   = 0x9U,  /**< Interrupt on rising edge. */
			PORT_INT_FALLING_EDGE  = 0xAU,  /**< Interrupt on falling edge. */
			PORT_INT_EITHER_EDGE   = 0xBU,  /**< Interrupt on either edge. */
			PORT_INT_LOGIC_ONE     = 0xCU   /**< Interrupt when logic level is 1. */
} Port_interrupt_config_t;


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief     Port Configuration Structure
 * @details   This structure is used to configure the settings of a GPIO port pin. 
 *            It includes the base address of the port, the pin index, and various 
 *            configuration options such as pull-up/pull-down resistors, drive strength, 
 *            multiplexing settings, and interrupt generation conditions.
 */
typedef struct
{
			PORT_Type               *base;          /*!< Port base pointer. */
			unsigned int            pinPortIdx;    	/*!< Port pin number. */
			Port_pull_config_t      pullConfig;    	/*!< Internal resistor pull feature selection. */
			Port_drive_strength_t   driveSelect;   	/*!< Configures the drive strength. */
			Port_mux_t              mux;           	/*!< Mux selection for pin function. */
			Port_interrupt_config_t intConfig;     	/*!< Interrupt generation condition. */
} Port_ConfigType;

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
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
Port_ret_t Port_Init(const Port_ConfigType* ConfigPtr);

#endif  /* PORT_H */

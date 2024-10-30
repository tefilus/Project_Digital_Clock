/****************************************************************************************************
*   @file    Gpio.h
*   @author  Ma Hien Nhan
*   @brief   Header File of Gpio. 
*   @version 1.0.0
*   @date    2024-8-30
****************************************************************************************************/

/*==================================================================================================
==================================================================================================*/
#ifndef GPIO_H
#define GPIO_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Utilitie.h"
#include "Gpio_Registers.h"

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          struct name Gpio_ConfigType
* @details        This structure is used to define the configuration for a GPIO pin,
*                 including its base address, pin number, mode, and padding for alignment.
*
*/
typedef struct
{
    GPIO_Type         *      base;                  /*!< Pointer to the GPIO base register.  */
    unsigned char            GPIO_PinNumber;        /*!< The pin number of the GPIO.*/
    unsigned char            GPIO_PinMode;          /*!< The mode of the GPIO pin (input, output) */
    unsigned char 			 padding[2];			/*!< Padding for alignment purposes */
} Gpio_ConfigType;

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/** 
 * @brief Initializes the pins with the given configuration structure
 *
 * This function configures the pins with the options provided in the
 * provided structure.  
 *
 * @param[in] ConfigPtr:  The configuration structure
 * @return None
 */
void Gpio_Init(const Gpio_ConfigType* ConfigPtr);

/**
 * @brief          Writes a value to a specified GPIO output pin.
 * 
 * This function writes either a high (1) or low (0) value to the given GPIO pin.
 * 
 * @param[in]      pGPIOx Pointer to the GPIO base address.
 * @param[in]      PinNumber The number of the pin to write to.
 * @param[in]      value The value to write to the pin (e.g., HIGH or LOW).
 * @return None
 */
void GPIO_WriteToOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber, unsigned char value);

/**
 * @brief          Sets a specified GPIO output pin to HIGH.
 * @param[in]      pGPIOx Pointer to the GPIO base address.
 * @param[in]      PinNumber The number of the pin to set.
 * @return None
 */
void GPIO_SetOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber);

/**
 * @brief          Resets a specified GPIO output pin to LOW.
 * @param[in]      pGPIOx Pointer to the GPIO base address.
 * @param[in]      PinNumber The number of the pin to reset.
 * @return None
 */
void GPIO_ResetOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber);

/**
 * @brief          Toggles the state of a specified GPIO output pin.
 * 
 * This function toggles the current state of the GPIO pin.
 * 
 * @param[in]      pGPIOx Pointer to the GPIO base address.
 * @param[in]      PinNumber The number of the pin to toggle.
 * @return None
 */
void GPIO_ToggleOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber);

/**
 * @brief          Reads the value from a specified GPIO input pin.
 * 
 * This function reads the state of the GPIO input pin.
 * 
 * @param[in]      pGPIOx Pointer to the GPIO base address.
 * @param[in]      PinNumber The number of the pin to read from.
 * @return         The value read from the pin (e.g., HIGH or LOW).
 */
unsigned char GPIO_ReadFromInputPin(GPIO_Type *pGPIOx, unsigned char PinNumber);


#endif /* GPIO_H */

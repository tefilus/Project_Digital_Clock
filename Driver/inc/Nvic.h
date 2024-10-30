/****************************************************************************************************
*   @file    Nvic.h
*   @author  Ma Hien Nhan
*   @brief   Header File of Nvic. 
*   @version 1.0.0
*   @date    2024-9-13
****************************************************************************************************/

/*==================================================================================================
==================================================================================================*/
#ifndef NVIC_H
#define NVIC_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Nvic_Registers.h"

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief          IRQn_Type enumeration
 * @details        This enumeration defines the IRQ (Interrupt Request) numbers for various 
 *                 peripherals, including DMA channels, timers, and communication interfaces.
 */
typedef enum
{
    DMA_0_IRQn                     = 0u,               /**< DMA channel 0 Interrupt */
    DMA_1_IRQn                     = 1u,               /**< DMA channel 1 Interrupt */
    DMA_2_IRQn                     = 2u,               /**< DMA channel 2 Interrupt */
    DMA_3_IRQn                     = 3u,               /**< DMA channel 3 Interrupt */
    DMA_4_IRQn                     = 4u,               /**< DMA channel 4 Interrupt */
    DMA_5_IRQn                     = 5u,               /**< DMA channel 5 Interrupt */
    DMA_6_IRQn                     = 6u,               /**< DMA channel 6 Interrupt */
    DMA_7_IRQn                     = 7u,               /**< DMA channel 7 Interrupt */
    DMA_8_IRQn                     = 8u,               /**< DMA channel 8 Interrupt */
    DMA_9_IRQn                     = 9u,               /**< DMA channel 9 Interrupt */
    DMA_10_IRQn                    = 10u,              /**< DMA channel 10 Interrupt */
    DMA_11_IRQn                    = 11u,              /**< DMA channel 11 Interrupt */
    DMA_12_IRQn                    = 12u,              /**< DMA channel 12 Interrupt */
    DMA_13_IRQn                    = 13u,              /**< DMA channel 13 Interrupt */
    DMA_14_IRQn                    = 14u,              /**< DMA channel 14 Interrupt */
    DMA_15_IRQn                    = 15u,              /**< DMA channel 15 Interrupt */
    DMA_ERROR_IRQn                 = 16u,              /**< DMA error Interrupt channels 0-15 */
    MCM_FPU_IRQn                   = 17u,              /**< FPU sources Interrupt */
    FTFC_CC_IRQn                   = 18u,              /**< Command complete Interrupt */
    FTFC_RC_IRQn                   = 19u,              /**< Read collision Interrupt */
    PMC_LVD_IRQn                   = 20u,              /**< Low voltage detect Interrupt */
    FTFC_DB_IRQn                   = 21u,              /**< Double bit Interrupt */
    WDOG_EWM_IRQn                  = 22u,              /**< Interrupt request out before WDG reset out; EWM output as Interrupt */
    RCM_IRQn                       = 23u,              /**< RCM Asynchronous Interrupt */
    LPI2C0_Master_IRQn             = 24u,              /**< LPI2C Master Interrupt */
    LPI2C0_Slave_IRQn              = 25u,              /**< LPI2C0 Slave Interrupt */
    LPSPI_0_IRQn                   = 26u,              /**< LPSPI0 Interrupt */
    LPSPI_1_IRQn                   = 27u,              /**< LPSPI1 Interrupt */
    LPSPI_2_IRQn                   = 28u,              /**< LPSPI2 Interrupt */
   
    LPUART0_RxTx_IRQn              = 31u,              /**< LPUART0 Transmit / Receive  Interrupt */

    LPUART1_RxTx_IRQn              = 33u,              /**< LPUART1 Transmit / Receive  Interrupt */

    LPUART2_RxTx_IRQn              = 35u,              /**< LPUART2 Transmit / Receive  Interrupt */

    ADC_0_IRQn                     = 39u,              /**< ADC0 Interrupt request */
    ADC_1_IRQn                     = 40u,              /**< ADC1 Interrupt request */
    CMP0_IRQn                      = 41u,              /**< ANLCMP Interrupt request */

    ERM_single_IRQn                = 44u,              /**< ERM single bit error correction */
    ERM_double_IRQn                = 45u,              /**< ERM double bit error non-correctable */
    RTC_IRQn                       = 46u,              /**< RTC alarm Interrupt */
    RTC_Seconds_IRQn               = 47u,              /**< RTC seconds Interrupt */

    LPIT0_Ch0_IRQn                 = 48u,              /**< LPIT Channel 0 Interrupt */
    LPIT0_Ch1_IRQn                 = 49u,              /**< LPIT Channel 1 Interrupt */
    LPIT0_Ch2_IRQn                 = 50u,              /**< LPIT Channel 2 Interrupt */
    LPIT0_Ch3_IRQn                 = 51u,              /**< LPIT Channel 3 Interrupt */

    PDB0_IRQn                      = 52u,              /**< PDB0 Interrupt */
    
    SCG_IRQn                       = 57u,              /**< SCG bus Interrupt request */
    LPTMR0_IRQn                    = 58u,              /**< LPTIMER interrupt request */

    PORTA_IRQn                     = 59u,              /**< Port A pin detect Interrupt */
    PORTB_IRQn                     = 60u,              /**< Port B pin detect Interrupt */
    PORTC_IRQn                     = 61u,              /**< Port C pin detect Interrupt */
    PORTD_IRQn                     = 62u,              /**< Port D pin detect Interrupt */
    PORTE_IRQn                     = 63u,              /**< Port E pin detect Interrupt */

    SWI_IRQn                       = 64u,              /**< Software Interrupt */
    PDB1_IRQn                      = 68u,              /**< PDB1 Interrupt */
    FLEXIO_IRQn                    = 69u,              /**< FlexIO Interrupt */

    CAN0_ORed_IRQn                 = 78u,              /**< OR’ed [Bus Off OR Bus Off Done OR Transmit Warning OR Receive Warning] */
    CAN0_Error_IRQn                = 79u,              /**< Interrupt indicating that errors were detected on the CAN bus */
    CAN0_Wake_Up_IRQn              = 80u,              /**< Interrupt asserted when Pretended Networking operation is enabled */
    CAN0_ORed_0_15_MB_IRQn         = 81u,              /**< OR'ed Message buffer (0-15) */
    CAN0_ORed_16_31_MB_IRQn        = 82u,              /**< OR'ed Message buffer (16-31) */

    CAN1_ORed_IRQn                 = 85u,              /**< OR’ed [Bus Off OR Bus Off Done OR Transmit Warning OR Receive Warning] */
    CAN1_Error_IRQn                = 86u,              /**< Interrupt indicating that errors were detected on the CAN bus */
    CAN1_ORed_0_15_MB_IRQn         = 88u,              /**< OR'ed Message buffer (0-15) */

    CAN2_ORed_IRQn                 = 92u,              /**< OR’ed [Bus Off OR Bus Off Done OR Transmit Warning OR Receive Warning] */
    CAN2_Error_IRQn                = 93u,              /**< Interrupt indicating that errors were detected on the CAN bus */
    CAN2_ORed_0_15_MB_IRQn         = 95u,              /**< OR'ed Message buffer (0-15) */

    FTM0_Ch0_Ch1_IRQn              = 99u,              /**< Flex Timer module 0 channel 0 & 1 share interrupt */
    FTM0_Ch2_Ch3_IRQn              = 100u,             /**< Flex Timer module 0 channel 2 & 3 share interrupt */
    FTM0_Ch4_Ch5_IRQn              = 101u,             /**< Flex Timer module 0 channel 4 & 5 share interrupt */
    FTM0_Ch6_Ch7_IRQn              = 102u,             /**< Flex Timer module 0 channel 6 & 7 share interrupt */
    FTM0_Fault_IRQn                = 103u,             /**< Flex Timer module 0 Fault interrupt */
    FTM0_Ovf_Reload_IRQn           = 104u,             /**< Flex Timer module 0 Counter overflow interrupt and Reload flag interrupt */

    FTM1_Ch0_Ch1_IRQn              = 105u,             /**< Flex Timer module 1 channel 0 & 1 share interrupt */
    FTM1_Ch2_Ch3_IRQn              = 106u,             /**< Flex Timer module 1 channel 2 & 3 share interrupt */
    FTM1_Ch4_Ch5_IRQn              = 107u,             /**< Flex Timer module 1 channel 4 & 5 share interrupt */
    FTM1_Ch6_Ch7_IRQn              = 108u,             /**< Flex Timer module 1 channel 6 & 7 share interrupt */
    FTM1_Fault_IRQn                = 109u,             /**< Flex Timer module 1 Fault interrupt */
    FTM1_Ovf_Reload_IRQn           = 110u,             /**< Flex Timer module 1 Counter overflow interrupt and Reload flag interrupt */

    FTM2_Ch0_Ch1_IRQn              = 111u,             /**< Flex Timer module 2 channel 0 & 1 share interrupt */
    FTM2_Ch2_Ch3_IRQn              = 112u,             /**< Flex Timer module 2 channel 2 & 3 share interrupt */
    FTM2_Ch4_Ch5_IRQn              = 113u,             /**< Flex Timer module 2 channel 4 & 5 share interrupt */
    FTM2_Ch6_Ch7_IRQn              = 114u,             /**< Flex Timer module 2 channel 6 & 7 share interrupt */
    FTM2_Fault_IRQn                = 115u,             /**< Flex Timer module 2 Fault interrupt */
    FTM2_Ovf_Reload_IRQn           = 116u,             /**< Flex Timer module 2 Counter overflow interrupt and Reload flag interrupt */

    FTM3_Ch0_Ch1_IRQn              = 117u,             /**< Flex Timer module 3 channel 0 & 1 share interrupt */
    FTM3_Ch2_Ch3_IRQn              = 118u,             /**< Flex Timer module 3 channel 2 & 3 share interrupt */
    FTM3_Ch4_Ch5_IRQn              = 119u,             /**< Flex Timer module 3 channel 4 & 5 share interrupt */
    FTM3_Ch6_Ch7_IRQn              = 120u,             /**< Flex Timer module 3 channel 6 & 7 share interrupt */
    FTM3_Fault_IRQn                = 121u,             /**< Flex Timer module 3 Fault interrupt */
    FTM3_Ovf_Reload_IRQn           = 122u,             /**< Flex Timer module 3 Counter overflow interrupt and Reload flag interrupt */
} IRQn_Type;

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
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
void NVIC_EnableInterrupt(IRQn_Type IRQ_number);

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
void NVIC_DisableInterrupt(IRQn_Type IRQ_number);

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
void NVIC_ClearPendingFlag(IRQn_Type IRQ_number);

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
void NVIC_SetPriority(IRQn_Type IRQ_number, unsigned char priority);

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
void NVIC_Settings(IRQn_Type IRQ_number, unsigned char priority);

#endif /* Nvic_H */

/****************************************************************************************************
*   @file     Nvic_Registers.h
*   @author   Ma Hien Nhan
*   @brief    This file contains the structure definition for NVIC_Type, representing the NVIC 
*             (Nested Vectored Interrupt Controller) registers in ARM Cortex-M microcontrollers.
*   @details  The NVIC_Type structure is used to manage interrupt control, including enabling/disabling
*             interrupts, setting/clearing pending states, checking active interrupts, and configuring
*             interrupt priority levels. 
*   @version  1.0.0
*   @date     2024-09-13
****************************************************************************************************/

/*==================================================================================================
==================================================================================================*/
#ifndef NVIC_REGISTER_H
#define NVIC_REGISTER_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Utilitie.h"

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/****** Represent a state where a feature or functionality ******/
/** Peripheral S32_NVIC base address */
#define NVIC_ISER_BASE_ADDRESS                    (0xE000E100u)
#define NVIC_ICER_BASE_ADDRESS                    (0xE000E180u)
#define NVIC_ISPR_BASE_ADDRESS                    (0xE000E200u)
#define NVIC_ICPR_BASE_ADDRESS                    (0xE000E280u)
#define NVIC_IABR_BASE_ADDRESS                    (0xE000E300u)
#define NVIC_IPR_BASE_ADDRESS                     (0xE000E400u)
#define NVIC_STIR_BASE_ADDRESS                    (0xE000EF00u)


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief          NVIC Interrupt Set-Enable Registers
 * @details        This structure represents the Interrupt Set-Enable Registers
 *                 for the Nested Vectored Interrupt Controller (NVIC) in
 *                 ARM Cortex-M microcontrollers. Each register allows enabling
 *                 specific interrupts.
 */
typedef struct {
	  volatile uint32 ISER[8];           	 /*!< Interrupt Set-enable Registers 0,                 Address offset: 0xE000E100u */
                                         /*!< Interrupt Set-enable Registers 1,                 Address offset: 0xE000E104u */
                                         /*!< Interrupt Set-enable Registers 2,                 Address offset: 0xE000E108u */
                                         /*!< Interrupt Set-enable Registers 3,                 Address offset: 0xE000E10Cu */
                                         /*!< Interrupt Set-enable Registers 4,                 Address offset: 0xE000E110u */
                                         /*!< Interrupt Set-enable Registers 5,                 Address offset: 0xE000E114u */
                                         /*!< Interrupt Set-enable Registers 6,                 Address offset: 0xE000E118u */
                                         /*!< Interrupt Set-enable Registers 7,                 Address offset: 0xE000E11Cu */
} NVIC_ISER_Type;


/**
 * @brief         NVIC Interrupt Clear-enable Registers
 *
 * @details       This structure defines the Interrupt Clear-enable Registers (ICER) of the
 *                Nested Vectored Interrupt Controller (NVIC). These registers are used to
 *                enable or disable specific interrupts in the system.
 */
typedef struct {
    volatile uint32 ICER[8];             /*!< Interrupt Clear-enable Registers 0,               Address offset: 0xE000E180u */
                                         /*!< Interrupt Clear-enable Registers 1,               Address offset: 0xE000E184u */
                                         /*!< Interrupt Clear-enable Registers 2,               Address offset: 0xE000E188u */
                                         /*!< Interrupt Clear-enable Registers 3,               Address offset: 0xE000E18Cu */
                                         /*!< Interrupt Clear-enable Registers 4,               Address offset: 0xE000E190u */
                                         /*!< Interrupt Clear-enable Registers 5,               Address offset: 0xE000E194u */
                                         /*!< Interrupt Clear-enable Registers 6,               Address offset: 0xE000E198u */
                                         /*!< Interrupt Clear-enable Registers 7,               Address offset: 0xE000E19Cu */
} NVIC_ICER_Type;


/**
 * @brief         NVIC Interrupt Set-pending Registers
 *
 * @details       This structure defines the Interrupt Set-pending Registers (ISPR) of the
 *                Nested Vectored Interrupt Controller (NVIC). These registers are used to
 *                set specific interrupts to a pending state, indicating that they should be
 *                processed by the interrupt handler.
 */
typedef struct {
    volatile uint32 ISPR[8];             /*!< Interrupt Set-pending Registers 0,                Address offset: 0xE000E200u */
                                         /*!< Interrupt Set-pending Registers 1,                Address offset: 0xE000E204u */
                                         /*!< Interrupt Set-pending Registers 2,                Address offset: 0xE000E208u */
                                         /*!< Interrupt Set-pending Registers 3,                Address offset: 0xE000E20Cu */
                                         /*!< Interrupt Set-pending Registers 4,                Address offset: 0xE000E210u */
                                         /*!< Interrupt Set-pending Registers 5,                Address offset: 0xE000E214u */
                                         /*!< Interrupt Set-pending Registers 6,                Address offset: 0xE000E218u */
                                         /*!< Interrupt Set-pending Registers 7,                Address offset: 0xE000E21Cu */
} NVIC_ISPR_Type;


/**
 * @brief         NVIC Interrupt Clear-pending Registers
 *
 * @details       This structure defines the Interrupt Clear-pending Registers (ICPR) of the
 *                Nested Vectored Interrupt Controller (NVIC). These registers are used to
 *                clear specific interrupts that are currently in a pending state.
 */
typedef struct {
    volatile uint32 ICPR[8];             /*!< Interrupt Clear-pending Registers 0,              Address offset: 0xE000E280u */
                                         /*!< Interrupt Clear-pending Registers 1,              Address offset: 0xE000E284u */
                                         /*!< Interrupt Clear-pending Registers 2,              Address offset: 0xE000E288u */
                                         /*!< Interrupt Clear-pending Registers 3,              Address offset: 0xE000E28Cu */
                                         /*!< Interrupt Clear-pending Registers 4,              Address offset: 0xE000E290u */
                                         /*!< Interrupt Clear-pending Registers 5,              Address offset: 0xE000E294u */
                                         /*!< Interrupt Clear-pending Registers 6,              Address offset: 0xE000E298u */
                                         /*!< Interrupt Clear-pending Registers 7,              Address offset: 0xE000E29Cu */
} NVIC_ICPR_Type;


/**
 * @brief         NVIC Interrupt Active Bit Registers
 *
 * @details       This structure defines the Interrupt Active Bit Registers (IABR) of the
 *                Nested Vectored Interrupt Controller (NVIC). These registers indicate
 *                which interrupts are currently active in the system.
 */
typedef struct {
    volatile uint32 IABR[8];             /*!< Interrupt Active Bit Registers 0,                 Address offset: 0xE000E300u */
                                         /*!< Interrupt Active Bit Registers 1,                 Address offset: 0xE000E304u */
                                         /*!< Interrupt Active Bit Registers 2,                 Address offset: 0xE000E308u */
                                         /*!< Interrupt Active Bit Registers 3,                 Address offset: 0xE000E30Cu */
                                         /*!< Interrupt Active Bit Registers 4,                 Address offset: 0xE000E310u */
                                         /*!< Interrupt Active Bit Registers 5,                 Address offset: 0xE000E314u */
                                         /*!< Interrupt Active Bit Registers 6,                 Address offset: 0xE000E318u */
                                         /*!< Interrupt Active Bit Registers 7,                 Address offset: 0xE000E31Cu */
} NVIC_IABR_Type;


/**
 * @brief           NVIC Interrupt Priority Registers
 *
 * @details         This structure defines the Interrupt Priority Registers (IPR) of the
 *                  Nested Vectored Interrupt Controller (NVIC). These registers are used to
 *                  set and manage the priority levels of various interrupts in the system.
 */
typedef struct {
    volatile uint32 IPR[60];              /*!< Interrupt Priority Registers 0,                   Address offset: 0xE000E400u */
                                          /*!< ... */
                                          /*!< Interrupt Priority Registers 59,                  Address offset: 0xE000E4EFu */
} NVIC_IPR_Type;


/**
 * @brief           NVIC Software Trigger Interrupt Register
 *
 * @details         This structure defines the Software Trigger Interrupt Register (STIR) of the
 *                  Nested Vectored Interrupt Controller (NVIC). This register is used to
 *                  trigger interrupts manually through software.
 */
typedef struct {
    volatile uint32 STIR;              /*!< Software Trigger Interrupt Register,              Address offset: 0xE000EF00u */
} NVIC_STIR_Type;

/** Peripheral S32_NVIC base pointer */
#define NVIC_ISER                             ((NVIC_ISER_Type *)NVIC_ISER_BASE_ADDRESS)
#define NVIC_ICER                             ((NVIC_ICER_Type *)NVIC_ICER_BASE_ADDRESS)
#define NVIC_ISPR                             ((NVIC_ISPR_Type *)NVIC_ISPR_BASE_ADDRESS)
#define NVIC_ICPR                             ((NVIC_ICPR_Type *)NVIC_ICPR_BASE_ADDRESS)
#define NVIC_IABR                             ((NVIC_IABR_Type *)NVIC_IABR_BASE_ADDRESS)
#define NVIC_IPR                              ((NVIC_IPR_Type *)NVIC_IPR_BASE_ADDRESS)
#define NVIC_STIR                             ((NVIC_STIR_Type *)NVIC_STIR_BASE_ADDRESS)

#endif /* Nvic_Registers */








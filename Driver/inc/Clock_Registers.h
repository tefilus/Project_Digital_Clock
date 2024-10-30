/****************************************************************************************************
* @file     Clock_Registers.h
* @author   Ma Hien Nhan
* @brief    Header file for clock register definitions.
* @details  This header file contains definitions for clock control registers and bit manipulation.
* @version  1.0.0
* @date     2024-09-30
****************************************************************************************************/

/*==================================================================================================
==================================================================================================*/
#ifndef CLOCK_REG_H
#define CLOCK_REG_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Utilitie.h"


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/****** Bit Shifts for Clock Control Registers ******/
/***  Peripheral Clock Control (PCC) ***/
#define PCC_CGC_SHIFT                       (30u)
#define PCC_PCS_SHIFT                       (24u)

/***  System Clock Generator (SCG) ***/
#define SCG_CSR_LK_SHIFT                    (23u)              /* Lock Register */
#define SCG_CSR_VLD_SHIFT                   (24u)              /* Valid */

/* FIRC - Fast IRC */
#define SCG_FIRCDIV_FIRCDIV1_SHIFT          (0u)               /* Fast IRC Clock Divide 1 */
#define SCG_FIRCDIV_FIRCDIV2_SHIFT          (8u)               /* Fast IRC Clock Divide 2 */

/* SIRC - Slow IRC */
#define SCG_SIRCCFG_RANGE_SHIFT             (0u)               /* Frequency Range */
#define SCG_SIRCDIV_SIRCDIV1_SHIFT          (0u)               /* Slow IRC Clock Divide 1 */
#define SCG_SIRCDIV_SIRCDIV2_SHIFT          (8u)               /* Slow IRC Clock Divide 2 */

/* SOSC - System OSC */
#define SCG_SOSCCFG_RANGE_SHIFT             (4u)               /* Frequency Range */
#define SCG_SOSCCFG_EREFS_SHIFT             (2u)               /* External Reference Select */
#define SCG_SOSCDIV_SOSCDIV1_SHIFT          (0u)               /* System OSC Clock Divide 1 */
#define SCG_SOSCDIV_SOSCDIV2_SHIFT          (8u)               /* System OSC Clock Divide 2 */

/* SPLL - System PLL */
#define SCG_SPLLCFG_SOURCE_SHIFT            (0u)               /* Clock Source */
#define SCG_SPLLCFG_PREDIV_SHIFT            (8u)               /* PLL Reference Clock Divider */
#define SCG_SPLLCFG_MULT_SHIFT              (16u)              /* System PLL Multiplier */
#define SCG_SPLLDIV_SPLLDIV1_SHIFT          (0u)               /* System PLL Clock Divide 1 */
#define SCG_SPLLDIV_SPLLDIV2_SHIFT          (8u)               /* System PLL Clock Divide 2 */

/* RCCR - Run Clock Control Register */
#define SCG_RCCR_DIVSLOW_SHIFT              (0u)               /* Slow Clock Divide Ratio */
#define SCG_RCCR_DIVBUS_SHIFT               (4u)               /* Bus Clock Divide Ratio */
#define SCG_RCCR_DIVCORE_SHIFT              (16u)              /* Core Clock Divide Ratio */
#define SCG_RCCR_SCS_SHIFT                  (24u)              /* System Clock Source */

/* VCCR - VLPR Clock Control Register */
#define SCG_VCCR_DIVSLOW_SHIFT              (0u)               /* Slow Clock Divide Ratio */
#define SCG_VCCR_DIVBUS_SHIFT               (4u)               /* Bus Clock Divide Ratio */
#define SCG_VCCR_DIVCORE_SHIFT              (16u)              /* Core Clock Divide Ratio */
#define SCG_VCCR_SCS_SHIFT                  (24u)              /* System Clock Source */

/* HCCR - HSRUN Clock Control Register */
#define SCG_HCCR_DIVSLOW_SHIFT              (0u)               /* Slow Clock Divide Ratio */
#define SCG_HCCR_DIVBUS_SHIFT               (4u)               /* Bus Clock Divide Ratio */
#define SCG_HCCR_DIVCORE_SHIFT              (16u)              /* Core Clock Divide Ratio */
#define SCG_HCCR_SCS_SHIFT                  (24u)              /* System Clock Source */

/*** Peripheral PCC base address ***/
#define PCC_BASE_ADDRESS                    (0x40065000u)

/** Peripheral SCG base address */
#define SCG_BASE_ADDRESS                    (0x40064000u)

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief   Peripheral Clock Control (PCC) structure.
 * @details This structure represents the PCC register set.
 */
typedef struct {
			volatile unsigned int PCCn[122];
} PCC_Type;


#define PCC ((PCC_Type*)PCC_BASE_ADDRESS)

/**
 * @brief   System Clock Generator (SCG) structure.
 * @details This structure represents the SCG Register Layout Typedef.
 */
typedef struct {
			volatile unsigned int VERID;                             /**< Version ID Register, Address offset: 0x0 */
			volatile unsigned int PARAM;                             /**< Parameter Register, Address offset: 0x4 */
			unsigned char RESERVED_0[8];
			volatile unsigned int CSR;                               /**< Clock Status Register, Address offset: 0x10 */
			volatile unsigned int RCCR;                              /**< Run Clock Control Register, Address offset: 0x14 */
			volatile unsigned int VCCR;                              /**< VLPR Clock Control Register, Address offset: 0x18 */
			volatile unsigned int HCCR;                              /**< HSRUN Clock Control Register, Address offset: 0x1C */
			volatile unsigned int CLKOUTCNFG;                        /**< SCG CLKOUT Configuration Register, Address offset: 0x20 */
			unsigned char RESERVED_1[220];
			volatile unsigned int SOSCCSR;                           /**< System OSC Control Status Register, Address offset: 0x100 */
			volatile unsigned int SOSCDIV;                           /**< System OSC Divide Register, Address offset: 0x104 */
			volatile unsigned int SOSCCFG;                           /**< System Oscillator Configuration Register, Address offset: 0x108 */
			unsigned char RESERVED_2[244];
			volatile unsigned int SIRCCSR;                           /**< Slow IRC Control Status Register, Address offset: 0x200 */
			volatile unsigned int SIRCDIV;                           /**< Slow IRC Divide Register, Address offset: 0x204 */
			volatile unsigned int SIRCCFG;                           /**< Slow IRC Configuration Register, Address offset: 0x208 */
			unsigned char RESERVED_3[244];
			volatile unsigned int FIRCCSR;                           /**< Fast IRC Control Status Register, Address offset: 0x300 */
			volatile unsigned int FIRCDIV;                           /**< Fast IRC Divide Register, Address offset: 0x304 */
			volatile unsigned int FIRCCFG;                           /**< Fast IRC Configuration Register, Address offset: 0x308 */
			unsigned char RESERVED_4[756];
			volatile unsigned int SPLLCSR;                           /**< System PLL Control Status Register, Address offset: 0x600 */
			volatile unsigned int SPLLDIV;                           /**< System PLL Divide Register, Address offset: 0x604 */
			volatile unsigned int SPLLCFG;                           /**< System PLL Configuration Register, Address offset: 0x608 */
} SCG_Type;


/** Peripheral SCG base pointer */
#define SCG ((SCG_Type *)SCG_BASE_ADDRESS)


#endif /* CLOCK_REG_H */         


/****************************************************************************************************
*   @file    Utilitie.h
*   @author  Ma Hien Nhan
*   @brief   Header File of Utilitie layer. 
*						 Initialize definitions and function prototypes declarations
*   @version 1.0.0
*   @date    2024-8-28
****************************************************************************************************/

/*==================================================================================================
==================================================================================================*/
#ifndef UTILITIE_H
#define UTILITIE_H

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*------------------------ Basic type definition ------------------------*/
typedef signed char int8;					/* Define int8 use interchangeably for signed char */
typedef signed short int16;				/* Define int16 use interchangeably for signed short */
typedef signed int int32;					/* Define int32 use interchangeably for signed int, long */
typedef unsigned char uint8;			/* Define uint8 use interchangeably for unsigned char */
typedef unsigned short uint16;	  /* Define uint16 use interchangeably for unsigned short */
typedef unsigned int uint32;			/* Define uint32 use interchangeably for unsigned int, long */

/*------------------------ Basic bit masking ------------------------*/
#define SET_BIT(REG, VALUE, BIT)     ((REG) |= (VALUE << BIT))		/* Set bit in register */
#define CLEAR_BIT(REG, VALUE, BIT)   ((REG) &= ~(VALUE << BIT))		/* Clear bit in register */
#define TOGGLE_BIT(REG, VALUE, BIT)   ((REG) ^= (VALUE << BIT))		/* Toggle bit in register */
#define CHECK_BIT(REG, BIT)   ((REG >> BIT) & 0x01)								/* Check bit in register */

#define VALUE_CHECK_BIT   (0x01u)																	/* Value check bit in register */
#define RESET   					(0u)																		/* Reset value */

/*------------------------ Represent a state where a feature or functionality ------------------------*/
#define DISABLEMENT (0)
#define ENABLEMENT (1u)

#define LOW (0)
#define HIGH (1u)

#define CLEARBIT (0)
#define SETBIT (1u)

#define INPUT (0)
#define OUTPUT (1u)

#define NULL ((void *) 0)

/*------------------------ Definition Pin ------------------------*/
#define PIN0 (0)
#define PIN1 (1)
#define PIN2 (2)
#define PIN3 (3)
#define PIN4 (4)
#define PIN5 (5)
#define PIN6 (6)
#define PIN7 (7)
#define PIN8 (8)
#define PIN9 (9)
#define PIN10 (10)
#define PIN11 (11)
#define PIN12 (12)
#define PIN13 (13)
#define PIN14 (14)
#define PIN15 (15)
#define PIN16 (16)

/*------------------------ Definition Bit ------------------------*/
#define BIT0 (0)
#define BIT1 (1)
#define BIT2 (2)
#define BIT3 (3)
#define BIT4 (4)
#define BIT5 (5)
#define BIT6 (6)
#define BIT7 (7)
#define BIT8 (8)
#define BIT9 (9)
#define BIT10 (10)
#define BIT11 (11)
#define BIT12 (12)
#define BIT13 (13)
#define BIT14 (14)
#define BIT15 (15)
#define BIT16 (16)
#define BIT17 (17)
#define BIT18 (18)
#define BIT19 (19)
#define BIT20 (20)
#define BIT21 (21)
#define BIT22 (22)
#define BIT23 (23)
#define BIT24 (24)
#define BIT25 (25)
#define BIT26 (26)
#define BIT27 (27)
#define BIT28 (28)
#define BIT29 (29)
#define BIT30 (30)
#define BIT31 (31)

/*------------------------  NULL Definition ------------------------*/
#define NULL   ((void *) 0)  									/* Definition of NULL as a null pointer constant */

/*------------------------  Value Number Definition ------------------------*/
#define VALUE_ZERO   (0u)  						/* Definition of VALUE_ZERO as zero (unsigned) */

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
extern void Delay(void);

#endif /* Utilitie */

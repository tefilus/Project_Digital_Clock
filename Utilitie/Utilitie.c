/****************************************************************************************************
*   @file    Utilitie.c
*   @author  Ma Hien Nhan
*   @brief   Utilitie layer. 
*   @version 1.0.0
*   @date    2024-8-28
****************************************************************************************************/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Utilitie.h"


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief Delay function
 * @details This function introduces a delay by running a loop for a specified number of iterations.
 *
 * @param[in] None
 *
 * @return void
 *
 * @pre None
 * @post The delay has been introduced in the program execution.
 *
 * @api This function is useful for creating time delays in embedded systems or for timing-related tasks.
**/
void Delay(void) 
{
    for (volatile int i = 0; i < 1000000; i++);  
}

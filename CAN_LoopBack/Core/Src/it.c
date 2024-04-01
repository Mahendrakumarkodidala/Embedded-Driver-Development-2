/*
 * it.c
 *
 *  Created on: Mar 28, 2024
 *      Author: mahen
 */

#include "main_app.h"


void SysTick_Handler (void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

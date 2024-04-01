/*
 * it.c
 *
 *  Created on: Mar 6, 2024
 *      Author: mahen
 */
#include "main_app.h"

#include "stm32f4xx_hal.h"

void SysTick_Handler(void)
{
	HAL_IncTick();

	HAL_SYSTICK_IRQHandler();
}


/*
 * it.c
 *
 *  Created on: Mar 16, 2024
 *      Author: mahen
 */
#include "main_app.h"

extern TIM_HandleTypeDef htimer3;

void SysTick_Handler (void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

void TIM3_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&htimer3);
}

/*
 * it.c
 *
 *  Created on: Mar 25, 2024
 *      Author: mahen
 */

#include "main_app.h"

extern TIM_HandleTypeDef htimer2;

void SysTick_Handler (void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}


void TIM2_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&htimer2);
}


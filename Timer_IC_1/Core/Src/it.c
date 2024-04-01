/*
 * it.c
 *
 *  Created on: Mar 16, 2024
 *      Author: mahen
 */
#include "main_app.h"
extern TIM_HandleTypeDef htimer2;
extern TIM_HandleTypeDef htimer5;

void SysTick_Handler (void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}


void TIM2_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&htimer2);
}


void TIM6_DAC_IRQHandler(void)
{
	HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
	HAL_TIM_IRQHandler(&htimer5);
}

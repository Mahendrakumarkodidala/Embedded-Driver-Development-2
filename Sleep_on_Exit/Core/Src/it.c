/*
 * it.c
 *
 *  Created on: Mar 30, 2024
 *      Author: mahen
 */

#include "main_app.h"

extern TIM_HandleTypeDef htimer5;
extern UART_HandleTypeDef huart2;

void SysTick_Handler (void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();

}


void TIM5_DAC_IRQHandler(void)
{
	//HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
	HAL_TIM_IRQHandler(&htimer5);
	//HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_RESET);
}


void USART2_IRQHandler(void)
{
	HAL_UART_IRQHandler(&huart2);
}

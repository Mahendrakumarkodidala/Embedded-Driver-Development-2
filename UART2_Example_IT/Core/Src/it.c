/*
 * it.c
 *
 *  Created on: Mar 6, 2024
 *      Author: mahen
 */
#include "main_app.h"



extern UART_HandleTypeDef huart2;

void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

void USART2_IRQHandler(void)
{
	//Identifying the type of interrupt
	HAL_UART_IRQHandler(&huart2);
}


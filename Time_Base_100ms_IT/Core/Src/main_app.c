/*
 * main_app.c
 *
 *  Created on: Mar 16, 2024
 *      Author: mahen
 */

#include "stm32f4xx_hal.h"

#include "main_app.h"


void SystemClockConfig(void);

void Error_handler(void);

void TIMER3_Init(void);

void GPIO_Init(void);


TIM_HandleTypeDef htimer3;


int main(void)
{
	HAL_Init();

	SystemClockConfig();

	GPIO_Init();

	TIMER3_Init();

	//Lets start Timer
	HAL_TIM_Base_Start_IT(&htimer3);

	while(1);

	return 0;
}


void SystemClockConfig(void)
{

}


void GPIO_Init(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef ledgpio;

	ledgpio.Pin = GPIO_PIN_5;
	ledgpio.Mode = GPIO_MODE_OUTPUT_PP;
	ledgpio.Pull = GPIO_NOPULL;

	HAL_GPIO_Init(GPIOA, &ledgpio);
}


void TIMER3_Init(void)
{
	htimer3.Instance = TIM3;
	htimer3.Init.Prescaler = 24;
	htimer3.Init.Period = 64000 - 1;

	if(HAL_TIM_Base_Init(&htimer3) != HAL_OK )
	{
		Error_handler();
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}



void Error_handler(void)
{
	while(1);
}





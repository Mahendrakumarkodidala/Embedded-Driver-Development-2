/*
 * msp.c
 *
 *  Created on: Mar 16, 2024
 *      Author: mahen
 */
/*
 * msp.c
 *
 *  Created on: Mar 6, 2024
 *      Author: mahen
 */

#include "stm32f4xx_hal.h"

void HAL_MspInit(void)
{
	// Low Level processor specific initializations

	//1. Set up the priority grouping of the arm cortex mx processor
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	//2. Enable the required system exceptions of the arm cortex mx processor
	SCB->SHCSR |= 0x7 << 16; //usage fault, memory fault and bus fault system exceptions

	//3. configure the priority for the system exceptions
	HAL_NVIC_SetPriority(MemoryManagement_IRQn,0,0);
	HAL_NVIC_SetPriority(BusFault_IRQn,0,0);
	HAL_NVIC_SetPriority(UsageFault_IRQn,0,0);
}

void HAL_TIM_Base_MspInit (TIM_HandleTypeDef *htimer)
{
	//1. Enable the clock for Timer 3
	__HAL_RCC_TIM3_CLK_ENABLE();

	//2. Enable the IRQs of Timer 3
	HAL_NVIC_EnableIRQ(TIM3_IRQn);

	//3. Setup the priority
	HAL_NVIC_SetPriority(TIM3_IRQn, 15, 0);


}



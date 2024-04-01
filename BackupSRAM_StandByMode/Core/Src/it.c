/*
 * it.c
 *
 *  Created on: Mar 31, 2024
 *      Author: mahen
 */

void SysTick_Handler (void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();

}

/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	SystemInit();
	RCC->AHB1ENR |= BV(3);
	GPIOD->MODER &= ~BV(29);
	GPIOD->MODER |=BV(28);
	GPIOD->OSPEEDR &=~(BV(28)|BV(29));
	GPIOD->PUPDR &= ~(BV(29) | BV(29));
	GPIOD->OTYPER &= ~BV(14);

	while(1)
	{
		GPIOD->BSRR |=BV(14);
		DelayMs(1000);
		GPIOD->BSRR &=~BV(14);
		DelayMs(1000);
	}

	return 0;
}

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
#include "ledver.h"
#include "usart.h"
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	SystemInit();
	char ch;

		SystemInit();
		LedInit(LED_GREEN);
			LedInit(LED_BLUE);
			LedInit(LED_RED);
			LedInit(LED_ORANGE);
			uartinit(baud_9600);
			//UartPuts("Enter Strings...\r\n");
			while(1) {
				//UartGets(str);
				//strupr(str);

				uartputs("Enter your choice \r\n1.LED redon\r\n2.LED redoff\r\n3.LED Blueon\r\n4.LED blueoff\r\n");
				ch = uartgetch();
		        switch(ch)
		        {
		           case '1':
		        	   Ledon(LED_RED) ;
		        	     break;
		           case '2':
		        	    Ledoff(LED_RED);
		        	     break;
		           case '3':
		        	   Ledon(LED_BLUE) ;
		        	     break;
		           case '4':
		        	   Ledoff(LED_BLUE);
		        	     break;
		           case '5':
		           		     Ledon(LED_ORANGE) ;
		           		        	     break;
		           		           case '6':
		           		        	    Ledoff(LED_ORANGE);
		           		        	     break;
		           		           case '7':
		           		        	   Ledon(LED_GREEN) ;
		           		        	     break;
		           		           case '8':
		           		        	   Ledoff(LED_GREEN);
		           		        	     break;
		        }
		        ch = 0;
			}
		return 0;

}

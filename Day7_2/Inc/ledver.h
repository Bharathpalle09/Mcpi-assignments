/*
 * ledver.h
 *
 *  Created on: Apr 1, 2024
 *      Author: cherikiansh
 */
#include <stdint.h>
#include "stm32f407xx.h"
#include "stm32f4xx.h"


#ifndef LEDVER_H_
#define LEDVER_H_

#define LED_GPIO GPIOD
#define LED_GPIO_EN 3
#define LED_GREEN  12
#define LED_ORANGE 13
#define LED_RED     14
#define LED_BLUE    15


void LedInit(uint32_t pin);
void Ledon(uint32_t pin);
void Ledoff(uint32_t pin);
void BlinkLed(uint32_t pin,uint32_t delay);


#endif /* LEDVER_H_ */

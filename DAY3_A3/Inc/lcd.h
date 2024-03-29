/*
 * lcd.h
 *
 *  Created on: Mar 29, 2024
 *      Author: cherikiansh
 */

#ifndef LCD_H_
#define LCD_H_




#include "stm32f4xx.h"
#include "stm32f407xx.h"

#define LCD_DATA_GPIO      GPIOD
#define LCD_DATA_GPIO_EN   3
#define LCD_D7             3
#define LCD_D6             2
#define LCD_D5             18
#define LCD_D4             0
#define LCD_BF            LCD_D7
#define LCD_D7_clear      (LCD_D7+16)
#define LCD_D6_clear      (LCD_D6+16)
#define LCD_D5_clear      (LCD_D5+16)
#define LCD_D4_clear      (LCD_D4+16)



#define LCD_CRTL_GPIO     GPIOD
#define LCD_CRTL_GPIO_EN  3
#define LCD_RS         	  5
#define LCD_RW       	  6
#define LCD_EN            7
#define LCD_RS_clear      (LCD_RS+16)
#define LCD_RW_clear      (LCD_RW+16)
#define LCD_EN_clear      (LCD_EN+16)

#define LEFT_SHIFT         0x18
#define RIGHT_SHIFT        0x1c

#define CLEAR_DISPLAY      0x01
#define ENTRY_MODE         0x06
#define DISP_ON_OFF        0x0F
#define FUN_SET            0x28
#define LINE_1             0x80
#define LINE_2             0xc0

#define LCD_DATA           1
#define LCD_CMD            0

void LcdBusyWait(void);
void WriteNibble(uint8_t rs,uint8_t val);
void LcdWrite(uint8_t rs,uint8_t val);

void LCDINIT(void);
void LPuts(uint8_t line,char str[]);
#endif /* LCD_H_ */






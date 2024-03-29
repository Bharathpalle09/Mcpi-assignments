/*
 * LCD.c
 *
 *  Created on: Mar 28, 2024
 *      Author: cherikiansh
 */


#include "lcd.h"

void LcdBusyWait(void)
{
	uint32_t state;
	LCD_DATA_GPIO->MODER &= ~(BV(LCD_RS*2)|BV(LCD_RS*2+1));
	LCD_CRTL_GPIO->BSRR = BV(LCD_RS_clear)|BV(LCD_RW)| BV(LCD_EN);
	do{
		state=LCD_DATA_GPIO->IDR;
	}while((state &BV(1))!=0);
	LCD_CRTL_GPIO->BSRR = BV(LCD_RW)| BV(LCD_EN);
	LCD_DATA_GPIO->MODER |= BV(LCD_RS*2);
}

void WriteNibble(uint8_t rs,uint8_t val)
{
	if(rs==LCD_CMD)
		LCD_CRTL_GPIO->BSRR=BV(LCD_RW_clear)|BV(LCD_RS_clear);
	else
		LCD_CRTL_GPIO->BSRR=BV(LCD_RW_clear)|BV(LCD_RS);
	LCD_DATA_GPIO->ODR &= ~(BV(LCD_D7)|BV(LCD_D6)|BV(LCD_D5)|BV(LCD_D4));
	LCD_DATA_GPIO->ODR=val<<4;

	LCD_CRTL_GPIO->BSRR=BV(LCD_EN);
	LCD_CRTL_GPIO->BSRR=BV(LCD_EN_clear);
}



void LcdWrite(uint8_t rs,uint8_t val)
{
	uint8_t high=val>>4, low=val &0x0F;
	WriteNibble(rs,high);
	WriteNibble(rs,low);
	LcdBusyWait();
	DelayMs(3);
}




void LCDINIT(void)
{ 	DelayMs(50);
	RCC->AHB1ENR=LCD_DATA_GPIO_EN;
	RCC->AHB1ENR=LCD_CRTL_GPIO_EN;

	//initialize lcd data pins (mode=output, speed=low, type=push-pull, no pull up/down)
	LCD_DATA_GPIO->MODER &= ~(BV(LCD_D7*2)|BV(LCD_D6*2)|BV(LCD_D5*2)|BV(LCD_D4*2));
	LCD_DATA_GPIO->MODER |= (BV(LCD_D7*2+1)|BV(LCD_D6*2+1)|BV(LCD_D5*2+1)|BV(LCD_D4*2+1));
	LCD_DATA_GPIO->OSPEEDR &= ~(BV(LCD_D7*2)|BV(LCD_D7*2+1)|BV(LCD_D6*2)|BV(LCD_D6*2+1)|BV(LCD_D5*2)|BV(LCD_D5*2+1)|BV(LCD_D4*2)|BV(LCD_D4*2+1));
	LCD_DATA_GPIO->PUPDR &= ~(BV(LCD_D7*2)|BV(LCD_D7*2+1)|BV(LCD_D6*2)|BV(LCD_D6*2+1)|BV(LCD_D5*2)|BV(LCD_D5*2+1)|BV(LCD_D4*2)|BV(LCD_D4*2+1));
	LCD_DATA_GPIO->OTYPER &= ~(BV(LCD_D7)||BV(LCD_D6)||BV(LCD_D5)|BV(LCD_D4));

	LCD_DATA_GPIO->BSRR =(BV(LCD_D7_clear)|BV(LCD_D6_clear)|BV(LCD_D5_clear)|BV(LCD_D4_clear));

	//intialize the ctrl pins mode=output ,speed=low , pupdr=00(no pull up or pull down ,type = push pull (00)
	    LCD_CRTL_GPIO->MODER &= ~(BV(LCD_RS*2)|BV(LCD_RW*2)|BV(LCD_EN*2));
		LCD_CRTL_GPIO->MODER |= (BV(LCD_RS*2+1)|BV(LCD_RW*2+1)|BV(LCD_EN*2+1));
		LCD_CRTL_GPIO->OSPEEDR &= ~(BV(LCD_RS*2)|BV(LCD_RS*2+1)|BV(LCD_RW*2)|BV(LCD_RW*2+1)|BV(LCD_EN*2)|BV(LCD_EN*2+1));
		LCD_CRTL_GPIO->PUPDR &= ~(BV(LCD_RS*2)|BV(LCD_RS*2+1)|BV(LCD_RW*2)|BV(LCD_RW*2+1)|BV(LCD_EN*2)|BV(LCD_EN*2+1));
		LCD_CRTL_GPIO->OTYPER &= ~(BV(LCD_RS)||BV(LCD_RW)||BV(LCD_EN));

		LCD_CRTL_GPIO->BSRR =(BV(LCD_RS_clear)||BV(LCD_RW_clear)||BV(LCD_EN_clear));


		DelayMs(200);
		LcdWrite(LCD_CMD,FUN_SET);
		LcdWrite(LCD_CMD,DISP_ON_OFF);
		LcdWrite(LCD_CMD,ENTRY_MODE);
		LcdWrite(LCD_CMD,CLEAR_DISPLAY);
		DelayMs(200);
}

void LPuts(uint8_t line,char str[])
{	int i;
	LcdWrite(LCD_CMD,line);

	for(i=0;str[i]!='\0';i++)
	{
		LcdWrite(LCD_CMD,str[i]);
	}


}

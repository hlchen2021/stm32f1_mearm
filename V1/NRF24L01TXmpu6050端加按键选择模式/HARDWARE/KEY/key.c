#include "delay.h"

void Key_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}



unsigned char Key_GetNum1(void)
{
	unsigned char KeyNum = 'a';
	if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13) == 0)
	{
		KeyNum = 'b';
	}
	return KeyNum;
}

unsigned char Key_GetNum2(void)
{
	unsigned char KeyNum = 'c';
	if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_14) == 0)
	{
		KeyNum = 'd';
	}
	return KeyNum;
}

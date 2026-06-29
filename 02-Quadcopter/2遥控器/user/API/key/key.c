#include "key.h"

key_t keylist[]={
    {GPIOA, GPIO_Pin_15, 1},
    {GPIOB, GPIO_Pin_11, 2},
    {GPIOC, GPIO_Pin_13, 3},
    {GPIOC, GPIO_Pin_14, 4},
    {GPIOA, GPIO_Pin_6,  5},
    {GPIOA, GPIO_Pin_7,  6},
    {GPIOB, GPIO_Pin_0,  7},
    {GPIOB, GPIO_Pin_1,  8},
};

void Key_Config(void)
{
//KEYA==GPIOA_Pin15==>上拉输入模式
//1.开启GPIOA,GPIOB时钟
  RCC->APB2ENR |= (1 << 2);
  RCC->APB2ENR |= (1 << 3);
	RCC->APB2ENR |= (1 << 4);
//2.配置GPIOA_Pin15为上拉输入模式
  GPIOA->CRH &=~(0xf << 28);
  GPIOA->CRH |= (0x8 << 28);
//GPIOB_Pin11	
  GPIOB->CRH &=~(0xf << 12);
  GPIOB->CRH |= (0x8 << 12);
//GPIOC_Pin13	
  GPIOC->CRH &=~(0xf << 20);
  GPIOC->CRH |= (0x8 << 20);
//GPIOC_pin14
  GPIOC->CRH &=~(0xf << 24);
  GPIOC->CRH |= (0x8 << 24);
//GPIOA_Pin6
  GPIOA->CRL &=~(0xf << 24);
  GPIOA->CRL |= (0x8 << 24);
//GPIOA_Pin7
  GPIOA->CRL &=~(0xf << 28);
  GPIOA->CRL |= (0x8 << 28);
//GPIOB_Pin0
  GPIOB->CRL &=~(0xf << 0);
  GPIOB->CRL |= (0x8 << 0);  
//GPIOB_Pin1
  GPIOB->CRL &=~(0xf << 4);
  GPIOB->CRL |= (0x8 << 4); 

//3.配置输入寄存器，默认输出高电平1
  GPIOA->ODR |= (0x1 << 15);
	GPIOB->ODR |= (0x1 << 11);
	GPIOC->ODR |= (0x1 << 13);
	GPIOC->ODR |= (0x1 << 14);
	GPIOA->ODR |= (0x1 << 6);
	GPIOA->ODR |= (0x1 << 7);
	GPIOB->ODR |= (0x1 << 0);
	GPIOB->ODR |= (0x1 << 1);	
}

/*
 *按键扫描函数
 *返回键值
 *暂时不用参数
 */
uint8_t Key_Scan(void)
{
  for(uint8_t i = 0;i<KEY_COUNT;i++)
  {
  if(keylist[i].GPIOx->IDR & keylist[i].pin == 0)
	{
	Delay_nms(20);
		if(keylist[i].GPIOx->IDR & keylist[i].pin == 0)
		{
		while((keylist[i].GPIOx->IDR & keylist[i].pin) == 0);
			Delay_nms(20);
			return keylist[i].keyval;
		}
	}
  }
	return 0;
  }


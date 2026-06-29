#include "buzz.h"
#include "delay.h"
#include "stm32f10x.h"

void Buzz_Config(void)
{
	//¿ªÆôGPIOAÊ±ÖÓ
  RCC->APB2ENR |= (0x1 << 2);
	//pA12Òý½Å
	GPIOA->CRH &= ~(0xf << 16);
	GPIOA->CRH |= (0x3 << 16);
	GPIOA->ODR |= (0x1 << 12);
}

void Buzz_Play(void)
{
  GPIOA->ODR |= (0x1 << 12);
	Delay_nms(200);
	GPIOA->ODR	&= ~(0x1 << 12);
	Delay_nms(500);
}


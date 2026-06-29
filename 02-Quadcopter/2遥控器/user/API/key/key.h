#ifndef _KEY_H_
#define _KEY_H_
#include "stm32f10x.h"
#include "delay.h"

typedef struct
{
  GPIO_TypeDef *GPIOx;
	uint16_t pin;
	uint8_t keyval;
}key_t;

extern key_t keylist[];
#define KEY_COUNT 8

void Key_Config(void);
uint8_t Key_Scan(void);

#endif
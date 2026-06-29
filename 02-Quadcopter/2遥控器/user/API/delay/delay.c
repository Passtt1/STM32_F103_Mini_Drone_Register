#include "delay.h"

void Delay_lus(void){
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();__nop();__nop();__nop();__nop();__nop();
	__nop();__nop();
}
void Delay_nus(uint32_t nus)
{
while(nus--)
	Delay_lus();
}

void Delay_nms(uint32_t nms)
{
while(nms--)
	Delay_nus(1000);
}


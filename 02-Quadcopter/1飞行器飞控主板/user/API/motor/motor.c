#include "motor.h"

void MOTOR_Config(void){
//开启GPIOA，GPIOB时钟
		RCC->APB2ENR |= (0x1<<2);

		//led1 PA0熄灭
		GPIOA->CRL &= ~(0xf<<0);
		GPIOA->CRL |= (0x3<<0);
		//配置GPIOA_PIN输出寄存器，输出高低电平关闭，即写0
		GPIOA->ODR &=~ (0x1<<0);
    
}
void MOTOR_Play(void)
{
    GPIOA->ODR |= (0x1<<0);//打开电机
    Delay_nms(100);
    GPIOA->ODR &=~(0x1<<0);//关闭电机
}



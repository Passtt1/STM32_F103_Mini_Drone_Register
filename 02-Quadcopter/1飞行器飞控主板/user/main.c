#include "stm32f10x.h"
#include "stdio.h"
#include "delay.h"
#include "led.h"
#include "motor.h"


int main(void)
{
	MOTOR_Config();	
	LED_Config();//初始化led灯
	MOTOR_Play();
  while(1)//程序不能终止
  {
    LED_Play();
  }
}


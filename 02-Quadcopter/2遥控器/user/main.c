#include "stm32f10x.h"
#include "stdio.h"
#include "delay.h"
#include "buzz.h"
#include "key.h"

int main(void)
{
	Buzz_Config();
  Key_Config();	
	uint8_t keyval = 0;
  while(1)//程序不能终止
  {
  keyval=Key_Scan();
  if(keyval != 0){
	switch(keyval)
	{
	case 1:
  // PA15按键功能，例如蜂鸣器响一下
  Buzz_Play();
  break;
  case 2:
  // PB11按键功能
  break;
  case 3:
  break;
  case 4:
  break;
  case 5:
  break;
  case 6:
  break;
  case 7:
  break;
  case 8:
  break;
  default: break;
	}
	}		
  }
}

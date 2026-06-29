#include "led.h"

/*函数说明：led初始化函数
 *说    明：无参数，无返回值
 *时    间：2026.6.26
 *作    者：123
 */
void LED_Config(void)
{
    //开启GPIOA，GPIOB时钟
		RCC->APB2ENR |= (0x1 << 2);
		RCC->APB2ENR |= (0x1 << 3);
		//led1 PA7熄灭
		GPIOA->CRL &= ~(0xf << 28);//把PA7对应的4位配置全部清零
		GPIOA->CRL |= (0x3 << 28);//把PA7对应的四位设置为通用推挽输出
		GPIOA->ODR |= (1 << 7);
    //led2 PA6熄灭
		GPIOA->CRL &= ~(0xf << 24);
		GPIOA->CRL |= (0x3 << 24);
		GPIOA->ODR |= (1 << 6);
		//led3 PB0熄灭
		GPIOB->CRL &= ~(0xf << 0);
		GPIOB->CRL |= (0x3 << 0);
		GPIOB->ODR |= (1 << 0);
		//led4 PB1熄灭
		GPIOB->CRL &= ~(0xf << 4);
		GPIOB->CRL |= (0x3 << 4);
		GPIOB->ODR |= (0x1 << 1);
}
	
/*函数说明：流水灯
 *说    明：无参数，无返回值
 *时    间：2026.6.26
 *作    者：123
 */
void LED_Play(void)
{
        // 第1步：只亮LED1(PA7)，其余全灭
        GPIOA->ODR &= ~(0x1 <<7 );
        Delay_nms(500);

        // 第2步：只亮LED2(PA6)，其余全灭
		    GPIOA->ODR |= (0x1<<7); //LED1灭
        GPIOA->ODR &= ~(0x1 << 6);  // LED2亮
        Delay_nms(500);

        // 第3步：只亮LED3(PB0)，其余全灭
		    GPIOA->ODR |= (0x1 << 6);  // LED2灭
        GPIOB->ODR &= ~(0x1 << 0);  // LED3亮
        Delay_nms(500);

        // 第4步：只亮LED4(PB1)，其余全灭
        GPIOB->ODR |= (0x1 << 0);  // LED3灭
        GPIOB->ODR &= ~(0x1 << 1);  // LED4亮
        Delay_nms(500);
		    
		    // 第5步：LED4熄灭
		    GPIOB->ODR |= (0x1 << 1);  // LED4灭
}



#include "stm32f10x.h"                  // Device header


int main(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//使能GPIOC时钟
	GPIO_InitTypeDef GPIOCInitStruct;
	GPIOCInitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIOCInitStruct.GPIO_Pin=GPIO_Pin_13;
	GPIOCInitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIOCInitStruct);
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);
	while(1){
	
	}
	return 0;
}

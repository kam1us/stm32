#include "stm32f10x.h"
#include "Delay.h"
int ConterSensor_Count=0;

void ConterSensor_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	
	
	
	GPIO_InitTypeDef GPIOB_InitStruct;
	GPIOB_InitStruct.GPIO_Mode=GPIO_Mode_IPU;
	GPIOB_InitStruct.GPIO_Pin=GPIO_Pin_14;
	GPIOB_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIOB_InitStruct);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);
	
	EXTI_InitTypeDef EXTI_InitStruct;
	EXTI_InitStruct.EXTI_Line=EXTI_Line14;
	EXTI_InitStruct.EXTI_LineCmd=ENABLE;
	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStruct);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel=EXTI15_10_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStruct);
}
int ConterSensor_Get(void){
	return ConterSensor_Count;
}


void EXTI15_10_IRQHandler(void){
	Delay_ms(500);
	if(EXTI_GetITStatus(EXTI_Line14)==SET){
		ConterSensor_Count++;
		EXTI_ClearITPendingBit(EXTI_Line14);
	}
}

		
#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "ConterSensor.h"

int main(void)
{
	/*模块初始化*/
	OLED_Init();		//OLED初始化
	ConterSensor_Init();
	
	OLED_ShowString(1, 1, "count");	//1行3列显示字符串!
	int num;

	while (1)
	{
		num=ConterSensor_Get();	
		OLED_ShowNum(1,7,num,2);
	}
	return 0;
}

/******************** (C) COPYRIGHT 2014 ANO Tech ***************************
 * 作者		 ：匿名科创
 * 文件名  ：board.c
 * 描述    ：硬件初始化
 * 官网    ：www.anotc.com
 * 淘宝    ：anotc.taobao.com
 * 技术Q群 ：190169595
**********************************************************************************/
#include "board.h"

void SysTick_IRQ(void)
{
	scheduler.cnt_1ms++;
	scheduler.cnt_2ms++;
	scheduler.cnt_5ms++;
	scheduler.cnt_10ms++;
	scheduler.cnt_20ms++;
}

void ANO_Hexacopter_board_Init(void)
{
	//中断优先级组别设置
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	
	//初始化系统滴答定时器
	SysTick_Config(SystemCoreClock / 1000);	
	
	//初始化模拟I2C
	ANO_I2C_Soft::Init();
	//初始化SPI2
	ANO_SPI2::Init();
	//初始化NRF
	nrf.Init(MODEL_TX2,80);
	
	//初始化定时器输出PWM,24KHz
	ANO_PWM::out_Init(24000);
	
	//解锁flash
	FLASH_Unlock();	
	//初始化虚拟eeprom设置
	EE_Init();	
	
}



/******************* (C) COPYRIGHT 2014 ANO TECH *****END OF FILE************/

/************************ (C) COPYRIGHT 2014 ANO Tech ******************************
 * 作者		 ：匿名科創
 * 文件名  ：ANO_RC.cpp
 * 描述    ：遙控通道數據處理
 * 官網    ：www.anotc.com
 * 淘寶    ：anotc.taobao.com
 * 技術Q群 ：190169595
**********************************************************************************/
#include "ANO_RC.h"

ANO_RC rc;

ANO_RC::ANO_RC()
{
	Init();
}

void ANO_RC::Init(void)
{
	
}

void ANO_RC::Cal_Command(void)
{

    for (u8 i = 0; i < 3; i++) 
		{	//處理ROLL,PITCH,YAW這三個軸的數據
			Command[i] = (rawData[i] - RC_MID) * 0.25;
		}
		Command[YAW] = -Command[YAW];
		Command[THROTTLE] = rawData[THROTTLE];
		
}


const uint8_t stick_min_flag[4] = {1<<0,1<<2,1<<4,1<<6}; 
const uint8_t stick_max_flag[4] = {1<<1,1<<3,1<<5,1<<7};
#define ROL_L 0x01
#define ROL_H 0x02
#define PIT_L	0x04
#define PIT_H 0x08
#define YAW_L 0x10
#define YAW_H 0x20
#define THR_L 0x40
#define THR_H 0x80

void ANO_RC::check_sticks(void)
{
	int i;
	static uint8_t rcDelayCommand;
	
	static uint8_t stick_flag = 0;

	for (i = 0; i < 4; i++) 
	{
			if(rawData[i]<900||rawData[i]>2000)	//如果搖桿值不在正常範圍內，則退出檢查
				break;
			
			if (rawData[i] < RC_MINCHECK)
					stick_flag |= stick_min_flag[i];  // check for MIN
			else if (rawData[i] > RC_MAXCHECK)
					stick_flag |= stick_max_flag[i];  // check for MAX
	}	
	
	if(stick_flag&0xff)	//如果任一搖桿在最大或最小位置
	{
		if(rcDelayCommand < 250)
			rcDelayCommand++;
	}
	else
	{
		rcDelayCommand = 0;
		stick_flag &= 0;
	}	
	
	if (rcDelayCommand == 100) //2s: 20ms * 100
	{
		if (ano.f.ARMED) //如果已經處於解鎖狀態
		{ 
			if((stick_flag & YAW_L)&&(stick_flag & THR_L))
			{
				ano.f.ARMED = 0;	//上鎖
			}
		}
		else
		{
			if((stick_flag & YAW_H)&&(stick_flag & THR_L))
			{
				ano.f.ARMED = 1;	//解鎖
			}
		}
		stick_flag &= 0;
		rcDelayCommand = 0;
	}
}


/******************* (C) COPYRIGHT 2014 ANO TECH *****END OF FILE************/

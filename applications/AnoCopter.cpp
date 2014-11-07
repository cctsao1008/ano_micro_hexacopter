/******************** (C) COPYRIGHT 2014 ANO Tech ***************************
 * 作者		 ：匿名科創
 * 文件名  ：AnoCopter.cpp
 * 描述    ：匿名微型六軸飛行器
 * 代碼版本：V1.0
 * 時間		 ：2014/10/13 
 * 官網    ：www.anotc.com
 * 淘寶    ：anotc.taobao.com
 * 技術Q群 ：190169595
**********************************************************************************/
#include "ANO_Config.h"

int main(void)
{
	//初始化飛控板的硬件設置
	ANO_Hexacopter_board_Init();
	
	//初始化參數
	param.Init();
	
	//初始化IMU（慣性測量單元）
	imu.Init();	
	
	while(1)
	{
		ANO_Loop();
	}
	
	return 0;
}


/******************* (C) COPYRIGHT 2014 ANO TECH *****END OF FILE************/

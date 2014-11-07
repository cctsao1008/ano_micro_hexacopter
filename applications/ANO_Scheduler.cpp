/******************** (C) COPYRIGHT 2014 ANO Tech ***************************
 * 作者		 ：匿名科創
 * 文件名  ：ANO_Scheduler.cpp
 * 描述    ：任務處理
 * 官網    ：www.anotc.com
 * 淘寶    ：anotc.taobao.com
 * 技術Q群 ：190169595
**********************************************************************************/
#include "ANO_Scheduler.h"

ANO_Scheduler scheduler;


static void ANO_Loop_1000Hz(void)	//1ms執行一次
{
	//檢查是否有接收到無線數據
	dt.Check_Event();
}

static void ANO_Loop_500Hz(void)	//2ms執行一次
{	
	//更新傳感器數據	
	imu.updateSensor();		
	
	//計算飛行器姿態
	imu.getAttitude();
	
	//飛行器姿態控制
	fc.Attitude_Loop();	
}

static void ANO_Loop_200Hz(void)	//5ms執行一次
{
	
}

static void ANO_Loop_100Hz(void)	//10ms執行一次
{
	//發送飛行器數據
	dt.Data_Exchange();
}

static void ANO_Loop_50Hz(void)	//20ms執行一次
{
	//遙控通道數據處理
	rc.Cal_Command();
	
	//搖桿位置檢查
	rc.check_sticks();
	
	//失控保護檢查
	dt.Failsafe_Check();
}

void ANO_Loop(void)
{
	if(scheduler.cnt_1ms >= 1){
		ANO_Loop_1000Hz();	
		scheduler.cnt_1ms = 0;
	}
	if(scheduler.cnt_2ms >= 2){
		ANO_Loop_500Hz();
		scheduler.cnt_2ms = 0;
	}		
	if(scheduler.cnt_5ms >= 5){	
		ANO_Loop_200Hz();
		scheduler.cnt_5ms = 0;
	}
	if(scheduler.cnt_10ms >= 10){		
		ANO_Loop_100Hz();
		scheduler.cnt_10ms = 0;
	}
	if(scheduler.cnt_20ms >= 20){		
		ANO_Loop_50Hz();
		scheduler.cnt_20ms = 0;
	}
}

ANO_Scheduler::ANO_Scheduler()
{
	cnt_1ms = cnt_2ms = cnt_5ms = cnt_10ms = cnt_20ms	= 0;
}



/******************* (C) COPYRIGHT 2014 ANO TECH *****END OF FILE************/

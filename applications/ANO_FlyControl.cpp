/******************** (C) COPYRIGHT 2014 ANO Tech ***************************
 * 作者		 ：匿名科創
 * 文件名  ：ANO_FlyControl.cpp
 * 描述    ：飛行控制
 * 官網    ：www.anotc.com
 * 淘寶    ：anotc.taobao.com
 * 技術Q群 ：190169595
**********************************************************************************/
#include "ANO_FlyControl.h"

ANO_FlyControl fc;


ANO_FlyControl::ANO_FlyControl()
{
	//重置PID參數
	PID_Reset();
}

//重置PID參數
void ANO_FlyControl::PID_Reset(void)
{
	pid[PIDROLL].set_pid(55, 25, 65, 2000000);
	pid[PIDPITCH].set_pid(55, 25, 65, 2000000);
	pid[PIDYAW].set_pid(50, 50, 0, 2000000);
}

//飛行器姿態控制
void ANO_FlyControl::Attitude_Loop(void)
{
	int32_t PIDTerm[3];
	int32_t	errorAngle[3];
	
	//計算角度誤差值
	errorAngle[ROLL] = constrain_int32((rc.Command[ROLL] * 2) , -((int)FLYANGLE_MAX), +FLYANGLE_MAX) - imu.angle.x * 10; 
	errorAngle[PITCH] = constrain_int32((rc.Command[PITCH] * 2) , -((int)FLYANGLE_MAX), +FLYANGLE_MAX) - imu.angle.y * 10; 
	errorAngle[YAW] = rc.Command[YAW] * 5 - mpu6050.Get_Gyro().z / 4;	
	
	for(u8 i=0; i<3;i++)
	{
		//當油門低於檢查值時積分清零
		if ((rc.rawData[THROTTLE]) < RC_MINCHECK)	
			pid[i].reset_I();
		
		//得到PID輸出
		PIDTerm[i] = pid[i].get_pid(errorAngle[i], PID_LOOP_TIME);
	}
	
	PIDTerm[YAW] = -constrain_int32(PIDTerm[YAW], -300 - abs(rc.Command[YAW]), +300 + abs(rc.Command[YAW]));		
	
	//PID輸出轉為電機控制量
	motor.writeMotor(rc.Command[THROTTLE], PIDTerm[ROLL], PIDTerm[PITCH], PIDTerm[YAW]);
}

/************************ (C) COPYRIGHT 2014 ANO TECH *****END OF FILE**********************/

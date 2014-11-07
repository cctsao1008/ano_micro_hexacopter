/******************** (C) COPYRIGHT 2014 ANO Tech ***************************
 * �@��		 �G�ΦW���
 * ���W  �GANO_FlyControl.cpp
 * �y�z    �G���汱��
 * �x��    �Gwww.anotc.com
 * �^�_    �Ganotc.taobao.com
 * �޳NQ�s �G190169595
**********************************************************************************/
#include "ANO_FlyControl.h"

ANO_FlyControl fc;


ANO_FlyControl::ANO_FlyControl()
{
	//���mPID�Ѽ�
	PID_Reset();
}

//���mPID�Ѽ�
void ANO_FlyControl::PID_Reset(void)
{
	pid[PIDROLL].set_pid(55, 25, 65, 2000000);
	pid[PIDPITCH].set_pid(55, 25, 65, 2000000);
	pid[PIDYAW].set_pid(50, 50, 0, 2000000);
}

//���澹���A����
void ANO_FlyControl::Attitude_Loop(void)
{
	int32_t PIDTerm[3];
	int32_t	errorAngle[3];
	
	//�p�⨤�׻~�t��
	errorAngle[ROLL] = constrain_int32((rc.Command[ROLL] * 2) , -((int)FLYANGLE_MAX), +FLYANGLE_MAX) - imu.angle.x * 10; 
	errorAngle[PITCH] = constrain_int32((rc.Command[PITCH] * 2) , -((int)FLYANGLE_MAX), +FLYANGLE_MAX) - imu.angle.y * 10; 
	errorAngle[YAW] = rc.Command[YAW] * 5 - mpu6050.Get_Gyro().z / 4;	
	
	for(u8 i=0; i<3;i++)
	{
		//��o���C���ˬd�Ȯɿn���M�s
		if ((rc.rawData[THROTTLE]) < RC_MINCHECK)	
			pid[i].reset_I();
		
		//�o��PID��X
		PIDTerm[i] = pid[i].get_pid(errorAngle[i], PID_LOOP_TIME);
	}
	
	PIDTerm[YAW] = -constrain_int32(PIDTerm[YAW], -300 - abs(rc.Command[YAW]), +300 + abs(rc.Command[YAW]));		
	
	//PID��X�ର�q������q
	motor.writeMotor(rc.Command[THROTTLE], PIDTerm[ROLL], PIDTerm[PITCH], PIDTerm[YAW]);
}

/************************ (C) COPYRIGHT 2014 ANO TECH *****END OF FILE**********************/

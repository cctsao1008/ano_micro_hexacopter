/******************** (C) COPYRIGHT 2014 ANO Tech ***************************
 * �@��		 �G�ΦW���
 * ���W  �GANO_Scheduler.cpp
 * �y�z    �G���ȳB�z
 * �x��    �Gwww.anotc.com
 * �^�_    �Ganotc.taobao.com
 * �޳NQ�s �G190169595
**********************************************************************************/
#include "ANO_Scheduler.h"

ANO_Scheduler scheduler;


static void ANO_Loop_1000Hz(void)	//1ms����@��
{
	//�ˬd�O�_��������L�u�ƾ�
	dt.Check_Event();
}

static void ANO_Loop_500Hz(void)	//2ms����@��
{	
	//��s�ǷP���ƾ�	
	imu.updateSensor();		
	
	//�p�⭸�澹���A
	imu.getAttitude();
	
	//���澹���A����
	fc.Attitude_Loop();	
}

static void ANO_Loop_200Hz(void)	//5ms����@��
{
	
}

static void ANO_Loop_100Hz(void)	//10ms����@��
{
	//�o�e���澹�ƾ�
	dt.Data_Exchange();
}

static void ANO_Loop_50Hz(void)	//20ms����@��
{
	//�����q�D�ƾڳB�z
	rc.Cal_Command();
	
	//�n���m�ˬd
	rc.check_sticks();
	
	//�����O�@�ˬd
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

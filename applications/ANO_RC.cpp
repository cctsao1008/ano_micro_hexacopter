/************************ (C) COPYRIGHT 2014 ANO Tech ******************************
 * �@��		 �G�ΦW���
 * ���W  �GANO_RC.cpp
 * �y�z    �G�����q�D�ƾڳB�z
 * �x��    �Gwww.anotc.com
 * �^�_    �Ganotc.taobao.com
 * �޳NQ�s �G190169595
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
		{	//�B�zROLL,PITCH,YAW�o�T�Ӷb���ƾ�
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
			if(rawData[i]<900||rawData[i]>2000)	//�p�G�n��Ȥ��b���`�d�򤺡A�h�h�X�ˬd
				break;
			
			if (rawData[i] < RC_MINCHECK)
					stick_flag |= stick_min_flag[i];  // check for MIN
			else if (rawData[i] > RC_MAXCHECK)
					stick_flag |= stick_max_flag[i];  // check for MAX
	}	
	
	if(stick_flag&0xff)	//�p�G���@�n��b�̤j�γ̤p��m
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
		if (ano.f.ARMED) //�p�G�w�g�B����ꪬ�A
		{ 
			if((stick_flag & YAW_L)&&(stick_flag & THR_L))
			{
				ano.f.ARMED = 0;	//�W��
			}
		}
		else
		{
			if((stick_flag & YAW_H)&&(stick_flag & THR_L))
			{
				ano.f.ARMED = 1;	//����
			}
		}
		stick_flag &= 0;
		rcDelayCommand = 0;
	}
}


/******************* (C) COPYRIGHT 2014 ANO TECH *****END OF FILE************/

/******************** (C) COPYRIGHT 2014 ANO Tech ***************************
 * �@��		 �G�ΦW���
 * ���W  �GAnoCopter.cpp
 * �y�z    �G�ΦW�L�����b���澹
 * �N�X�����GV1.0
 * �ɶ�		 �G2014/10/13 
 * �x��    �Gwww.anotc.com
 * �^�_    �Ganotc.taobao.com
 * �޳NQ�s �G190169595
**********************************************************************************/
#include "ANO_Config.h"

int main(void)
{
	//��l�ƭ����O���w��]�m
	ANO_Hexacopter_board_Init();
	
	//��l�ưѼ�
	param.Init();
	
	//��l��IMU�]�D�ʴ��q�椸�^
	imu.Init();	
	
	while(1)
	{
		ANO_Loop();
	}
	
	return 0;
}


/******************* (C) COPYRIGHT 2014 ANO TECH *****END OF FILE************/

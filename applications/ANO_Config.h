#ifndef __ANO_CONFIG_H
#define __ANO_CONFIG_H

#include "board.h"
#include "ANO_PID.h"
#include "ANO_Filter.h"
#include "ANO_IMU.h"
#include "ANO_Scheduler.h"
#include "ANO_DT.h"
#include "ANO_Motor.h"
#include "ANO_RC.h"
#include "ANO_FlyControl.h"
#include "ANO_Param.h"

/*----------------------IMU--------------------*/
#define ANO_IMU_USE_DCM_CF

#define IMU_LOOP_TIME		2000	//��쬰uS
#define PID_LOOP_TIME		2000	//��쬰us

#define ACC_1G 			4096		//�ѥ[�t�׭p���q�{�T�w
#define ACC_LPF_CUT 10.0f		//�[�t�קC�q�o�i���I���W�v10Hz

#define GYRO_CF_TAU 1.2f
/*---------------------------------------------*/

/*-------------------�L�u�ƾڵo�e�覡���-----------------*/
//#define ANO_DT_USE_Bluetooth
#define ANO_DT_USE_NRF24l01
/*--------------------------------------------------------*/


class ANO_Config
{
	
public:
	
	ANO_Config();

	class Factor{
		public:		
			float acc_lpf;		
			float gyro_cf;		
	}factor;

	class Flag{
		public:
			uint8_t ARMED;
			uint8_t failsafe;
	}f;
	
};

extern ANO_Config ano;

#endif


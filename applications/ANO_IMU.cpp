/******************** (C) COPYRIGHT 2014 ANO Tech *******************************
 * �@��		 �G�ΦW���
 * ���W  �GANO_IMU.cpp
 * �y�z    �G���澹���A�p��
 * �x��    �Gwww.anotc.com
 * �^�_    �Ganotc.taobao.com
 * �޳NQ�s �G190169595
**********************************************************************************/
#include "ANO_IMU.h"

ANO_IMU imu;

ANO_IMU::ANO_IMU()
{
}

//IMU��l��
void ANO_IMU::Init()
{
	//�o�i���Ѽƪ�l��
	filter_Init();
	//�ǷP����l��
	sensor_Init();	
}

//��s�ǷP���ƾ�
void ANO_IMU::updateSensor()
{
	//Ū���[�t��
	mpu6050.Read_Acc_Data();
	//Ū�����t��
	mpu6050.Read_Gyro_Data();	
	//������t�סA��쬰�רC��
	Gyro = mpu6050.Get_Gyro_in_dps();
	//����[�t�ױļ˭�
	Acc = mpu6050.Get_Acc();
}


//�p�⭸�澹���A
void ANO_IMU::getAttitude()
{
	//�[�t�׼ƾڤ@���C�q�o�i
	Acc_lpf_1st = LPF_1st(Acc_lpf_1st, Acc, ano.factor.acc_lpf);
	
	//�|���Ƨ�s���A
	Quaternion_CF(Gyro,Acc_lpf_1st,IMU_LOOP_TIME*1e-6);
}


#define Kp 2.0f        //�[�t���v���A�V�j�h�V�[�t�״��q�Ȧ��ĶV��
#define Ki 0.001f      //�~�t�n���W�q
//�|���Ƨ�s���A
void ANO_IMU::Quaternion_CF(Vector3f gyro,Vector3f acc, float deltaT)
{
	Vector3f V_gravity, V_error, V_error_I;
	
	//���O�[�t���k�@��
	acc.normalize();
	
	//�����|���ƪ����ľl���x�}�������O���q
	Q.vector_gravity(V_gravity);
	
	//�V�q�e�n�o�X���A�~�t
	V_error = acc % V_gravity;
	
	//��~�t�i��n��	
	V_error_I += V_error * Ki;
	
	//�����o�i�A���A�~�t���v�쨤�t�פW�A�ץ����t�׿n���}��
	Gyro += V_error * Kp + V_error_I;		
	
	//�@���s��w��k��s�|����
	Q.Runge_Kutta_1st(Gyro, deltaT);
	
	//�|�����k�@��
	Q.normalize();
	
	//�|������کԨ�
	Q.to_euler(&angle.x, &angle.y, &angle.z);
}


void ANO_IMU::filter_Init()
{
	//�[�t�פ@���C�q�o�i���Y�ƭp��
	ano.factor.acc_lpf = LPF_1st_Factor_Cal(IMU_LOOP_TIME * 1e-6, ACC_LPF_CUT);
	//�����o�i���Y�ƭp��
	ano.factor.gyro_cf = CF_Factor_Cal(IMU_LOOP_TIME * 1e-6, GYRO_CF_TAU);	
}

void ANO_IMU::sensor_Init()
{
	//��l��MPU6050�A1Khz�ļ˲v�A98Hz�C�q�o�i
	mpu6050.Init(1000,98);
}

/******************* (C) COPYRIGHT 2014 ANO TECH *****END OF FILE************/

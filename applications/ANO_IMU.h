#ifndef __ANO_IMU_H
#define __ANO_IMU_H

#include "ANO_Config.h"

class ANO_IMU : public ANO_Filter
{
	
public:

	ANO_IMU();
	
	//�کԨ���ܪ����澹���A
	Vector3f angle;
	
	Vector3f Gyro, Acc, Acc_lpf_1st, Acc_lpf_2nd; 
	
	void Init();
	
	//��s�ǷP���ƾ�
	void updateSensor();	
	
	//�p�⭸�澹���A
	void getAttitude();
	
private:
	
	Quaternion Q;

	//���|���ƩM�����o�i�����A�Ѻ�
	void Quaternion_CF(Vector3f gyro,Vector3f acc, float deltaT);

	//�o�i���Ѽƪ�l��
	void filter_Init();
	//�ǷP����l��
	void sensor_Init();

};

extern ANO_IMU imu;

#endif


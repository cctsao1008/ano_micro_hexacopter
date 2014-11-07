#ifndef __ANO_IMU_H
#define __ANO_IMU_H

#include "ANO_Config.h"

class ANO_IMU : public ANO_Filter
{
	
public:

	ANO_IMU();
	
	//歐拉角表示的飛行器姿態
	Vector3f angle;
	
	Vector3f Gyro, Acc, Acc_lpf_1st, Acc_lpf_2nd; 
	
	void Init();
	
	//更新傳感器數據
	void updateSensor();	
	
	//計算飛行器姿態
	void getAttitude();
	
private:
	
	Quaternion Q;

	//基於四元數和互補濾波的姿態解算
	void Quaternion_CF(Vector3f gyro,Vector3f acc, float deltaT);

	//濾波器參數初始化
	void filter_Init();
	//傳感器初始化
	void sensor_Init();

};

extern ANO_IMU imu;

#endif


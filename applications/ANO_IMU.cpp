/******************** (C) COPYRIGHT 2014 ANO Tech *******************************
 * 作者		 ：匿名科創
 * 文件名  ：ANO_IMU.cpp
 * 描述    ：飛行器姿態計算
 * 官網    ：www.anotc.com
 * 淘寶    ：anotc.taobao.com
 * 技術Q群 ：190169595
**********************************************************************************/
#include "ANO_IMU.h"

ANO_IMU imu;

ANO_IMU::ANO_IMU()
{
}

//IMU初始化
void ANO_IMU::Init()
{
	//濾波器參數初始化
	filter_Init();
	//傳感器初始化
	sensor_Init();	
}

//更新傳感器數據
void ANO_IMU::updateSensor()
{
	//讀取加速度
	mpu6050.Read_Acc_Data();
	//讀取角速度
	mpu6050.Read_Gyro_Data();	
	//獲取角速度，單位為度每秒
	Gyro = mpu6050.Get_Gyro_in_dps();
	//獲取加速度採樣值
	Acc = mpu6050.Get_Acc();
}


//計算飛行器姿態
void ANO_IMU::getAttitude()
{
	//加速度數據一階低通濾波
	Acc_lpf_1st = LPF_1st(Acc_lpf_1st, Acc, ano.factor.acc_lpf);
	
	//四元數更新姿態
	Quaternion_CF(Gyro,Acc_lpf_1st,IMU_LOOP_TIME*1e-6);
}


#define Kp 2.0f        //加速度權重，越大則向加速度測量值收斂越快
#define Ki 0.001f      //誤差積分增益
//四元數更新姿態
void ANO_IMU::Quaternion_CF(Vector3f gyro,Vector3f acc, float deltaT)
{
	Vector3f V_gravity, V_error, V_error_I;
	
	//重力加速度歸一化
	acc.normalize();
	
	//提取四元數的等效餘弦矩陣中的重力份量
	Q.vector_gravity(V_gravity);
	
	//向量叉積得出姿態誤差
	V_error = acc % V_gravity;
	
	//對誤差進行積分	
	V_error_I += V_error * Ki;
	
	//互補濾波，姿態誤差補償到角速度上，修正角速度積分漂移
	Gyro += V_error * Kp + V_error_I;		
	
	//一階龍格庫塔法更新四元數
	Q.Runge_Kutta_1st(Gyro, deltaT);
	
	//四元數歸一化
	Q.normalize();
	
	//四元數轉歐拉角
	Q.to_euler(&angle.x, &angle.y, &angle.z);
}


void ANO_IMU::filter_Init()
{
	//加速度一階低通濾波器係數計算
	ano.factor.acc_lpf = LPF_1st_Factor_Cal(IMU_LOOP_TIME * 1e-6, ACC_LPF_CUT);
	//互補濾波器係數計算
	ano.factor.gyro_cf = CF_Factor_Cal(IMU_LOOP_TIME * 1e-6, GYRO_CF_TAU);	
}

void ANO_IMU::sensor_Init()
{
	//初始化MPU6050，1Khz採樣率，98Hz低通濾波
	mpu6050.Init(1000,98);
}

/******************* (C) COPYRIGHT 2014 ANO TECH *****END OF FILE************/

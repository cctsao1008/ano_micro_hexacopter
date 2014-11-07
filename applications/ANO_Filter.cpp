/******************** (C) COPYRIGHT 2014 ANO Tech ***************************
 * 作者		 ：匿名科創
 * 文件名  ：ANO_Filter.cpp
 * 描述    ：濾波器相關函數
 * 官網    ：www.anotc.com
 * 淘寶    ：anotc.taobao.com
 * 技術Q群 ：190169595
**********************************************************************************/
#include "ANO_Filter.h"


/*----------------------低通濾波器係數計算-------------------------*/
float ANO_Filter::LPF_1st_Factor_Cal(float deltaT, float Fcut)
{
	return deltaT / (deltaT + 1 / (2 * M_PI * Fcut));
}

/*----------------------一階低通濾波器------------------------*/
Vector3f ANO_Filter::LPF_1st(Vector3f oldData, Vector3f newData, float lpf_factor)
{
	return oldData * (1 - lpf_factor) + newData * lpf_factor;
}

/*----------------------互補濾波器係數計算-------------------------*/
float ANO_Filter::CF_Factor_Cal(float deltaT, float tau)
{
	return tau / (deltaT + tau);
}

/*----------------------一階互補濾波器-----------------------------*/
Vector3f ANO_Filter::CF_1st(Vector3f gyroData, Vector3f accData, float cf_factor)
{ 
	return (gyroData * cf_factor + accData *(1 - cf_factor));	
}





/******************* (C) COPYRIGHT 2014 ANO TECH *****END OF FILE************/

#ifndef __ANO_FILTER_H
#define __ANO_FILTER_H

#include "ANO_Math.h"

class ANO_Filter
{
	
public:

	ANO_Filter(){
	}

	//�@���C�q�o�i���Y�ƭp��
	float LPF_1st_Factor_Cal(float deltaT, float Fcut);
	
	//�����o�i���Y�ƭp��
	float CF_Factor_Cal(float deltaT, float tau);
	
	//�@���C�q�o�i��
	Vector3f LPF_1st(Vector3f oldData, Vector3f newData, float lpf_factor);

	//�@�������o�i��
	Vector3f CF_1st(Vector3f gyroData, Vector3f accData, float cf_factor);
	
};


#endif


/******************** (C) COPYRIGHT 2014 ANO Tech ***************************
 * 作者		 ：匿名科創
 * 文件名  ：ANO_PID.cpp
 * 描述    ：PID運算庫
 * 官網    ：www.anotc.com
 * 淘寶    ：anotc.taobao.com
 * 技術Q群 ：190169595
**********************************************************************************/
#include "ANO_PID.h"


int32_t ANO_PID::get_p(int32_t error)
{
    return error * kP / 64;
}

int32_t ANO_PID::get_i(int32_t error, uint16_t dt)
{
    if((kI != 0) && (dt != 0)) {
        integrator += (error * dt / 2048 ) * kI;
				//積分限幅
				integrator = constrain_int32(integrator, -imax, +imax);		
				
        return integrator / 8192;
    }
    return 0;
}

void ANO_PID::reset_I(void)
{
	integrator = 0;
}

int32_t ANO_PID::get_d(int32_t error, uint16_t dt)
{
    if ((kD != 0) && (dt != 0)) {			
			int32_t derivative;
			derivative = error - last_error; 
			last_error = error;
			derivative = (derivative * ((uint16_t)0xFFFF / (dt / 16 ))) / 64;
			return (derivative * kD) / 4;
    }
    return 0;
}

int32_t ANO_PID::get_pi(int32_t error, uint16_t dt)
{
    return get_p(error) + get_i(error, dt);
}

int32_t ANO_PID::get_pid(int32_t error, uint16_t dt)
{
    return get_p(error) + get_i(error, dt) + get_d(error, dt);
}


/******************* (C) COPYRIGHT 2014 ANO TECH *****END OF FILE************/

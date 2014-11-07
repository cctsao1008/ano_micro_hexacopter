#ifndef __ANO_PID_H
#define __ANO_PID_H

#include <stdint.h>
#include "ANO_Math.h"

class ANO_PID
{
	
public:
	
	ANO_PID(){
		kP = kI = kD = 0;
		imax = 0;
	}

	//PID參數
	uint16_t kP;
	uint16_t kI;
	uint16_t kD;
	
	//返回PID計算的值
	int32_t get_pid(int32_t error, uint16_t dt);
	int32_t get_pi(int32_t error, uint16_t dt);
	int32_t get_p(int32_t error);
	int32_t get_i(int32_t error, uint16_t dt);
	int32_t get_d(int32_t error, uint16_t dt);
	
	//積分控制器的值清零
	void reset_I(void);
	
	void set_pid(const uint16_t p,
									 const uint16_t i,
									 const uint16_t d,
									 const uint32_t  imaxval) {
			kP = p; kI = i; kD = d; imax = imaxval;
	}
	
private:
	
	//積分上限
	uint32_t imax;
	//積分器的值
	int32_t integrator; 
	//上一次的誤差輸入
	int32_t last_error;
};



#endif


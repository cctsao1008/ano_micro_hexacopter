#include "ANO_Math.h"

//保證輸入值是有效的
float safe_asin(float v)
{
    if (isnan(v)) {
        return 0.0;
    }
    if (v >= 1.0f) {
        return M_PI/2;
    }
    if (v <= -1.0f) {
        return -M_PI/2;
    }
    return asinf(v);
}

//浮點數限幅
float constrain_float(float amt, float low, float high) 
{
	if (isnan(amt)) {
		return (low+high)*0.5f;
	}
	return ((amt)<(low)?(low):((amt)>(high)?(high):(amt)));
}

//16位整型數限幅
int16_t constrain_int16(int16_t amt, int16_t low, int16_t high) {
	return ((amt)<(low)?(low):((amt)>(high)?(high):(amt)));
}

//16位無符號整型數限幅
uint16_t constrain_uint16(uint16_t amt, uint16_t low, uint16_t high)
{
	return ((amt)<(low)?(low):((amt)>(high)?(high):(amt)));
}

//32位整型數限幅
int32_t constrain_int32(int32_t amt, int32_t low, int32_t high) {
	return ((amt)<(low)?(low):((amt)>(high)?(high):(amt)));
}

//角度轉弧度
float radians(float deg) {
	return deg * DEG_TO_RAD;
}

//弧度轉角度
float degrees(float rad) {
	return rad * RAD_TO_DEG;
}

//求平方
float sq(float v) {
	return v*v;
}

//2維向量長度
float pythagorous2(float a, float b) {
	return sqrtf(sq(a)+sq(b));
}

//3維向量長度
float pythagorous3(float a, float b, float c) {
	return sqrtf(sq(a)+sq(b)+sq(c));
}

//4維向量長度
float pythagorous4(float a, float b, float c, float d) {
	return sqrtf(sq(a)+sq(b)+sq(c)+sq(d));
}












#ifndef __ANO_MATH_H__
#define __ANO_MATH_H__

#include <stdint.h>
#include <stddef.h>
#include <math.h>
#include "ANO_Rotations.h"
#include "ANO_Vector3.h"
#include "ANO_Quaternion.h"

#define M_PI 3.141592653f
#define DEG_TO_RAD 0.01745329f
#define RAD_TO_DEG 57.29577951f

float safe_asin(float v);

//浮點數限幅
float constrain_float(float amt, float low, float high);

//16位整型數限幅
int16_t constrain_int16(int16_t amt, int16_t low, int16_t high);

//16位無符號整型數限幅
uint16_t constrain_uint16(uint16_t amt, uint16_t low, uint16_t high);

//32位整型數限幅
int32_t constrain_int32(int32_t amt, int32_t low, int32_t high);

//角度轉弧度
float radians(float deg);

//弧度轉角度
float degrees(float rad);

//求平方
float sq(float v);

//2維向量長度
float pythagorous2(float a, float b);

//3維向量長度
float pythagorous3(float a, float b, float c); 

//4維向量長度
float pythagorous4(float a, float b, float c, float d);


#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define abs(x) ((x) > 0 ? (x) : -(x))

#endif








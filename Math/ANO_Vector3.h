#ifndef __VECTOR3_H
#define __VECTOR3_H

#include <stdint.h>
#include <math.h>

template <typename T>
class Vector3
{
public:
    T	x, y, z;

		//構造函數，初始化向量值為0
    Vector3<T>() {
        x = y = z = 0;
    }
		
		//賦值構造函數
    Vector3<T>(const T x0, const T y0, const T z0) : x(x0), y(y0), z(z0) {
    }		
		
    void operator ()(const T x0, const T y0, const T z0)
    {
        x= x0; y= y0; z= z0;
    }		
		
		//向量旋轉
		void rotate(enum Rotation rotation);
		
		//獲取本向量平方
    T  length_squared() const
    {
        return (T)(*this * *this);
    }
		
		//獲取本向量長度
    float length(void) const;
		
    //向量歸一化
    void normalize()
    {
        *this /= length();
    }
		
    //向量置零
    void zero()
    {
        x = y = z = 0;
    }
		
    //返回歸一化向量
    Vector3<T> normalized() const
    {
        return *this/length();
    }
		
	  //計算兩個向量之間的夾角
    float angle(const Vector3<T> &v2) const;	
		
		void get_rollpitch(Vector3<T> &angle);
		
		void get_yaw(Vector3<T> &angle);	
		
    // 檢查是否有元素的值為 NAN
    bool is_nan(void) const;		
		
/*************************運算符重載********************************/		
    //點積
    T operator *(const Vector3<T> &v) const;

    //叉積
    Vector3<T> operator %(const Vector3<T> &v) const;		
		
    //與標量相乘
    Vector3<T> operator *(const T num) const;
    Vector3<T> &operator *=(const T num);
		
    //與標量相除
    Vector3<T> operator  /(const T num) const;
    Vector3<T> &operator /=(const T num);
		
		//取反
	  Vector3<T> operator -(void) const;
	
	  //相加
    Vector3<T> operator +(const Vector3<T> &v) const;
    Vector3<T> &operator +=(const Vector3<T> &v);
		
    //相減
    Vector3<T> operator -(const Vector3<T> &v) const;
    Vector3<T> &operator -=(const Vector3<T> &v);
		
    //對比兩個向量是否相等
    bool operator ==(const Vector3<T> &v) const;

    //對比兩個向量是否不相等
    bool operator !=(const Vector3<T> &v) const;
		
/*******************************************************************/	
		
};

typedef Vector3<int16_t>                Vector3i;
typedef Vector3<uint16_t>               Vector3ui;
typedef Vector3<int32_t>                Vector3l;
typedef Vector3<uint32_t>               Vector3ul;
typedef Vector3<float>                  Vector3f;
typedef Vector3<double>                 Vector3d;

#endif // VECTOR3_H


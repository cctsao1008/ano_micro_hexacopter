#ifndef QUATERNION_H
#define QUATERNION_H

#include <math.h>

class Quaternion
{
public:
    float        q1, q2, q3, q4;

    // 構造函數
    // roll=0, pitch=0, yaw=0
    Quaternion() {
        q1 = 1; q2 = q3 = q4 = 0;
    }

    //賦值構造函數
    Quaternion(const float _q1, const float _q2, const float _q3, const float _q4) :
        q1(_q1), q2(_q2), q3(_q3), q4(_q4) {
    }

    //函數調用操作符
    void operator        ()(const float _q1, const float _q2, const float _q3, const float _q4)
    {
        q1 = _q1; q2 = _q2; q3 = _q3; q4 = _q4;
    }
		
		//四元數歸一化
		void normalize(void);

    // 返回該四元數的等效旋轉矩陣中的重力份量
    void vector_gravity(Vector3f &v);

		//一階龍格庫塔法更新四元數
		void Runge_Kutta_1st(Vector3f &g, float deltaT);
		
    //歐拉角轉四元數
    void from_euler(float roll, float pitch, float yaw);

    //四元數轉歐拉角
    void to_euler(float *roll, float *pitch, float *yaw);
};
#endif // QUATERNION_H















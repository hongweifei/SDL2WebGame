


#include "vector2.h"

#ifndef BODY_HEAD
#define BODY_HEAD


typedef struct __body__ Body;


typedef struct __body__
{
    Vector2 position;//位置
    float rotation;//旋转

    Vector2 velocity;//速度
    float angular_velocity;//角速度

    Vector2 force;//力量
	float torque;//力矩,扭矩

	Vector2 width;//宽

    float friction;//摩擦力
    float mass;//质量
};





#endif




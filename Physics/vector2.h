


#ifndef VECTOR2_HEAD
#define VECTOR2_HEAD


#ifndef BOOL
#define BOOL short
#define TRUE 1
#define FALSE 0
#endif


typedef struct __vector_2__ Vector2;


typedef struct __vector_2__
{
    float x;
    float y;
};

Vector2 *Vector2Init(float x,float y);
#define Vector2Init_() Vector2Init(0,0)

Vector2 *Vector2Plus(Vector2 *dest,const Vector2 *src);
Vector2 *Vector2Minus(Vector2 *dest,const Vector2 *src);
Vector2 *Vector2Multiply(Vector2 *dest,const float a);

float Vector2Length(Vector2 *v);


#endif



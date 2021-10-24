

#include "vector2.h"
#include <math.h>

Vector2 *Vector2Init(float x,float y)
{
    Vector2 *v = (Vector2*)malloc(sizeof(Vector2));
    v->x = x;
    v->y = y;

    return v;
}


Vector2 *Vector2Plus(Vector2 *dest,const Vector2 *src)
{
    dest->x += src->x;
    dest->y += src->y;

    return dest;
}


Vector2 *Vector2Minus(Vector2 *dest,const Vector2 *src)
{
    dest->x -= src->x;
    dest->y -= src->y;

    return dest;
}

Vector2 *Vector2Multiply(Vector2 *dest,const float a)
{
    dest->x *= a;
    dest->y *= a;

    return dest;
}


float Vector2Length(Vector2 *v)
{
    /**             A
     *              +
     *            + +
     *           +  +
     *         +    +
     *       +      +
     *     +        +
     * C +----------+ B
     * 
     * AB = y
     * BC = x
     * AC * AC = x * x  +  y * y
    */
    return sqrtf(v->x * v->x + v->y * v->y);//求平方根,得到 AC
}



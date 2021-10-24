



#include <math.h>

#include "vector2.h"


#ifndef WORLD_HEAD
#define WORLD_HEAD


#ifndef BOOL
#define BOOL short
#define TRUE 1
#define FALSE 0
#endif


typedef struct __world__ World;


typedef struct __world__
{
    Vector2 gravity;//ÖØÁ¦

    BOOL position_correction;
};


World *WorldInit();
#define WorldInit WorldInit

void WorldAdd();



#endif



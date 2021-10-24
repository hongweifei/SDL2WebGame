



#pragma once

#include "include/SDL2/SDL.h"
#include <stdio.h>

/*
#ifdef _WIN32
#undef main
#endif
*/

#define SYSTEM_INIT_TIMER          0x00000001u
#define SYSTEM_INIT_AUDIO          0x00000010u
#define SYSTEM_INIT_VIDEO          0x00000020u  /**< SYSTEM_INIT_VIDEO implies SYSTEM_INIT_EVENTS */
#define SYSTEM_INIT_JOYSTICK       0x00000200u  /**< SYSTEM_INIT_JOYSTICK implies SYSTEM_INIT_EVENTS */
#define SYSTEM_INIT_HAPTIC         0x00001000u
#define SYSTEM_INIT_GAMECONTROLLER 0x00002000u  /**< SYSTEM_INIT_GAMECONTROLLER implies SYSTEM_INIT_JOYSTICK */
#define SYSTEM_INIT_EVENTS         0x00004000u
#define SYSTEM_INIT_SENSOR         0x00008000u
#define SYSTEM_INIT_NOPARACHUTE    0x00100000u  /**< compatibility; this flag is ignored. */
#define SYSTEM_INIT_EVERYTHING ( \
                SYSTEM_INIT_TIMER | SYSTEM_INIT_AUDIO | SYSTEM_INIT_VIDEO | SYSTEM_INIT_EVENTS | \
                SYSTEM_INIT_JOYSTICK | SYSTEM_INIT_HAPTIC | SYSTEM_INIT_GAMECONTROLLER | SYSTEM_INIT_SENSOR \
            )


int SystemInit(uint32_t mod)
{
    return SDL_Init(mod);
}















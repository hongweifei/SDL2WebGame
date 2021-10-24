


#include "../include/SDL2/SDL.h"
#include "renderer.h"

#ifndef WINDOW_HEAD
#define WINDOW_HEAD

#ifndef BOOL
#define BOOL short
#define TRUE 1
#define FALSE 0
#endif

#define WINDOW_POS_CENTERED  SDL_WINDOWPOS_CENTERED
#define WINDOW_POS_UNDEFINED SDL_WINDOWPOS_UNDEFINED

typedef enum __window_flags__
{
    WINDOW_FULLSCREEN = 0x00000001,         /**< fullscreen window */
    WINDOW_OPENGL = 0x00000002,             /**< window usable with OpenGL context */
    WINDOW_SHOWN = 0x00000004,              /**< window is visible */
    WINDOW_HIDDEN = 0x00000008,             /**< window is not visible */
    WINDOW_BORDERLESS = 0x00000010,         /**< no window decoration */
    WINDOW_RESIZABLE = 0x00000020,          /**< window can be resized */
    WINDOW_MINIMIZED = 0x00000040,          /**< window is minimized */
    WINDOW_MAXIMIZED = 0x00000080,          /**< window is maximized */
    WINDOW_INPUT_GRABBED = 0x00000100,      /**< window has grabbed input focus */
    WINDOW_INPUT_FOCUS  = 0x00000200,       /**< window has input focus */
    WINDOW_MOUSE_FOCUS = 0x00000400,        /**< window has mouse focus */
    WINDOW_FULLSCREEN_DESKTOP = ( SDL_WINDOW_FULLSCREEN | 0x00001000 ),
    WINDOW_FOREIGN  = 0x00000800,           /**< window not created by SDL */

    WINDOW_ALLOW_HIGHDPI = 0x00002000,      /**< window should be created in high-DPI mode if supported. */
                                                /**  On macOS NSHighResolutionCapable must be set true in the */
                                                /**  application's Info.plist for this to have any effect. */

    WINDOW_MOUSE_CAPTURE = 0x00004000,      /**< window has mouse captured (unrelated to INPUT_GRABBED) */
    WINDOW_ALWAYS_ON_TOP = 0x00008000,      /**< window should always be above others */
    WINDOW_SKIP_TASKBAR = 0x00010000,       /**< window should not be added to the taskbar */
    WINDOW_UTILITY = 0x00020000,            /**< window should be treated as a utility window */
    WINDOW_TOOLTIP = 0x00040000,            /**< window should be treated as a tooltip */
    WINDOW_POPUP_MENU = 0x00080000,         /**< window should be treated as a popup menu */
    WINDOW_VULKAN = 0x10000000,             /**< window usable for Vulkan surface */
}WindowFlags;



typedef struct __window__  Window;
typedef void(*WindowEvent)(Window*);
typedef void(*WindowRenderEvent)(Renderer*,Window*);

static unsigned long thread_delay_time = 1000/60;

typedef struct __window__
{
    SDL_Window *win;
    Renderer *renderer;

    int x,y;
    int width,height;
    Uint32 id;

    Surface *icon;

    WindowRenderEvent render_event;
}Window;



Window *WindowCreate(const char*,int,int,Uint32);
#define WindowCreate_(title,width,height) WindowCreate(title,width,height,WINDOW_SHOWN|WINDOW_OPENGL|WINDOW_RESIZABLE)//创建窗口


void WindowMainLoop(int window_count,...);

void WindowDestroy(Window*);

const char *WindowGetTitle(Window*);
void WindowSetTitle(Window*,const char*);

int WindowGetX(Window*);
int WindowGetY(Window*);
int WindowGetWidth(Window*);
int WindowGetHeight(Window*);

void WindowSetX(Window*,int);
void WindowSetY(Window*,int);
void WindowSetWidth(Window*,int);
void WindowSetHeight(Window*,int);

void WindowGetPosition(Window*,int*,int*);
void WindowGetSize(Window*,int*,int*);

void WindowSetPosition(Window*,int,int);
void WindowSetSize(Window*,int,int);


#endif



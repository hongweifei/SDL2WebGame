


#include "../renderer.h"


#ifndef WIDGET_HEAD
#define WIDGET_HEAD


typedef struct __widget__ Widget;
typedef void(*WidgetRenderEvent)(Renderer*,Widget*);


typedef struct __widget__
{
    FRect rect;
    WidgetRenderEvent render_event;
}Widget,_Widget;


Widget *WidgetCreate_A(float,float,float,float);
Widget *WidgetCreate_B();



#endif



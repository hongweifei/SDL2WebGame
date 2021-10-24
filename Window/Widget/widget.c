


#include "widget.h"





Widget *WidgetCreate_A(float x,float y,float w,float h)
{
    Widget *widget = (Widget*)malloc(sizeof(Widget));
    
    widget->rect.x = x;
    widget->rect.y = y;
    widget->rect.w = w;
    widget->rect.h = h;

    return widget;
}


Widget *WidgetCreate_B()
{
    return WidgetCreate_A(0,0,0,0);
}



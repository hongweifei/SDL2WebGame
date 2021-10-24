


#include "Window.h"
#include "../include/SDL2/SDL_image.h"


/**创建窗口*/
Window *WindowCreate(const char *title,int w,int h,Uint32 flags)
{
    Window *window = (Window*)malloc(sizeof(Window));

    window->width = w;
    window->height = h;

    window->win = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,window->width,window->height,flags);

    WindowGetX(window);
    WindowGetY(window);
    window->id = SDL_GetWindowID(window->win);

    window->renderer = RendererCreate_(window->win);
    window->render_event = NULL;

    Surface *surface;
    if((surface = IMG_Load("./ico.bmp")) != NULL)
        window->icon = surface;
    else if((surface = IMG_Load("./ico.jpg")) != NULL)
        window->icon = surface;
    else if((surface = IMG_Load("./ico.png")) != NULL)
        window->icon = surface;

    SDL_SetWindowIcon(window->win,window->icon);
    
    return window;
}

/**窗口主循环*/
void WindowMainLoop(int window_count,...)
{
    int i = 0;
    SDL_Event event;//事件


    /**取出窗口*/
    Window **window = (Window**)calloc(window_count,sizeof(Window*));//各个窗口
    //SDL_Thread *window_thread[window_n];//各个窗口事件线程

    va_list window_list;//窗口列表
    va_start(window_list, window_count);

    for (i = 0; i < window_count; i++)
    {
        window[i] = va_arg(window_list, Window*);//将各个窗口取出
    }

    va_end(window_list);


    /**窗口销毁信息记录*/
    int window_was_destroyed_count = 0;//被销毁窗口的数量
    int window_need_to_destroy_count = 0;//要销毁的窗口的数量
    int *window_need_to_destroy_index = (int*)calloc(0,sizeof(int));//要销毁的窗口记录


    /**循环*/
    while (window_was_destroyed_count < window_count)
    {
        /*窗口销毁*/
        if (window_need_to_destroy_count > 0)
        {
            i = 0;
            while (i < window_need_to_destroy_count)
            {
                WindowDestroy(window[window_need_to_destroy_index[i]]);//销毁 需要销毁窗口
                window_was_destroyed_count++;//被销毁窗口数量+1
                window_need_to_destroy_count--;//需要销毁窗口数量-1
                i++;
            }
            
            window_need_to_destroy_count++;
        }

        /**处理各个窗口事件*/
        for (i = 0; i < window_count; i++)
        {
            if (SDL_PollEvent(&event))//获取事件
            {
                switch (event.type)//判断事件类型
                {
                case SDL_QUIT://退出事件
                    SDL_Log("Program quit after %i ticks", event.quit.timestamp);
                    break;
                case SDL_USEREVENT://用户事件
                    break;
                case SDL_WINDOWEVENT://窗口事件
                    if (event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == window[i]->id)//窗口关闭，且id等于执行事件的窗口
                    {
                        WindowDestroy(window[i]);//销毁窗口
                        window_was_destroyed_count++;//窗口被销毁数量+1
                    }
                    else if (event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID != window[i]->id)
                    {
                        window_need_to_destroy_count++;//要销毁窗口+1
                        window_need_to_destroy_index = realloc(window_need_to_destroy_index,sizeof(int) * window_need_to_destroy_count);
                        window_need_to_destroy_index[window_need_to_destroy_count - 1] = i;//记录需要销毁窗口的索引
                    }
                    break;
                }
            }

            /*获取执行事件的窗口的坐标与大小*/
            WindowGetPosition(window[i],NULL,NULL);
            WindowGetSize(window[i],NULL,NULL);

            RendererClear(window[i]->renderer);
            if(window[i]->render_event != NULL)
                window[i]->render_event(window[i]->renderer, window[i]);
            RendererPresent(window[i]->renderer);
            
        }

        SDL_Delay(thread_delay_time);
    }
    

    


    
    
}


/**销毁窗口*/
void WindowDestroy(Window *window)
{
    SDL_DestroyWindow(window->win);
    SDL_FreeSurface(window->icon);
    free(window);
}



/**获取窗口标题*/
const char *WindowGetTitle(Window *window)
{
    return SDL_GetWindowTitle(window->win);
}

/**设置窗口标题*/
void WindowSetTitle(Window *window,const char *title)
{
    SDL_SetWindowTitle(window->win,title);
}


/**获取窗口X坐标*/
int WindowGetX(Window *window)
{
    SDL_GetWindowPosition(window->win,&window->x,NULL);
    return window->x;
}

/**获取窗口Y坐标*/
int WindowGetY(Window *window)
{
    SDL_GetWindowPosition(window->win,NULL,&window->y);
    return window->y;
}

/**获取窗口宽度*/
int WindowGetWidth(Window *window)
{
    SDL_GetWindowSize(window->win,&window->width,NULL);
    return window->width;
}

/**获取窗口高度*/
int WindowGetHeight(Window *window)
{
    SDL_GetWindowSize(window->win,NULL,&window->height);
    return window->height;
}

/**设置窗口X*/
void WindowSetX(Window *window,int x)
{
    window->x = x;
    SDL_SetWindowPosition(window->win,window->x,window->y);
}

/**设置窗口Y*/
void WindowSetY(Window *window,int y)
{
    window->y = y;
    SDL_SetWindowPosition(window->win,window->x,window->y);
}

/**设置窗口宽度*/
void WindowSetWidth(Window *window,int w)
{
    window->width = w;
    SDL_SetWindowSize(window->win,window->width,window->height);
}

/**设置窗口高度*/
void WindowSetHeight(Window *window,int h)
{
    window->height = h;
    SDL_SetWindowSize(window->win,window->width,window->height);
}

/**获取窗口位置*/
void WindowGetPosition(Window *window,int *x,int *y)
{
    SDL_GetWindowPosition(window->win,&window->x,&window->y);

    if(x != NULL)
        *x = window->x;
    if(y != NULL)
        *y = window->y;
}

/**获取窗口大小*/
void WindowGetSize(Window *window,int *w,int *h)
{
    SDL_GetWindowSize(window->win,&window->width,&window->height);

    if(w != NULL)
        *w = window->width;
    if(h != NULL)
        *h = window->height;
}

/**设置窗口位置*/
void WindowSetPosition(Window *window,int x,int y)
{
    window->x = x;
    window->y = y;
    SDL_SetWindowPosition(window->win,window->x,window->y);
}

/**设置窗口大小*/
void WindowSetSize(Window *window,int w,int h)
{
    window->width = w;
    window->height = h;
    SDL_SetWindowSize(window->win,window->width,window->height);
}



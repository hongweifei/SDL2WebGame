


#include "renderer.h"
#include "window.h"
#include <stdio.h>
#include "../include/SDL2/SDL_image.h"


Renderer *RendererCreate(SDL_Window *window,Uint32 flags)
{
    return SDL_CreateRenderer(window,-1,flags);
}


/**设置绘制颜色*/
int RendererSetDrawColor(Renderer *renderer,Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    return SDL_SetRenderDrawColor(renderer,r,g,b,a);
}



/**清空*/
int RendererClear(Renderer *renderer)
{
    return SDL_RenderClear(renderer);
}

int RendererFlush(Renderer *renderer)
{
    return SDL_RenderFlush(renderer);
}

/**交换*/
void RendererPresent(Renderer *renderer)
{
    SDL_RenderPresent(renderer);
}



/**画线*/
int RendererDrawLine(Renderer *renderer,int x1,int y1,int x2,int y2)
{
    return SDL_RenderDrawLine(renderer,x1,y1,x2,y2);
}

/**通过点来画线，可绘制多条*/
int RendererDrawLines(Renderer *renderer,const Point *points,int count)
{
    return SDL_RenderDrawLines(renderer,points,count);
}

/**画线，坐标使用浮点数*/
int RendererDrawLineF(Renderer *renderer,float x1, float y1, float x2, float y2)
{
    return SDL_RenderDrawLineF(renderer,x1,y1,x2,y2);
}

/**通过点来画线，可绘制多条，坐标使用浮点数*/
int RendererDrawLinesF(Renderer *renderer,const FPoint *points, int count)
{
    return SDL_RenderDrawLinesF(renderer,points,count);
}


/**绘制点*/
int RendererDrawPoint(Renderer *renderer,int x,int y)
{
    return SDL_RenderDrawPoint(renderer,x,y);
}

/**绘制多个点*/
int RendererDrawPoints(Renderer *renderer,const Point *points, int count)
{
    return SDL_RenderDrawPoints(renderer,points,count);
}

/**绘制点，坐标使用浮点数*/
int RendererDrawPointF(Renderer *renderer,float x, float y)
{
    return SDL_RenderDrawPointF(renderer,x,y);
}

/**绘制多个点，坐标使用浮点数*/
int RendererDrawPointsF(Renderer *renderer,const FPoint *points, int count)
{
    return SDL_RenderDrawPointsF(renderer,points,count);
}



/**绘制矩形*/
int RendererDrawRect(Renderer *renderer,const Rect *rect)
{
    return SDL_RenderDrawRect(renderer,rect);
}

/**绘制多个矩形*/
int RendererDrawRects(Renderer *renderer,const Rect *rects,int count)
{
    return SDL_RenderDrawRects(renderer,rects,count);
}


/**绘制矩形，坐标使用浮点数*/
int RendererDrawRectF(Renderer *renderer,const FRect *rect)
{
    return SDL_RenderDrawRectF(renderer,rect);
}

/**绘制多个矩形，坐标使用浮点数*/
int RendererDrawRectsF(Renderer *renderer,const FRect *rects,int count)
{
    return SDL_RenderDrawRectsF(renderer,rects,count);
}

/**绘制实心矩形*/
int RendererDrawFillRect(Renderer *renderer,const Rect *rect)
{
    return SDL_RenderFillRect(renderer,rect);
}

/**绘制多个实心矩形*/
int RendererDrawFillRects(Renderer *renderer,const Rect *rects, int count)
{
    return SDL_RenderFillRects(renderer,rects,count);
}

/**绘制实心矩形，坐标使用浮点数*/
int RendererDrawFillRectF(Renderer *renderer,const FRect *rect)
{
    return SDL_RenderFillRectF(renderer,rect);
}

/**绘制多个实心矩形，坐标使用浮点数*/
int RendererDrawFillRectsF(Renderer *renderer,const FRect *rects, int count)
{
    return SDL_RenderFillRectsF(renderer,rects,count);
}


/**绘制image，可翻转，可裁剪，坐标使用整数*/
int RendererDrawImage_RectA(Renderer *renderer,const char *path, const Rect *src,const Rect *dest,RenderFlip flip)
{
    static BOOL first = TRUE;
    
    static int count = 0;
    static const char** cache_path = NULL;
    static Surface* surface = NULL;
    static Texture** texture = NULL;

    static int draw_index = 0;

    if (first)
    {
        cache_path = (const char**)calloc(0, sizeof(char*));
        texture = (Texture**)calloc(count, sizeof(Texture*));
    }
    


    for (int i = 0; i < count; i++)
    {
        if (strcmp(cache_path[i], path) == 0)
        {
            draw_index = i;
            goto draw;
        }
    }

    cache_path = (const char**)realloc(cache_path, sizeof(char*) * (count + 1));
    cache_path[count] = path;

    surface = IMG_Load(cache_path[count]);
    if (surface == NULL)
    {
        fprintf(stderr, "CreateSurface failed: %s\n", SDL_GetError());
        return -1;
    }

    texture = (Texture**)calloc(count + 1, sizeof(Texture*));
    texture[count] = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture[count] == NULL)
    {
        fprintf(stderr, "CreateTextureFromSurface failed: %s\n", SDL_GetError());
        return -1;
    }

    SDL_FreeSurface(surface);
    surface = NULL;

    count++;
    draw_index = count - 1;

draw:
    return RendererDrawTexture_RectD(renderer, texture[draw_index], src, dest,flip);
}

/**绘制image，不可翻转，可裁剪，坐标使用整数*/
int RendererDrawImage_RectB(Renderer *renderer,const char *path, const Rect *src, const Rect *dest)
{
    return RendererDrawImage_RectA(renderer, path, src, dest,FLIP_NONE);
}

/**绘制image，可翻转，不可裁剪，坐标使用整数*/
int RendererDrawImage_RectC(Renderer *renderer,const char *path, const Rect *dest, RenderFlip flip)
{
    return RendererDrawImage_RectA(renderer, path, NULL, dest,flip);
}

/**绘制image，不可翻转，不可裁剪，坐标使用整数*/
int RendererDrawImage_RectD(Renderer *renderer,const char *path, int x, int y, int width, int height)
{
    Rect rect = { x,y,width,height };
    return RendererDrawImage_RectA(renderer, path, NULL, &rect,FLIP_NONE);
}



/*绘制image，可翻转，可裁剪，坐标使用浮点数*/
int RendererDrawImage_FloatRectA(Renderer *renderer,const char *path, const Rect *src,const FRect *dest,RenderFlip flip)
{
    static BOOL first = TRUE;
    
    static int count = 0;
    static const char** cache_path = NULL;
    static Surface* surface = NULL;
    static Texture** texture = NULL;

    static int draw_index = 0;

    if (first)
    {
        cache_path = (const char**)calloc(0, sizeof(char*));
        texture = (Texture**)calloc(count, sizeof(Texture*));
    }
    


    for (int i = 0; i < count; i++)
    {
        if (strcmp(cache_path[i], path) == 0)
        {
            draw_index = i;
            goto draw;
        }
    }

    cache_path = (const char**)realloc(cache_path, sizeof(char*) * (count + 1));
    cache_path[count] = path;

    surface = IMG_Load(cache_path[count]);
    if (surface == NULL)
    {
        fprintf(stderr, "CreateSurface failed: %s\n", SDL_GetError());
        return -1;
    }

    texture = (Texture**)calloc(count + 1, sizeof(Texture*));
    texture[count] = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture[count] == NULL)
    {
        fprintf(stderr, "CreateTextureFromSurface failed: %s\n", SDL_GetError());
        return -1;
    }

    SDL_FreeSurface(surface);
    surface = NULL;

    count++;
    draw_index = count - 1;

draw:
    return RendererDrawTexture_FloatRectD(renderer, texture[draw_index], src, dest,flip);
}

/**绘制image，不可翻转，可裁剪，坐标使用浮点数*/
int RendererDrawImage_FloatRectB(Renderer *renderer,const char *path, const Rect *src, const FRect *dest)
{
    return RendererDrawImage_FloatRectA(renderer, path, src, dest,FLIP_NONE);
}

/**绘制image，可翻转，不可裁剪，坐标使用浮点数*/
int RendererDrawImage_FloatRectC(Renderer *renderer,const char *path, const FRect *dest, RenderFlip flip)
{
    return RendererDrawImage_FloatRectA(renderer, path, NULL, dest,flip);
}

/*绘制image，不可翻转，不可裁剪，坐标使用浮点数*/
int RendererDrawImage_FloatRectD(Renderer *renderer,const char *path, float x, float y, float width, float height)
{
    _FRect rect = { x,y,width,height };
    return RendererDrawImage_FloatRectA(renderer, path, NULL, &rect,FLIP_NONE);
}



/*绘制纹理，不可翻转*/
int RendererDrawTexture_A(Renderer *renderer,Texture *texture)
{
    return SDL_RenderCopy(renderer, texture, NULL, NULL);
}

/*绘制纹理，可翻转*/
int RendererDrawTexture_B(Renderer *renderer,Texture *texture, const RenderFlip flip)
{
    return SDL_RenderCopyEx(renderer, texture, NULL, NULL,0,NULL,(SDL_RendererFlip)flip);
}


/*绘制纹理，不可翻转*/
int RendererDrawTexture_RectA(Renderer *renderer,Texture *texture, const Rect *dest)
{
    return SDL_RenderCopy(renderer, texture, NULL, dest);
}

/**绘制纹理，不可翻转，坐标使用浮点数*/
int RendererDrawTexture_FloatRectA(Renderer *renderer,Texture *texture, const FRect *dest)
{
    return SDL_RenderCopyF(renderer, texture, NULL, dest);
}


/*绘制纹理，可翻转*/
int RendererDrawTexture_RectB(Renderer *renderer,Texture *texture, const Rect *dest, const RenderFlip flip)
{
    return SDL_RenderCopyEx(renderer, texture, NULL, dest, 0, NULL, (SDL_RendererFlip)flip);
}

/**绘制纹理，可翻转，坐标使用浮点数*/
int RendererDrawTexture_FloatRectB(Renderer *renderer,Texture *texture, const FRect *dest, const RenderFlip flip)
{
    return SDL_RenderCopyExF(renderer, texture, NULL, dest, 0, NULL, (SDL_RendererFlip)flip);
}


/*绘制纹理，不可翻转，可裁剪源图片*/
int RendererDrawTexture_RectC(Renderer *renderer,Texture *texture, const Rect *src, const Rect *dest)
{
    return SDL_RenderCopy(renderer, texture, src, dest);
}

/**绘制纹理，不可翻转，可裁剪源图片，坐标使用浮点数*/
int RendererDrawTexture_FloatRectC(Renderer *renderer,Texture *texture, const Rect *src, const FRect *dest)
{
    return SDL_RenderCopyF(renderer, texture, src, dest);
}


/*绘制纹理，可翻转，可裁剪源图片*/
int RendererDrawTexture_RectD(Renderer *renderer,Texture *texture, const Rect *src, const Rect *dest, const RenderFlip flip)
{
    return SDL_RenderCopyEx(renderer, texture, src, dest, 0, NULL,(SDL_RendererFlip)flip);
}

/*绘制纹理，可翻转，可裁剪源图片，坐标使用浮点数*/
int RendererDrawTexture_FloatRectD(Renderer *renderer,Texture *texture, const Rect *src, const FRect *dest, const RenderFlip flip)
{
    return SDL_RenderCopyExF(renderer, texture, src, dest, 0, NULL, (SDL_RendererFlip)flip);
}



/*绘制纹理，可翻转，可旋转图片*/
int RendererDrawTexture_RectE(Renderer *renderer, SDL_Texture *texture, const SDL_Rect *dest, double angle, const RenderFlip flip)
{
    return SDL_RenderCopyEx(renderer, texture, NULL, dest, angle, NULL, (SDL_RendererFlip)flip);
}

/*绘制纹理，可翻转，可旋转图片，坐标使用浮点数*/
int RendererDrawTexture_FloatRectE(Renderer *renderer, SDL_Texture *texture, const SDL_FRect *dest, double angle,const RenderFlip flip)
{
    return SDL_RenderCopyExF(renderer, texture, NULL, dest, angle, NULL, (SDL_RendererFlip)flip);
}


/*绘制纹理，可翻转，可旋转图片，可裁剪源图片*/
int RendererDrawTexture_RectF(Renderer *renderer, SDL_Texture *texture, const SDL_Rect *src, const SDL_Rect *dest, double angle, const RenderFlip flip)
{
    return SDL_RenderCopyEx(renderer, texture, src, dest, angle, NULL, (SDL_RendererFlip)flip);
}

/*绘制纹理，可翻转，可旋转图片，可裁剪源图片，坐标使用浮点数*/
int RendererDrawTexture_FloatRectF(Renderer *renderer, SDL_Texture *texture, const SDL_Rect *src, const SDL_FRect *dest, double angle, const RenderFlip flip)
{
    return SDL_RenderCopyExF(renderer, texture, src, dest, angle, NULL, (SDL_RendererFlip)flip);
}




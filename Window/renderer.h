


#include "../include/SDL2/SDL.h"

#ifndef RENDERER_HEAD
#define RENDERER_HEAD


#define RENDERER_SOFTWARE       SDL_RENDERER_SOFTWARE       //the renderer is a software fallback
#define RENDERER_ACCELERATED    SDL_RENDERER_ACCELERATED    //the renderer uses hardware acceleration
#define RENDERER_PRESENTVSYNC   SDL_RENDERER_PRESENTVSYNC   //present is synchronized with the refresh rate
#define RENDERER_TARGETTEXTURE  SDL_RENDERER_TARGETTEXTURE  //the renderer supports rendering to texture




typedef enum __render_flip__
{
    FLIP_NONE = 0x00000000,         /**< Do not flip */
    FLIP_HORIZONTAL = 0x00000001,   /**< flip horizontally */
    FLIP_VERTICAL = 0x00000002      /**< flip vertically */
}RenderFlip;


/**Renderer*/
typedef struct SDL_Renderer __renderer__;
typedef struct SDL_Renderer Renderer;


/**Point*/
typedef struct SDL_Point __point__;
typedef struct SDL_Point Point;

/**FloatPoint*/
typedef struct SDL_FPoint __f_point__;
typedef struct SDL_FPoint FPoint;


/**Rect*/
typedef struct SDL_Rect __rect__;
typedef struct SDL_Rect Rect;

/**FloatRect*/
typedef struct SDL_FRect __f_rect__;
typedef struct SDL_FRect FRect;


/**Surface*/
typedef struct SDL_Surface __surface__;
typedef struct SDL_Surface Surface;

/**Texture*/
typedef struct SDL_Texture __texture__;
typedef struct SDL_Texture Texture;



Renderer *RendererCreate(SDL_Window *window,Uint32 flags);
#define RendererCreate_(window) RendererCreate(window,RENDERER_ACCELERATED)

int RendererSetDrawColor(Renderer*,Uint8, Uint8, Uint8, Uint8);

int RendererClear(Renderer*);//清空
int RendererFlush(Renderer*);
void RendererPresent(Renderer*);//交换

int RendererDrawLine(Renderer*,int,int,int,int);
int RendererDrawLines(Renderer*,const Point*,int);

int RendererDrawLineF(Renderer*,float, float, float, float);
int RendererDrawLinesF(Renderer*,const FPoint*, int);

int RendererDrawPoint(Renderer*,int,int);
int RendererDrawPoints(Renderer*,const Point*, int);

int RendererDrawPointF(Renderer*,float, float);
int RendererDrawPointsF(Renderer*,const FPoint*, int);

int RendererDrawRect(Renderer*,const Rect*);
int RendererDrawRects(Renderer*,const Rect*,int);

int RendererDrawRectF(Renderer*,const FRect*);
int RendererDrawRectsF(Renderer*,const FRect*,int);

int RendererDrawFillRect(Renderer*,const Rect*);
int RendererDrawFillRects(Renderer*,const Rect*, int);

int RendererDrawFillRectF(Renderer*,const FRect*);
int RendererDrawFillRectsF(Renderer*,const FRect*, int);


/*绘制image，坐标使用整数*/
int RendererDrawImage_RectA(Renderer*,const char*, const Rect *src, const Rect *dest, RenderFlip flip);
int RendererDrawImage_RectB(Renderer*,const char*, const Rect *src, const Rect *dest);
int RendererDrawImage_RectC(Renderer*,const char*, const Rect *dest, RenderFlip flip);
int RendererDrawImage_RectD(Renderer*,const char*, int, int, int, int);


/*绘制image，坐标使用浮点数*/
int RendererDrawImage_FloatRectA(Renderer*,const char*, const Rect*,const FRect*,RenderFlip);
int RendererDrawImage_FloatRectB(Renderer*,const char*, const Rect *src, const FRect *dest);
int RendererDrawImage_FloatRectC(Renderer*,const char*, const FRect *dest, RenderFlip flip);
int RendererDrawImage_FloatRectD(Renderer*,const char*, float, float, float, float);


/*绘制纹理，不可翻转*/
int RendererDrawTexture_A(Renderer*,Texture*);

/*绘制纹理，可翻转*/
int RendererDrawTexture_B(Renderer*,Texture*, const RenderFlip);

/*绘制纹理，不可翻转*/
int RendererDrawTexture_RectA(Renderer*,Texture*, const Rect*);
int RendererDrawTexture_FloatRectA(Renderer*,Texture*, const FRect*);

/*绘制纹理，可翻转*/
int RendererDrawTexture_RectB(Renderer*,Texture*, const Rect*, const RenderFlip);
int RendererDrawTexture_FloatRectB(Renderer*,Texture*, const FRect*, const RenderFlip);

/*绘制纹理，不可翻转，可裁剪源图片*/
int RendererDrawTexture_RectC(Renderer*,Texture*, const Rect*, const Rect*);
int RendererDrawTexture_FloatRectC(Renderer*,Texture*, const Rect*, const FRect*);

/*绘制纹理，可翻转，可裁剪源图片*/
int RendererDrawTexture_RectD(Renderer*,Texture*, const Rect*, const Rect*, const RenderFlip);
int RendererDrawTexture_FloatRectD(Renderer*,Texture*, const Rect*, const FRect*, const RenderFlip);


/*绘制纹理，可翻转，可旋转图片*/
int RendererDrawTexture_RectE(Renderer*, SDL_Texture*, const SDL_Rect*, double, const RenderFlip);
int RendererDrawTexture_FloatRectE(Renderer*, SDL_Texture*, const SDL_FRect*, double ,const RenderFlip);


/*绘制纹理，可翻转，可旋转图片，可裁剪源图片*/
int RendererDrawTexture_RectF(Renderer*, SDL_Texture*, const SDL_Rect*, const SDL_Rect*, double, const RenderFlip);
int RendererDrawTexture_FloatRectF(Renderer*, SDL_Texture*, const SDL_Rect*, const SDL_FRect*, double, const RenderFlip);




#endif //RENDERER_HEAD




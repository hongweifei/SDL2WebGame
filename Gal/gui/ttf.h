

#include "../../include/SDL2/SDL.h"
#include "../../include/SDL2/SDL_ttf.h"


#ifndef TTF_HEAD
#define TTF_HEAD

SDL_Renderer *ttf_renderer = NULL;

TTF_Font *font_default;
TTF_Font *font_big;
TTF_Font *font_small;

SDL_Color color_gray = {136,136,136};
SDL_Color color_blue = {0,153,204};
SDL_Color color_black = {0,0,0};
SDL_Color color_white = {255,255,255};

int TTFInit(SDL_Renderer *renderer)
{
    int error = TTF_Init();

    ttf_renderer = renderer;

    font_default = TTF_OpenFont("siyuan.ttf",20);
    font_big = TTF_OpenFont("siyuan.ttf",40);
    font_small = TTF_OpenFont("siyuan.ttf",14);
    
    return error;
}

SDL_Texture *CreateText(TTF_Font *font,const char *text,SDL_Color color)
{
    SDL_Surface *surface = TTF_RenderText_Solid(font,text,color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(ttf_renderer,surface);

    SDL_FreeSurface(surface);

    return texture;
}


int GetTextWidth(TTF_Font *font,const char *text)
{
    SDL_Surface *surface_text = TTF_RenderText_Solid(font,text,color_black);
    int width = surface_text->w;
    SDL_FreeSurface(surface_text);
    return width;
}


int GetTextHeight(TTF_Font *font,const char *text)
{
    SDL_Surface *surface_text = TTF_RenderText_Solid(font,text,color_black);
    int height = surface_text->h;
    SDL_FreeSurface(surface_text);
    return height;
}


void GetTextWidthAndHeight(TTF_Font *font,const char *text,int *width,int *height)
{
    SDL_Surface *surface_text = TTF_RenderText_Solid(font,text,color_black);
    *width = surface_text->w;
    *height = surface_text->h;
    SDL_FreeSurface(surface_text);
}


#endif


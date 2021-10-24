


#include "sprite.hpp"
#include "../include/SDL2/SDL_image.h"



Sprite::Sprite()
{
}

Sprite::Sprite(SDL_Renderer *renderer,const char *path)
{
    this->texture = IMG_LoadTexture(renderer,path);
    //IMG_ReadXPMFromArray(NULL);
}

Sprite::Sprite(SDL_Texture *texture)
{
    this->texture = texture;
}

Sprite::Sprite(SDL_Texture *texture,SDL_Rect *src_rect,double angle,SDL_RendererFlip flip)
{
    this->texture = texture;
    this->src_rect = src_rect;
    this->angle = angle;
    this->flip = flip;
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(this->texture);
    SDL_free(this->src_rect);
}


void Sprite::SetTexture(SDL_Texture *texture)
{
    this->texture = texture;
}

void Sprite::SetSrcRect(SDL_Rect *rect)
{
    this->src_rect = rect;
}

void Sprite::SetSrcRect(int x,int y,int w,int h)
{
    this->src_rect = new SDL_Rect();
    this->src_rect->x = x;
    this->src_rect->y = y;
    this->src_rect->w = w;
    this->src_rect->h = h;
}

void Sprite::SetAngle(double angle)
{
    this->angle = angle;
}

void Sprite::SetFlip(SDL_RendererFlip flip)
{
    this->flip = flip;
}


int Sprite::Render(SDL_Renderer *renderer,SDL_Rect *rect)
{
    return SDL_RenderCopyEx(renderer,this->texture,this->src_rect,rect,this->angle,NULL,this->flip);
}

int Sprite::Render(SDL_Renderer *renderer,SDL_FRect *rect)
{
    return SDL_RenderCopyExF(renderer,this->texture,this->src_rect,rect,this->angle,NULL,this->flip);
}


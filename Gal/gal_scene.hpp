

#include <vector>
#include "../include/SDL2/SDL.h"

#include "sprite.hpp"

#ifndef GAL_SCENE_HEAD
#define GAL_SCENE_HEAD


class GalScene
{
private:
    Sprite *background = new Sprite();

    std::vector<Sprite*> sprite;
    std::vector<SDL_FRect*> sprite_dest_rect;
public:
    GalScene();
    GalScene(SDL_Texture *texture,SDL_Rect *src_rect = NULL,double angle = 0,SDL_RendererFlip flip = SDL_FLIP_NONE);
    GalScene(std::vector<SDL_Texture*> texture);
    GalScene(std::vector<SDL_Texture*> texture,std::vector<SDL_FRect*> dest_rect);
    GalScene(std::vector<SDL_Texture*> texture,std::vector<SDL_Rect*> src_rect,std::vector<SDL_FRect*> dest_rect);
    GalScene(std::vector<SDL_Texture*> texture,std::vector<SDL_Rect*> src_rect,std::vector<SDL_FRect*> dest_rect,
    std::vector<double> angle,std::vector<SDL_RendererFlip> flip);
    
    ~GalScene();

    void SetBackground(SDL_Texture *texture,SDL_Rect *src_rect = NULL,double angle = 0,SDL_RendererFlip flip = SDL_FLIP_NONE);
    void SetBackground(Sprite *sprite);

    void SetTexture(std::vector<SDL_Texture*> texture);
    void SetTexture(short index,SDL_Texture *texture);

    void SetSrcRect(std::vector<SDL_Rect*> rect);
    void SetSrcRect(short index,SDL_Rect *rect);

    void SetDestRect(std::vector<SDL_FRect*> rect);
    void SetDestRect(short index,SDL_FRect *rect);

    void SetAngle(std::vector<double> angle);
    void SetAngle(short index,double angle);

    void SetFlip(std::vector<SDL_RendererFlip> flip);
    void SetFlip(short index,SDL_RendererFlip flip);

    void Render(SDL_Renderer *renderer);

    void AddSprite(Sprite *sprite,SDL_FRect *dest_rect = NULL);
    void AddSprite(Sprite *sprite,float x,float y,float w,float h);
    void AddSprite(SDL_Texture *texture,SDL_FRect *dest_rect = NULL);
    //void AddSprite(SDL_Texture *texture,SDL_Rect *src_rect = NULL,SDL_FRect *dest_rect = NULL,double angle = 0);
    void AddSprite(SDL_Texture *texture,SDL_Rect *src_rect = NULL,SDL_FRect *dest_rect = NULL,double angle = 0,SDL_RendererFlip flip = SDL_FLIP_NONE);
};



#endif



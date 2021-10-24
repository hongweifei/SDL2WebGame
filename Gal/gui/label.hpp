

#include "ttf.h"

#ifndef LABEL_HEAD
#define LABEL_HEAD




class Label
{
private:
    char *text = NULL;
    int width = 0;
    int height = 0;
    SDL_Texture *texture = NULL;
    SDL_FRect *dest_rect = NULL;
public:
    Label();
    Label(const char *text,SDL_FRect *dest_rect = NULL,TTF_Font *font = font_default,SDL_Color color = color_black);
    ~Label();

    void SetText();

    int GetTextWidth() {return this->width;}
    int GetTextHeight() {return this->height;}

    int Render(double angle = 0,SDL_RendererFlip flip = SDL_FLIP_NONE){SDL_RenderCopyExF(ttf_renderer,this->texture,NULL,this->dest_rect,angle,NULL,flip);}
};





#endif


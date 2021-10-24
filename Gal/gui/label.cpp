



#include "label.hpp"
#include "ttf.h"

Label::Label()
{
    this->text = "\0";
}


Label::Label(const char *text,SDL_FRect *dest_rect = NULL,TTF_Font *font,SDL_Color color)
{
    this->text = (char*)text;
    this->texture = CreateText(font,text,color);
    this->dest_rect = dest_rect;
    GetTextWidthAndHeight(font,text,&this->width,&this->height);
}

Label::~Label()
{
    SDL_DestroyTexture(this->texture);
    SDL_free(this->dest_rect);
}


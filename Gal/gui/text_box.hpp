

#include "label.h"

#ifndef TEXTBOX_HEAD
#define TEXTBOX_HEAD



class TextBox : private FlyLabel
{
private:
    SDL_Texture *box = NULL;
    SDL_FRect *box_dest_rect = NULL;
public:
    TextBox(/* args */);
    ~TextBox();
};

TextBox::TextBox(/* args */)
{
}

TextBox::~TextBox()
{
}



#endif


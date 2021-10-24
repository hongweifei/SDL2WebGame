

#include "gal_character.hpp"


GalCharacter::GalCharacter(std::string name)
{
    this->name = name;
    this->sprite = new FlySprite(NULL);
}

GalCharacter::GalCharacter(std::string name,SDL_Texture* texture)
{
    this->name = name;
    this->sprite = new FlySprite(texture);
}

GalCharacter::~GalCharacter()
{
    delete this->sprite;
}

void GalCharacter::SetTexture(SDL_Texture* texture)
{
    this->sprite->SetTexture(texture);
}

std::string GalCharacter::GetName()
{
    return this->name;
}

void GalCharacter::Render(SDL_Renderer *renderer)
{
    if(this->show)
        this->sprite->Render(renderer);
}

void GalCharacter::Show()
{
    this->show = true;
}

void GalCharacter::Hide()
{
    this->show = false;
}

void GalCharacter::Say(std::string text)
{
    printf("%s:\"%s\"\n",this->name.c_str(),text.c_str());
}



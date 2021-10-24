

#include <string>
#include "sprite.hpp"

#ifndef CHARACTER_HEAD
#define CHARACTER_HEAD


class GalCharacter
{
private:
    std::string name;
    Sprite *sprite;

    bool show = true;
public:
    GalCharacter(std::string name);
    GalCharacter(std::string name,SDL_Texture* texture);
    ~GalCharacter();

    void SetTexture(SDL_Texture* texture);
    std::string GetName();

    void Render(SDL_Renderer *renderer);

    void Show();
    void Hide();
    void Say(std::string text);
};




#endif


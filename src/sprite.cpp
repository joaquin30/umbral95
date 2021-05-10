#include "sprite.hpp"

Sprite::Sprite(SDL_Renderer *rend, SDL_Rect &r, const char *img)
{
    texture = IMG_LoadTexture(rend, img);
    rect = r;
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(texture);
}

void Sprite::draw(SDL_Renderer *rend)
{
    SDL_RenderCopy(rend, texture, nullptr, &rect);
}

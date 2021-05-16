#include "sprite.hpp"

Sprite::Sprite(SDL_Rect r) : rect{r} {}

Sprite::~Sprite()
{
    SDL_DestroyTexture(texture);
}

void Sprite::load_img(SDL_Renderer *rend, const char *str)
{
    texture = IMG_LoadTexture(rend, str);
}

void Sprite::load_text(SDL_Renderer *rend, const char *str, SDL_Color color, int size)
{
    auto font = TTF_OpenFont("assets/fonts/Staatliches-Regular.ttf", size*3);
    if (font == nullptr)
        std::cerr << TTF_GetError() << std::endl;

    auto surf = TTF_RenderUTF8_Blended(font, str, color);
    rect.w = surf->w / 3;
    rect.h = surf->h / 3;
    if (surf == nullptr)
        std::cerr << TTF_GetError() << std::endl;

    texture = SDL_CreateTextureFromSurface(rend, surf);
    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
}

void Sprite::draw(SDL_Renderer *rend)
{
    SDL_RenderCopyEx(rend, texture, nullptr, &rect,
                     angle, nullptr, SDL_FLIP_NONE);
}

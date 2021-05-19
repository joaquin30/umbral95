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

void Sprite::load_text(SDL_Renderer *rend, const char *str,
                       SDL_Color color, int size)
{
    auto font{TTF_OpenFont("assets/fonts/Staatliches-Regular.ttf", size)};
    auto surf{TTF_RenderUTF8_Blended(font, str, color)};
    texture = SDL_CreateTextureFromSurface(rend, surf);
    SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
}

void Sprite::set_animation(SDL_Rect src, SDL_Rect dest,
                           std::chrono::milliseconds msec, bool loop)
{
    animated = true;
    animation = [&](auto ticks) {
        return false;
    };
}

void Sprite::center_x(int mid) {
    rect.x = (mid*2 - rect.w)/2;
}

void Sprite::draw(SDL_Renderer *rend, int ticks)
{
    SDL_RenderCopyEx(rend, texture, nullptr, &rect,
                     angle, nullptr, SDL_FLIP_NONE);
    if (animated) {
        if (!animation(ticks))
            animated = false;
    }
}

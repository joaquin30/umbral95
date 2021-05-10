#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "utils.hpp"

class Sprite {
    SDL_Texture *texture;

public:
    SDL_Rect rect;
    Sprite(SDL_Renderer*, SDL_Rect&, const char*);
    ~Sprite();
    void draw(SDL_Renderer*);
};

#endif

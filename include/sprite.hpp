#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Sprite {
    SDL_Texture *texture;

public:
    double angle {0.};
    bool remove {false};
    SDL_Rect rect;
    Sprite(SDL_Rect);
    ~Sprite();
    void load_text(SDL_Renderer*, const char*, SDL_Color, int);
    void load_img(SDL_Renderer*, const char*);
    void draw(SDL_Renderer*);
};

#endif

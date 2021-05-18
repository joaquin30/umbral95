#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <iostream>
#include <functional>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Sprite {
    SDL_Texture *texture;
    std::function<void(int)> animation;

public:
    double angle{0.};
    bool animated{false};
    SDL_Rect rect;
    Sprite(SDL_Rect);
    ~Sprite();
    void load_text(SDL_Renderer*, const char*, SDL_Color, int);
    void load_img(SDL_Renderer*, const char*);
    void set_animation(std::function<void(int)>);
    void draw(SDL_Renderer*, int);
};

#endif

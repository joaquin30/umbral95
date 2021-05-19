#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <iostream>
#include <functional>
#include <chrono>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Sprite {
    SDL_Texture *texture;
    std::function<bool(int)> animation;

public:
    double angle{0.};
    bool animated{false};
    SDL_Rect rect;
    Sprite(SDL_Rect);
    ~Sprite();
    void load_text(SDL_Renderer*, const char*, SDL_Color, int);
    void load_img(SDL_Renderer*, const char*);
    void set_animation(SDL_Rect, SDL_Rect,
                       std::chrono::milliseconds, bool = false);
    void center_x(int = 960);
    void center_y(int = 540);
    void draw(SDL_Renderer*, int);
};

#endif

#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <iostream>

class Game {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    int width;
    int height;
    void manage_events();
    void draw();

public:
    Game();
    ~Game();
    int loop();
};

#endif

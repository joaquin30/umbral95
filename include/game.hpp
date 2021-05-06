#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <iostream>

class Game {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    void manage_events();
    void draw();

public:
    Game();
    ~Game();
    int loop();
};

#endif

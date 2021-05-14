#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <iostream>
#include <SDL2/SDL.h>
#include "scene.hpp"
#include "entities.hpp"

class Game {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    std::unique_ptr<Scene> scene;

public:
    Game();
    ~Game();
    int loop();
};

#endif

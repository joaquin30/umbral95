#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "home.hpp"
#include "instructions.hpp"
#include "game_room.hpp"


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

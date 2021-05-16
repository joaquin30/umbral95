#ifndef GAME_ROOM_HPP
#define GAME_ROOM_HPP

#include <random>
#include <SDL2/SDL.h>
#include "scene.hpp"

class GameRoom: public Scene {
public:
    GameRoom(SDL_Renderer*);
    state manage_events(SDL_Event) override;
    bool probability(int);
};


#endif

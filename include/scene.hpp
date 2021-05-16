#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <memory>
#include <SDL2/SDL.h>
#include "sprite.hpp"

extern SDL_Color white;
extern SDL_Color gray;

enum class state {
    home,
    instructions,
    game_room,
    exit
};

class Scene {
protected:
    std::vector<std::unique_ptr<Sprite>> sprites;

public:
    state name;
    void draw(SDL_Renderer*);
    virtual state manage_events(SDL_Event) = 0;
};

#endif

#ifndef SCENE_HPP
#define SCENE_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <SDL2/SDL.h>
#include "sprite.hpp"
#include "utils.hpp"

class Scene {
    state name;
    std::vector<std::unique_ptr<Sprite>> sprites;

public:
    Scene(SDL_Renderer*, state, const char*);
    virtual state manage_events(SDL_Event &event);
    void draw(SDL_Renderer*);
};

#endif

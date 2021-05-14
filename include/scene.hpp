#ifndef SCENE_HPP
#define SCENE_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <SDL2/SDL.h>
#include "sprite.hpp"
#include "utils.hpp"

class Scene {
    const char *bg {"/home/j30/Documentos/Proyectos/umbral95/assets/img/home.jpg"};
    std::vector<std::unique_ptr<Sprite>> sprites;

public:
    state name;
    Scene(SDL_Renderer*);
    void draw(SDL_Renderer*);
    virtual state manage_events(SDL_Event) = 0;
};

#endif

#ifndef ENTITIES_HPP
#define ENTITIES_HPP

#include "scene.hpp"

class Home : public Scene {
    const char *bg = "/home/j30/Documentos/Proyectos/umbral95/assets/img/home.jpg";
public:
    Home(SDL_Renderer *rend) : Scene{rend} {}
    state manage_events(SDL_Event event) override;
};

#endif

#ifndef HOME_HPP
#define HOME_HPP

#include <SDL2/SDL.h>
#include "scene.hpp"

class Home : public Scene {
public:
    Home(SDL_Renderer*);
    state manage_events(SDL_Event) override;
};

#endif

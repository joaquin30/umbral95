#ifndef INSTRUCTIONS_HPP
#define INSTRUCTIONS_HPP

#include <SDL2/SDL.h>
#include "scene.hpp"

class Instructions : public Scene {
public:
    Instructions(SDL_Renderer*);
    state manage_events(SDL_Event) override;
};


#endif

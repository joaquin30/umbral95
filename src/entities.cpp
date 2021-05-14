#include "entities.hpp"

state Home::manage_events(SDL_Event event)
{
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            return state::exit;

        case SDL_KEYDOWN:
            if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                return state::exit;

            break;

        default:
            break;
        }
    }

    return name;
}

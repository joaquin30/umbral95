#include "instructions.hpp"

Instructions::Instructions(SDL_Renderer *rend) : Scene{state::instructions}
{
    sprites.push_back(std::make_unique<Sprite>(SDL_Rect{0, 0, 1920, 1080}));
    sprites[0]->load_img(rend, "assets/img/instructions.jpg");
}

state Instructions::manage_events(SDL_Event event)
{
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            return state::exit;

        case SDL_KEYDOWN:
            switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_ESCAPE:
                return state::exit;

            case SDL_SCANCODE_RETURN:
                return state::home;

            default:
                break;
            }

            break;

        default:
            break;
        }
    }

    return name;
}

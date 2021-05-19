#include "home.hpp"

Home::Home(SDL_Renderer *rend) : Scene{state::home}
{
    sprites.push_back(std::make_unique<Sprite>(SDL_Rect{0, 0, 1920, 1080}));
    sprites[0]->load_img(rend, "assets/img/home.jpg");

    sprites.push_back(std::make_unique<Sprite>(SDL_Rect{240, 120, 0, 0}));
    sprites[1]->load_text(rend, "EL UMBRAL", white, 180);
    sprites[1]->center_x();

    sprites.push_back(std::make_unique<Sprite>(SDL_Rect{480, 300, 0, 0}));
    sprites[2]->load_text(rend, "DEL 95%", white, 180);
    sprites[2]->center_x();

    sprites.push_back(std::make_unique<Sprite>(SDL_Rect{0, 650, 0, 0}));
    sprites[3]->load_text(rend, "Pulsa Enter para empezar", white, 60);
    sprites[3]->center_x();

    sprites.push_back(std::make_unique<Sprite>(SDL_Rect{0, 750, 0, 0}));
    sprites[4]->load_text(rend, "Pulsa Escape para salir", gray, 50);
    sprites[4]->center_x();

    sprites.push_back(std::make_unique<Sprite>(SDL_Rect{0, 850, 0, 0}));
    sprites[5]->load_text(rend, "Pulsa C para ver los créditos", gray, 40);
    sprites[5]->center_x();
}

state Home::manage_events(SDL_Event event)
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
                return state::instructions;

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

/*
set_animation(SDL_Rect src, SDL_Rect dest, chrono::miliseconds msec, bool loop = false) {

}
*/

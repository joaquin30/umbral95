#include "home.hpp"

Home::Home(SDL_Renderer *rend) : Scene{state::home}
{
    sprites.push_back(std::make_unique<Sprite>(SDL_Rect{0, 0, 1920, 1080}));
    sprites[0]->load_img(rend, "assets/img/home.jpg");

    sprites.push_back(std::make_unique<Sprite>(SDL_Rect{240, 120, 0, 0}));
    sprites[1]->load_text(rend, "EL UMBRAL", white, 180);
    sprites[1]->rect.x = (1920 - sprites[1]->rect.w)/2;

    sprites.push_back(std::make_unique<Sprite>(SDL_Rect{480, 300, 0, 0}));
    sprites[2]->load_text(rend, "DEL 95%", white, 180);
    sprites[2]->rect.x = (1920 - sprites[2]->rect.w)/2;

    sprites.push_back(std::make_unique<Sprite>(SDL_Rect{750, 690, 0, 0}));
    sprites[3]->load_text(rend, "Enter", gray, 60);

    sprites.push_back(std::make_unique<Sprite>(SDL_Rect{990, 690, 0, 0}));
    sprites[4]->load_text(rend, "Jugar", white, 60);

    sprites.push_back(std::make_unique<Sprite>(SDL_Rect{750, 768, 0, 0}));
    sprites[5]->load_text(rend, "Escape", gray, 60);

    sprites.push_back(std::make_unique<Sprite>(SDL_Rect{990, 768, 0, 0}));
    sprites[6]->load_text(rend, "Salir", white, 60);
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

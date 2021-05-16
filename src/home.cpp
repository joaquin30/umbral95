#include "home.hpp"

Home::Home(SDL_Renderer *rend)
{
    sprites.push_back(std::make_unique<Sprite>(SDL_Rect{0, 0, 320, 180}));
    sprites[0]->load_img(rend, "assets/img/home.jpg");

    sprites.push_back(std::make_unique<Sprite>(SDL_Rect{40, 20, 0, 0}));
    sprites[1]->load_text(rend, "EL UMBRAL", white, 36);
    sprites[1]->rect.x = (320 - sprites[1]->rect.w)/2;

    sprites.push_back(std::make_unique<Sprite>(SDL_Rect{80, 50, 0, 0}));
    sprites[2]->load_text(rend, "DEL 95%", white, 36);
    sprites[2]->rect.x = (320 - sprites[2]->rect.w)/2;

    sprites.push_back(std::make_unique<Sprite>(SDL_Rect{125, 115, 0, 0}));
    sprites[3]->load_text(rend, "Enter", gray, 12);

    sprites.push_back(std::make_unique<Sprite>(SDL_Rect{165, 115, 0, 0}));
    sprites[4]->load_text(rend, "Jugar", white, 12);

    sprites.push_back(std::make_unique<Sprite>(SDL_Rect{125, 128, 0, 0}));
    sprites[5]->load_text(rend, "Escape", gray, 12);

    sprites.push_back(std::make_unique<Sprite>(SDL_Rect{165, 128, 0, 0}));
    sprites[6]->load_text(rend, "Salir", white, 12);

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

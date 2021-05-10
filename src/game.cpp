#include <game.hpp>

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Umbral del 95%",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              0, 0,
                              SDL_WINDOW_FULLSCREEN_DESKTOP);
    renderer = SDL_CreateRenderer(window, -1,
                                  SDL_RENDERER_ACCELERATED |
                                  SDL_RENDERER_PRESENTVSYNC);
    SDL_RenderSetLogicalSize(renderer, 320, 180);
}

Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int Game::loop()
{
    while (true) {
        switch (scene->manage_events(event)) {
        case state::home:
            break;

        case state::instructions:
            break;

        case state::game:
            break;

        default:
            return 0;
        }

        SDL_RenderClear(renderer);
        scene->draw(renderer);
        SDL_RenderPresent(renderer);
    }
}

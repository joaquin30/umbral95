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
    SDL_RenderSetLogicalSize(renderer, 1920, 1080);
    TTF_Init();
    scene = std::make_unique<Home>(renderer);
}

Game::~Game()
{
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int Game::loop()
{
    while (true) {
        auto tmp{scene->manage_events(event)};
        if (tmp != scene->name) {
            switch (tmp) {
            case state::home:
                scene = std::make_unique<Home>(renderer);
                break;

            case state::instructions:
                scene = std::make_unique<Instructions>(renderer);
                break;

            case state::game_room:
                scene = std::make_unique<GameRoom>(renderer);
                break;

            default:
                return 0;
            }
        }

        SDL_RenderClear(renderer);
        scene->draw(renderer);
        SDL_RenderPresent(renderer);
    }
}

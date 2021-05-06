#include <game.hpp>

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Umbral del 95%",
                              0, 0, 0, 0,
                              SDL_WINDOW_FULLSCREEN_DESKTOP);
    renderer = SDL_CreateRenderer(window, -1,
                                  SDL_RENDERER_ACCELERATED |
                                  SDL_RENDERER_PRESENTVSYNC);
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
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                return 0;
            }
        }
    }
}
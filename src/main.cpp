#include <iostream>
#include <game.h>

int main()
{
	using std::cerr;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        cerr << "error initializing SDL: " << SDL_GetError() << endl;
    
    auto win = SDL_CreateWindow("GAME",
                           SDL_WINDOWPOS_CENTERED,
                           SDL_WINDOWPOS_CENTERED,
                           1000, 1000, 0);
	while (true) ;
	return 0;
}

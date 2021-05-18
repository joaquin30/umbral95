#include "game_room.hpp"

GameRoom::GameRoom(SDL_Renderer *rend) : Scene{state::game_room}
{

}

state GameRoom::manage_events(SDL_Event event)
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

bool GameRoom::probability(int n)
{
    std::mt19937 rd{std::random_device{}()};
    std::uniform_int_distribution<> uid{0, 99};
    if (uid(rd) < n)
        return false;

    return true;
}

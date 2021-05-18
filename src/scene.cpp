#include "scene.hpp"

SDL_Color white {255, 255, 255, 255};
SDL_Color gray {230, 230, 230, 255};

Scene::Scene(state s) : name{s} {}

void Scene::draw(SDL_Renderer *rend)
{
    auto tmp{SDL_GetTicks()};
    tmp -= ticks;
    for (auto &it : sprites)
        it->draw(rend, tmp);

    ticks += tmp;
}

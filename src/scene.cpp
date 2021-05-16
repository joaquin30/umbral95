#include "scene.hpp"

SDL_Color white {255, 255, 255, 255};
SDL_Color gray {230, 230, 230, 255};

void Scene::draw(SDL_Renderer *rend)
{
    for (auto &it : sprites) {
        it->draw(rend);
        //std::cout<<i;
    }
}

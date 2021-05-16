#include "scene.hpp"

void Scene::draw(SDL_Renderer *rend)
{
    for (auto &it : sprites) {
        it->draw(rend);
        //std::cout<<i;
    }
}

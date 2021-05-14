#include "scene.hpp"

Scene::Scene(SDL_Renderer *rend)
{
    SDL_Rect r;
    r.x = r.y = 0;
    r.w = 320;
    r.h = 180;
    sprites.push_back(std::unique_ptr<Sprite>(new Sprite(rend, r, bg)));
}

void Scene::draw(SDL_Renderer *rend)
{
    for (auto &&it : sprites)
        it->draw(rend);
}

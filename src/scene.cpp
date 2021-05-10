#include "scene.hpp"

Scene::Scene(SDL_Renderer *rend, state n, const char *bg)
{
    sprites.push_back(std::make_unique<Sprite>(320, 180, rend, bg));
    name = n;
}

state Scene::manage_events(SDL_Event &event)
{
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            return state::exit;

        /*case SDL_KEYDOWN:
            if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                return state::exit;

            break;*/

        default:
            break;
        }
    }

    return name;
}

void Scene::draw(SDL_Renderer *rend)
{
    for (auto&& it : sprites)
        it->draw(rend);
}

#ifndef SCENE_HPP
#define SCENE_HPP

#include <algorithm>
#include "renderer.hpp"

enum class state {
    start,
    credits,
    instructions,
    game,
    none, //para quedarse en la escena y no hacer nada
    exit //para salir del juego
};

class Scene {
protected:
    const int SCREEN_WIDTH, SCREEN_HEIGHT;

public:
    std::vector<Sprite> sprites;
    std::vector<Label> labels;
    Scene(int w, int h) : SCREEN_WIDTH{w}, SCREEN_HEIGHT{h} {};
    virtual state manage_events(int, float) = 0;
};

#endif //SCENE_HPP

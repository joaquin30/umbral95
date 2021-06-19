#ifndef SCENE_HPP
#define SCENE_HPP

#include "renderer.hpp"

enum class state {
    start,
    credits,
    instructions,
    game,
    gameover,
    none, //para quedarse en la escena y no hacer nada
    exit //para salir del juego
};

class Scene {
public:
    float time_elapsed = 0;
    virtual ~Scene() {}
    virtual state update(int key) = 0;
    virtual void draw(Term::Renderer& r) = 0;
};

#endif //SCENE_HPP

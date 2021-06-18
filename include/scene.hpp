#ifndef SCENE_HPP
#define SCENE_HPP

#include "renderer.hpp"

enum class scene_enum {
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
    virtual ~Scene() {}
    virtual scene_enum update(int key) = 0;
    virtual void draw(Term::Renderer& r) = 0;
};

#endif //SCENE_HPP

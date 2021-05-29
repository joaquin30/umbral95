#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "cpp-terminal/terminal_renderer.hpp"

enum class state {
    start,
    credits,
    instructions,
    game,
    none, //para quedarse en la escena y no hacer nada
    exit //para salir del juego
};

class Scene {
public:
    std::vector<Term::Sprite> sprites;
    std::vector<Term::Label> labels;
    Scene() = default;
    virtual state manage_events(int, float) = 0;
};

#endif //SCENE_HPP

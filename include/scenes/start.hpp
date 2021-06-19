#ifndef START_SCENE_HPP
#define START_SCENE_HPP

#include "scene.hpp"
#include "entities/label.hpp"

class Start : public Scene {
    Label title {{(Term::WIDTH - 57) / 2.f,
                  (Term::HEIGHT - 19) / 2.f}};

public:
    Start();
    state update(int) override;
    void draw(Term::Renderer&) override;
};

#endif

#ifndef CREDITS_HPP
#define CREDITS_HPP

#include "scene.hpp"
#include "entities/label.hpp"

class Credits : public Scene {
    Label text {{(Term::WIDTH - 41) / 2.f,
                 (Term::HEIGHT - 25) / 2.f}};

public:
    Credits();
    state update(int) override;
    void draw(Term::Renderer& rend);
};

#endif

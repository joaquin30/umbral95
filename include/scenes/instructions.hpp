#ifndef INSTRUCTIONS_HPP
#define INSTRUCTIONS_HPP

#include "scene.hpp"
#include "entities/label.hpp"

class Instructions : public Scene {
    Label text {{(Term::WIDTH - 67) / 2.f,
                 (Term::HEIGHT - 23) / 2.f}};

public:
    Instructions();
    state update(int) override;
    void draw(Term::Renderer&) override;
};

#endif

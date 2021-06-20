#ifndef WIN_HPP
#define WIN_HPP

#include "scene.hpp"
#include "entities/label.hpp"

class Win : public Scene {
    Label text {{(Term::WIDTH - 54) / 2.f,
                 (Term::HEIGHT - 9) / 2.f}};

public:
    Win();
    state update(int) override;
    void draw(Term::Renderer& rend);
};

#endif

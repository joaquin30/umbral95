#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP

#include "scene.hpp"
#include "entities/label.hpp"

class GameOver : public Scene {
    Label text {{(Term::WIDTH - 56) / 2.f,
                 (Term::HEIGHT - 11) / 2.f}};

public:
    GameOver();
    state update(int) override;
    void draw(Term::Renderer& rend);
};

#endif

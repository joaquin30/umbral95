#ifndef LEVEL1_HPP
#define LEVEL1_HPP

#include <random>
#include <algorithm>
#include "scene.hpp"
#include "entities/player.hpp"
#include "entities/bullet.hpp"
#include "entities/enemy.hpp"
#include "entities/orb.hpp"
#include "entities/label.hpp"

class Level1 : public Scene {
    std::mt19937 rnd {std::random_device{}()};
    Player player {{Term::WIDTH/2.f, Term::HEIGHT/2.f}};
    Orb orb {{(float) randrange(20, Term::WIDTH - 20),
              (float) randrange(5, Term::HEIGHT - 5)}};
    Label lbl {{(Term::WIDTH - 3)/2.f, Term::HEIGHT - 3.f}};
    Label pnts {{3, 1}};
    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;
    unsigned probability = 100;
    bool new_enemy = true;
    int points = 0;

public:
    Level1();
    state update(int) override;
    unsigned randrange(unsigned, unsigned); // [uint, uint]
    unsigned randrange(unsigned); // [0, uint]
    bool implosion(unsigned);
    bool collision(Entity&, Entity&);
    void draw(Term::Renderer&) override;
};

#endif

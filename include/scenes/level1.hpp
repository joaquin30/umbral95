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
    Orb orb {{(float)(rnd() % Term::WIDTH),
              (float)(rnd() % Term::HEIGHT)}};
    Label lbl {{Term::WIDTH/2.f - 2, Term::HEIGHT - 3.f}, "100%"};
    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;
    int probability = 100;
    bool new_enemy = true;

public:
    Level1();
    state update(int) override;
    int random_range(int, int); // [int, int]
    int random_range(int); // [0, int]
    bool implosion(int);
    bool collision(Entity&, Entity&);
    void draw(Term::Renderer&) override;
};

#endif

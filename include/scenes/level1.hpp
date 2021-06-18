#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

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
    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;
    std::vector<Orb> orbs;
    Label lbl {{Term::WIDTH/2.f - 2, Term::HEIGHT - 3.f}, "100"};

public:
    Level1();
    scene_enum update(int) override;
    void draw(Term::Renderer&) override;
};

#endif

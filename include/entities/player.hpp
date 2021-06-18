#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity.hpp"
#include "bullet.hpp"

class Player : public Entity {
    float2 vel {0, -20};
    float e_vel = 20, angle = 0, ang_vel = 5;
    std::vector<float2> points {{0, -3}, {-2, 2}, {2, 2}};

public:
    Player(float2);
    void move_forward();
    void move_backwards();
    Bullet shoot();
    void rotate_right();
    void rotate_left();
    void draw(Term::Renderer&) override;
};

#endif

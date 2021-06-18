#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "entity.hpp"

class Enemy : public Entity {
    float2 vel;
    float e_vel = 4, angle = 0;
    std::vector<float2> points {{-2, -2}, {-2, 2}, {3, 0}};

public:
    Enemy(float2);
    void follow(float2);
    void draw(Term::Renderer&) override;
};

#endif

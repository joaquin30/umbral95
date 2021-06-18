#ifndef BULLET_HPP
#define BULLET_HPP

#include "entity.hpp"

class Bullet : public Entity {
    float2 vel;

public:
    Bullet(float2, float2);
    bool in_screen();
    void draw(Term::Renderer&) override;
};

#endif

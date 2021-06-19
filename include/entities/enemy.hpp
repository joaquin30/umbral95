#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "entities/sprite.hpp"

class Enemy : public Sprite {
public:
    Enemy(float2);
    void follow(float2);
};

#endif

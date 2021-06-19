#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entities/sprite.hpp"
#include "entities/bullet.hpp"

class Player : public Sprite {
public:
    Player(float2);
    Bullet shoot();
};

#endif

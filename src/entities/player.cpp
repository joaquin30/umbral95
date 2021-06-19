#include "entities/player.hpp"

Player::Player(float2 p) : Sprite{p}
{
    vel = {0, -20};
    e_vel = 20;
    angle = 0;
    ang_vel = 5;
    points = {{0, -3}, {-2, 2}, {2, 2}};
}

Bullet Player::shoot() { return Bullet{pos, 2*vel}; }

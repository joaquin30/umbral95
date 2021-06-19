#include "entities/enemy.hpp"

Enemy::Enemy(float2 p) : Sprite{p}
{
    e_vel = 4;
    angle = 0;
    ang_vel = 5;
    points = {{-1, -1}, {-1, 1}, {2, 0}};
}

void Enemy::follow(float2 p)
{
    float x = p.x - pos.x;
    float y =  -p.y + pos.y;
    if (x == 0 and y == 0)
        angle = 0;
    else if (y > 0)
        angle = -acosf(x / sqrtf(x*x + y*y));
    else
        angle = acosf(x / sqrtf(x*x + y*y));

    vel.x = e_vel * cosf(angle);
    vel.y = e_vel * sinf(angle);
    move_forward();
}

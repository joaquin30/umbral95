#include "entities/bullet.hpp"

Bullet::Bullet(float2 p, float2 v) : Entity{p}, vel{v} {}

bool Bullet::in_screen()
{
    return pos.x > 0 && pos.y > 0 &&
            pos.x < Term::WIDTH && pos.y < Term::HEIGHT;
}

void Bullet::draw(Term::Renderer& rend)
{
    rend.draw_pixel(pos.x, pos.y, 'o');
    pos += vel * Term::FPS;
}

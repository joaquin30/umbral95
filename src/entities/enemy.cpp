#include "entities/enemy.hpp"

Enemy::Enemy(float2 p) : Entity{p} {}

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

    vel.y = e_vel * sinf(angle);
    vel.x = e_vel * cosf(angle);
    pos += vel * Term::fps;
}

void Enemy::draw(Term::Renderer& rend)
{
    auto pnts = points;
    float2x2 m_rot {{cosf(angle), sinf(angle)},
                    {-sinf(angle), cosf(angle)}};
    for (int i = 0; i < 3; ++i)
        pnts[i] = linalg::mul(m_rot, points[i]);

    for (auto& i : pnts)
        i += pos;

    rend.draw_poligon(pnts, '$');
}

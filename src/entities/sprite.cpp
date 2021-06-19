#include "entities/sprite.hpp"

Sprite::Sprite(float2 p) : Entity{p} {}
Sprite::~Sprite() {}

void Sprite::move_forward() { pos += vel * Term::FPS; }

void Sprite::move_backwards() { pos -= vel * Term::FPS; }

void Sprite::rotate_right()
{
    angle += ang_vel * Term::FPS;
    vel.x = e_vel * sinf(angle);
    vel.y = e_vel * -cosf(angle);
}

void Sprite::rotate_left()
{
    angle -= ang_vel * Term::FPS;
    vel.x = e_vel * sinf(angle);
    vel.y = e_vel * -cosf(angle);
}

void Sprite::draw(Term::Renderer& rend)
{
    auto pnts = points;
    float2x2 m_rot {{cosf(angle), sinf(angle)}, {-sinf(angle), cosf(angle)}};
    for (int i = 0; i < 3; ++i)
        pnts[i] = linalg::mul(m_rot, points[i]);

    for (auto& i : pnts)
        i += pos;

    rend.draw_poligon(pnts);
}

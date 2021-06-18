#include "entities/player.hpp"

Player::Player(float2 p) : Entity{p} {}

void Player::move_forward() { pos += vel * Term::fps; }

void Player::move_backwards() { pos -= vel * Term::fps; }

Bullet Player::shoot() { return Bullet{pos, 2*vel}; }

void Player::rotate_right()
{
    angle += ang_vel * Term::fps;
    vel.x = e_vel * sinf(angle);
    vel.y = e_vel * -cosf(angle);
}

void Player::rotate_left()
{
    angle -= ang_vel * Term::fps;
    vel.x = e_vel * sinf(angle);
    vel.y = e_vel * -cosf(angle);
}

void Player::draw(Term::Renderer& rend)
{
    auto pnts = points;
    float2x2 m_rot {{cosf(angle), sinf(angle)}, {-sinf(angle), cosf(angle)}};
    for (int i = 0; i < 3; ++i)
        pnts[i] = linalg::mul(m_rot, points[i]);

    for (auto& i : pnts)
        i += pos;

    rend.draw_poligon(pnts);
}

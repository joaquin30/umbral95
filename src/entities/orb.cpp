#include "entities/orb.hpp"

Orb::Orb(float2 p) : Entity{p} {}

void Orb::set_pos(float x, float y)
{
    pos.x = x;
    pos.y = y;
}

void Orb::draw(Term::Renderer& rend)
{
    int x = pos.x, y = pos.y;
    for (auto i : "/\\\n\\/") {
        if (i == '\n') {
            x = pos.x;
            y++;
        } else {
            rend.draw_pixel(x, y, i);
            x++;
        }
    }
}

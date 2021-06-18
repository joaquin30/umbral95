#include "entities/label.hpp"

Label::Label(float2 p) : Entity{p} {}

Label::Label(float2 p, const std::string& s) : Entity{p}, str{s} {}

void Label::set_str(const std::string& s) {str = s;}

void Label::draw(Term::Renderer& rend)
{
    int x = pos.x, y = pos.y;
    for (auto i : str) {
        if (i == '\n') {
            x = pos.x;
            y++;
        } else {
            rend.draw_pixel(x, y, i);
            x++;
        }
    }
}

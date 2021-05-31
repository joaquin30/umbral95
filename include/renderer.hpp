#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <cmath>
#include <utility>
#include <iostream>
#include <cpp-terminal/terminal.h>

using point = std::pair<float, float>;

struct Sprite {
    float x, y;
    float dx, dy;
    float angle;
    char c;
    std::vector<point> points;
};

struct Label {
    float x, y;
    float dx, dy;
    std::string str;
};

class Renderer : public Term::Terminal {
    std::string buffer[2];
    int SCREEN_WIDTH, SCREEN_HEIGHT;

public:
    explicit Renderer(bool = false, bool = true);
    ~Renderer() override;
    int get_term_width();
    int get_term_height();
    void draw_pixel(int, int, char = '#');
    void draw_line(point, point, char = '#');
    void draw_poligon(const std::vector<point>&, char = '#');
    void draw_sprite(const Sprite&);
    void draw_label(const Label&);
    void render();
};

#endif //RENDERER_HPP

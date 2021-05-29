#ifndef TERMINAL_RENDERER_HPP
#define TERMINAL_RENDERER_HPP

#include <cmath>
#include <utility>
#include <fstream>
#include "terminal.hpp"

namespace Term {

using point = std::pair<float, float>;

struct Sprite {
    float x, y; //centro
    float dx, dy; //velocidad
    float angle;
    char c;
    std::vector<point> points; //vertices relativos
};

struct Label {
    float x, y; //esquina sup izq
    float dx, dy; //velocidad
    std::string str;
};

class TerminalRenderer : public Terminal {
    int SCREEN_WIDTH, SCREEN_HEIGHT;
    std::string buffer[2];
    //std::ofstream file{"log.txt"};

public:
    explicit TerminalRenderer(bool enable_keyboard = false,
                              bool disable_ctrl_c = true)
        : Terminal{enable_keyboard, disable_ctrl_c}
    {
        std::ios::sync_with_stdio(false);
        get_term_size(SCREEN_HEIGHT, SCREEN_WIDTH);
        buffer[0] = buffer[1] = std::string(SCREEN_WIDTH * SCREEN_HEIGHT, ' ');
        std::cout << Term::cursor_off();
    }

    ~TerminalRenderer() override
    {
        std::cout << Term::cursor_on();
        std::ios::sync_with_stdio(true);
        restore_screen();
    }

    void draw_pixel(point p, char c = '#')
    {
        int x = p.first, y = p.second;
        //coordenas forma de dona
        /*if (x < 0)
            x = SCREEN_WIDTH - 1;
        else if (x >= SCREEN_WIDTH)
            x %= SCREEN_WIDTH;

        if (y < 0)
            y = SCREEN_HEIGHT - 1;
        else if (y >= SCREEN_HEIGHT)
            y %= SCREEN_HEIGHT;*/

        //coordenas forma de plano
        if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
            buffer[1][y * SCREEN_WIDTH + x] = c;
    }

    void draw_line(point p1, point p2, char c = '#')
    {
        //mejorar y acortar
        int x1 = p1.first, x2 = p2.first, y1 = p1.second, y2 = p2.second;
        int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
        dx = x2 - x1;
        dy = y2 - y1;
        dx1 = abs(dx);
        dy1 = abs(dy);
        px = 2 * dy1 - dx1;
        py = 2 * dx1 - dy1;
        if (dy1 <= dx1) {
            if (dx >= 0) {
                x = x1;
                y = y1;
                xe = x2;
            } else {
                x = x2;
                y = y2;
                xe = x1;
            }

            draw_pixel({x, y}, c);
            for (i = 0; x<xe; i++) {
                x = x + 1;
                if (px < 0) {
                    px = px + 2 * dy1;
                } else {
                    if ((dx<0 && dy<0) || (dx>0 && dy>0))
                        y = y + 1;
                    else
                        y = y - 1;

                    px = px + 2 * (dy1 - dx1);
                }

                draw_pixel({x, y}, c);
            }
        } else {
            if (dy >= 0) {
                x = x1;
                y = y1;
                ye = y2;
            } else {
                x = x2;
                y = y2;
                ye = y1;
            }

            draw_pixel({x, y}, c);
            for (i = 0; y < ye; i++) {
                y = y + 1;
                if (py <= 0) {
                    py = py + 2 * dx1;
                } else {
                    if ((dx<0 && dy<0) || (dx>0 && dy>0))
                        x = x + 1;
                    else
                        x = x - 1;

                    py = py + 2 * (dx1 - dy1);
                }

                draw_pixel({x, y}, c);
            }
        }
    }

    void draw_poligon(const std::vector<point> &points, char c = '#')
    {
        for (int i = 0, len = points.size(); i < len +1; i++)
            draw_line(points[i % len], points[(i+1) % len], c);
    }

    void draw_sprite(const Sprite &sprite)
    {
        int len = sprite.points.size();
        std::vector<Term::point> pnts(len);
        float seno = sinf(sprite.angle), coseno = cosf(sprite.angle);
        //rotacion
        for (int i = 0; i < len; ++i) {
            pnts[i].first = sprite.points[i].first * coseno - sprite.points[i].second * seno;
            pnts[i].second = sprite.points[i].first * seno + sprite.points[i].second * coseno;
        }

        //traslacion
        for (auto& [x, y] : pnts) {
            x += sprite.x;
            y += sprite.y;
        }

        draw_poligon(pnts, sprite.c);
    }

    void draw_label(const Label& label)
    {
        int x = label.x, y = label.y;
        for (auto i : label.str) {
            if (i == '\n') {
                x = label.x;
                y++;
            } else {
                draw_pixel({x, y}, i);
                x++;
            }
        }
    }

    void render()
    {
        for (int i = 0; i < SCREEN_HEIGHT; ++i) {
            for (int j = 0; j < SCREEN_WIDTH; ++j) {
                auto pos = i * SCREEN_WIDTH + j;
                if (buffer[0][pos] != buffer[1][pos]) {
                    std::cout << Term::move_cursor(i + 1, j + 1);
                    std::cout << buffer[1][pos];
                }
            }
        }

        buffer[0] = buffer[1];
        std::fill(buffer[1].begin(), buffer[1].end(), ' ');
        std::cout << std::flush;
    }
};

} //namespace Term

#endif //TERMINAL_RENDERER_HPP

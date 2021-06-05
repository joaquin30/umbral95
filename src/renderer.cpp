#include "renderer.hpp"

Renderer::Renderer(bool enable_keyboard, bool disable_ctrl_c) :
    Term::Terminal(enable_keyboard, disable_ctrl_c)
{
    std::ios::sync_with_stdio(false);
    save_screen();
    get_term_size(SCREEN_HEIGHT, SCREEN_WIDTH);
    buffer[0] = buffer[1] = std::string(SCREEN_WIDTH * SCREEN_HEIGHT, ' ');
    std::cout << Term::cursor_off();
}

Renderer::~Renderer()
{
    std::cout << Term::cursor_on();
    std::ios::sync_with_stdio(true);
    restore_screen();
}

int Renderer::get_term_width() { return SCREEN_WIDTH; }
int Renderer::get_term_height() { return SCREEN_HEIGHT; }

void Renderer::draw_pixel(int x, int y, char c)
{
    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
        buffer[1][y * SCREEN_WIDTH + x] = c;
}


void Renderer::draw_line(point p1, point p2, char c)
{
    int x1 = std::lroundf(p1.first), x2 = std::lroundf(p2.first);
    int y1 = std::lroundf(p1.second), y2 = std::lroundf(p2.second);
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

        draw_pixel(x, y, c);
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

            draw_pixel(x, y, c);
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

        draw_pixel(x, y, c);
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

            draw_pixel(x, y, c);
        }
    }
}

void Renderer::draw_poligon(const std::vector<point> &points, char c)
{
    for (int i = 0, len = points.size(); i < len; i++)
        draw_line(points[i], points[(i+1 == len ? 0 : i+1)], c);
}

void Renderer::draw_sprite(const Sprite &sprite)
{
    int len = sprite.points.size();
    std::vector<point> pnts(len);
    float seno = sinf(sprite.angle), coseno = cosf(sprite.angle);
    for (int i = 0; i < len; ++i) {
        pnts[i].first = sprite.points[i].first * coseno -
                        sprite.points[i].second * seno;
        pnts[i].second = sprite.points[i].first * seno +
                            sprite.points[i].second * coseno;
    }

    for (auto& [x, y] : pnts) {
        x += sprite.x;
        y += sprite.y;
    }

    draw_poligon(pnts, sprite.c);
}

void Renderer::draw_label(const Label &label)
{
    int x = label.x, y = label.y;
    for (auto i : label.str) {
        if (i == '\n') {
            x = label.x;
            y++;
        } else {
            draw_pixel(x, y, i);
            x++;
        }
    }
}

void Renderer::render()
{
    for (int i = 0; i < SCREEN_HEIGHT; ++i) {
        for (int j = 0; j < SCREEN_WIDTH; ++j) {
            auto pos = i * SCREEN_WIDTH + j;
            if (buffer[0][pos] != buffer[1][pos])
                std::cout << Term::move_cursor(i+1, j+1) << buffer[1][pos];
        }
    }

    buffer[0] = buffer[1];
    std::fill(buffer[1].begin(), buffer[1].end(), ' ');
    std::cout << std::flush;
}

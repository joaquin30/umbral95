#include "renderer.hpp"

namespace Term {

float frames = 0.f;
int WIDTH = 0, HEIGHT = 0;

Renderer::Renderer(bool enable_keyboard, bool disable_ctrl_c)
: Term::Terminal(enable_keyboard, disable_ctrl_c)
{
    save_screen();
    get_term_size(HEIGHT, WIDTH);
    buffer[current] = buffer[next] = std::string(WIDTH * HEIGHT, ' ');
    std::ios::sync_with_stdio(false);
    std::cout << Term::cursor_off();
}

Renderer::~Renderer()
{
    std::cout << Term::cursor_on();
    std::ios::sync_with_stdio(true);
}

void Renderer::draw_pixel(int x, int y, char c)
{
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
        buffer[next][y * WIDTH + x] = c;
}

void Renderer::draw_line(float2 p1, float2 p2, char c)
{
    int x1 = p1.x, x2 = p2.x;
    int y1 = p1.y, y2 = p2.y;
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

void Renderer::draw_poligon(const std::vector<float2> &points, char c)
{
    for (int i = 0, len = points.size(); i < len; i++)
        draw_line(points[i], points[(i+1 == len ? 0 : i+1)], c);
}

void Renderer::render()
{
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            int pos = i * WIDTH + j;
            if (buffer[current][pos] != buffer[next][pos])
                std::cout << Term::move_cursor(i+1, j+1) << buffer[next][pos];
        }
    }

    std::swap(current, next);
    std::fill(buffer[next].begin(), buffer[next].end(), ' ');
    std::cout << std::flush;
}

} //namespace Term

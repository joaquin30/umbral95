#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <cmath>
#include <utility>
#include <iostream>
#include <string_view>
#include <cpp-terminal/terminal.h>
#include <linalg/linalg.h>

using namespace linalg::aliases;

namespace Term {

inline constexpr float fps = 1.f/30.f; //~30fps
extern float frames;
extern int WIDTH, HEIGHT;

class Renderer : public Terminal {
    std::string buffer[2];
    int current = 0, next = 1;

public:
    explicit Renderer(bool = false, bool = true);
    ~Renderer() override;
    void draw_pixel(int, int, char = '#');
    void draw_line(float2, float2, char = '#');
    void draw_poligon(const std::vector<float2>&, char = '#');
    void render();
};

} //namespace Term

#endif //RENDERER_HPP

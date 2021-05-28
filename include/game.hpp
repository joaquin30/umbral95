#ifndef GAME_HPP
#define GAME_HPP

#include <thread>
#include <chrono>
#include <memory>
#include <vector>
#include "terminal/terminal_renderer.hpp"
#include "start_scene.hpp"
#include "credits_scene.hpp"
#include "instructions_scene.hpp"
#include "game_scene.hpp"

class Game {
    Term::TerminalRenderer rend;
    std::unique_ptr<Scene> scene;
    state s;
    decltype(std::chrono::system_clock::now()) before, after;
    std::chrono::duration<float> time_elapsed;
    int SCREEN_WIDTH, SCREEN_HEIGHT;

public:
    Game();
    int loop();
};

#endif //GAME_HPP

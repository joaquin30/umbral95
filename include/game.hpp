#ifndef GAME_HPP
#define GAME_HPP

#include <thread>
#include <chrono>
#include <memory>
#include "scenes/start.hpp"
#include "scenes/credits.hpp"
#include "scenes/instructions.hpp"
#include "scenes/level1.hpp"
#include "scenes/gameover.hpp"

using namespace std::chrono;

class Game {
    Term::Renderer term{true, false};
    std::unique_ptr<Scene> scene = std::make_unique<Start>();
    decltype(system_clock::now()) previous = system_clock::now();
    decltype(system_clock::now()) current;
    duration<float> time_elapsed;
    float lag = 0;

public:
    int loop();
};

#endif //GAME_HPP

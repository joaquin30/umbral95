#ifndef UTILS_HPP
#define UTILS_HPP

#include <random>

enum class state {
    home,
    instructions,
    game,
    exit
};

bool flip100coins(int);

#endif

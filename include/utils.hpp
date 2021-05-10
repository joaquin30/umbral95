#ifndef UTILS_HPP
#define UTILS_HPP

#include <random>
#include <SDL2/SDL.h>

enum class state {
    home,
    instructions,
    game,
    exit
};

inline bool flip100coins(int n)
{
    std::random_device tmp;
    std::mt19937 rd(tmp());
    std::uniform_int_distribution<> uid(0, 99);
    if (uid(rd) < n)
        return false;

    return true;
}

#endif

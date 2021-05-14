#include "utils.hpp"

bool flip100coins(int n)
{
    std::random_device tmp;
    std::mt19937 rd(tmp());
    std::uniform_int_distribution<> uid(0, 99);
    if (uid(rd) < n)
        return false;

    return true;
}

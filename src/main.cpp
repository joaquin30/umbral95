#include "game.hpp"

int main() {
    int exit_code;
    try {
        Game umbral95;
        exit_code = umbral95.loop();
    } catch (...) {
        throw;
    }

    return exit_code;
}

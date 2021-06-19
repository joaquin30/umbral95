#include "scenes/gameover.hpp"

GameOver::GameOver()
{
    auto s = R"(__________                 .___.__          __
\______   \ ___________  __| _/|__| _______/  |_  ____
 |     ___// __ \_  __ \/ __ | |  |/  ___/\   __\/ __ \
 |    |   \  ___/|  | \/ /_/ | |  |\___ \  |  | \  ___/
 |____|    \___  >__|  \____ | |__/____  > |__|  \___  >
               \/           \/         \/            \/


           PRESIONA ENTER PARA JUGAR DE NUEVO

         PRESIONA ESC PARA IR AL MENU PRINCIPAL)";

    text.set_str(s);
}

state GameOver::update(int key)
{
    switch (key) {
    case 0:
        break;

    case Term::ESC:
        return state::start;

    case Term::ENTER:
        return state::level1;

    default:
        break;
    }

    return state::none;
}

void GameOver::draw(Term::Renderer& rend) { text.draw(rend); }

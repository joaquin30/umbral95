#include "scenes/start.hpp"

Start::Start()
{
    auto s = R"(___________.__                 ___.                .__
\_   _____/|  |    __ __  _____\_ |______________  |  |
 |    __)_ |  |   |  |  \/     \| __ \_  __ \__  \ |  |
 |        \|  |__ |  |  /  Y Y  \ \_\ \  | \// __ \|  |__
/_______  /|____/ |____/|__|_|  /___  /__|  (____  /____/
        \/                    \/    \/           \/
          .___     .__     ________._________   /\
        __| _/____ |  |   /   __   \   ____/ \ / /
       / __ |/ __ \|  |   \____    /____  \\_// /_
      / /_/ \  ___/|  |__    /    //       \ / // \
      \____ |\___  >____/   /____//______  // / \_/
           \/    \/                      \/ \/


                PRESIONA ENTER PARA EMPEZAR

                  PRESIONA ESC PARA SALIR

              PRESIONA C PARA VER LOS CREDITOS)";
    title.set_str(s);
}

state Start::update(int key)
{
    switch (key) {
    case 0:
        break;

    case Term::Key::ENTER:
        return state::game; //state::instructions;

    case Term::Key::ESC:
        return state::exit;

    case 'c':
    case 'C':
        return state::game; //state::credits;

    default:
        break;
    }

    return state::none;
}

void Start::draw(Term::Renderer &rend)
{
    title.draw(rend);
}

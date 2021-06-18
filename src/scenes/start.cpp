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

scene_enum Start::update(int key)
{
    switch (key) {
    case 0:
        break;

    case Term::Key::ENTER:
        return scene_enum::game; //scene_enum::instructions;

    case Term::Key::ESC:
        return scene_enum::exit;

    case 'c':
    case 'C':
        return scene_enum::game; //scene_enum::credits;

    default:
        break;
    }

    return scene_enum::none;
}

void Start::draw(Term::Renderer &rend)
{
    title.draw(rend);
}

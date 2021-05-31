#include "start_scene.hpp"

StartScene::StartScene(int w, int h) : Scene{w, h}
{
    auto title = R"(___________.__                 ___.                .__
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
    labels.push_back(Label{(float)(SCREEN_WIDTH - 57) / 2,
                           (float)(SCREEN_HEIGHT - 19) / 2,
                           0, 0, title});
}

state StartScene::manage_events(int key, float)
{
    switch (key) {
    case 0:
        break;

    case Term::Key::ENTER:
        return state::game;

    case Term::Key::ESC:
        return state::exit;

    case 'c':
    case 'C':
        return state::none;

    default:
        break;
    }

    return state::none;
}

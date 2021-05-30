#include "start_scene.hpp"

StartScene::StartScene(int w, int h) : SCREEN_WIDTH{w}, SCREEN_HEIGHT{h}
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
    labels.push_back(Term::Label{(float)(SCREEN_WIDTH - 57) / 2,
                                 (float)(SCREEN_HEIGHT - 19) / 2,
                                 0, 0, title});
    /*sprites.push_back(Term::Sprite{(float)SCREEN_WIDTH/2.f,
                                   (float)SCREEN_HEIGHT/2.f,
                                   0, 0, 0, '#',
                                   {{0, -4}, {-3, 3}, {3, 3}}});*/
}

state StartScene::manage_events(int key, float)
{
    switch (key) {
    case 0:
        break;

    case Term::Key::ENTER:
        return state::instructions;

    case Term::Key::ESC:
        return state::exit;

    case 'c':
    case 'C':
        return state::credits;

    default:
        break;
    }

    return state::none;
}
/*
state StartScene::manage_events(int key, float time_elapsed)
{
    sprites[0].dx = 20.f * sinf(sprites[0].angle);
	sprites[0].dy = 20.f * -cosf(sprites[0].angle);
    switch (key) {
    case 0:
        break;

    case Term::Key::ARROW_UP:
        sprites[0].x += sprites[0].dx * time_elapsed;
        sprites[0].y += sprites[0].dy * time_elapsed;
        break;

    case Term::Key::ARROW_DOWN:
        sprites[0].x -= sprites[0].dx * time_elapsed;
        sprites[0].y -= sprites[0].dy * time_elapsed;
        break;

    case Term::Key::ARROW_LEFT:
        sprites[0].angle -= 5.f * time_elapsed;
        break;

    case Term::Key::ARROW_RIGHT:
        sprites[0].angle += 5.f * time_elapsed;
        break;

    case 'x':
    case 'X':
        labels.push_back(Term::Label{sprites[0].x, sprites[0].y,
                                     sprites[0].dx / 15.f, sprites[0].dy / 15.f,
                                     "x"});
        break;

    case Term::ESC:
        return state::exit;

    default:
        break;
    }

    for (auto &i : labels) {
        i.x += i.dx;
        i.y += i.dy;
    }

    auto it = std::remove_if(labels.begin(), labels.end(),
    [&] (const auto &lbl) {
        return lbl.x < 0 || lbl.x >= SCREEN_WIDTH ||
                lbl.y < 0 || lbl.y >= SCREEN_HEIGHT;
    });

    labels.erase(it, labels.end());
    return state::none;
}
*/

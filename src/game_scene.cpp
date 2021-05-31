#include "game_scene.hpp"

GameScene::GameScene(int w, int h) : Scene{w, h}
{
    sprites.push_back(Sprite{(float)SCREEN_WIDTH/2.f,
                             (float)SCREEN_HEIGHT/2.f,
                             0, 0, 0, '#',
                             {{0, -4}, {-3, 3}, {3, 3}}});
}


state GameScene::manage_events(int key, float time_elapsed)
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
        labels.push_back(Label{sprites[0].x, sprites[0].y,
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

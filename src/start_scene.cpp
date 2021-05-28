#include "start_scene.hpp"

StartScene::StartScene(int w, int h) : SCREEN_WIDTH{w}, SCREEN_HEIGHT{h}
{
    sprites.push_back(Term::Sprite{(float)SCREEN_WIDTH / 2,
                                   (float)SCREEN_HEIGHT / 2,
                                   20, 20, 0, '#',
                                   {{0, -2}, {-1, 1}, {1, 1}}});
    labels.push_back(Term::Label{0, 0, "hola\nque haces"});
}

state StartScene::manage_events(int key, float time_elapsed)
{

    switch (key) {
    case 0:
        break;

    case Term::Key::ARROW_UP:
        sprites[0].y -= sprites[0].dy * time_elapsed;
        break;

    case 's':
    case 'S':
        sprites[0].y += sprites[0].dy * time_elapsed;
        break;

    case 'a':
    case 'A':
        sprites[0].x -= sprites[0].dx * time_elapsed;// * 3.f/2.f;
        break;

    case 'd':
    case 'D':
        sprites[0].x += sprites[0].dx * time_elapsed;// * 3.f/2.f;
        break;

    case Term::ESC:
        return state::exit;

    default:
        break;
    }

    return state::none;
}

#include "start_scene.hpp"

StartScene::StartScene(int w, int h) : SCREEN_WIDTH{w}, SCREEN_HEIGHT{h}
{
    sprites.push_back(Term::Sprite{(float) SCREEN_WIDTH/2.f,
                                   (float) SCREEN_HEIGHT/2.f,
                                   0, 0, 0, '#',
                                   {{0, -2}, {-3, 1}, {3, 1}}});
    labels.push_back(Term::Label{0, 0, 0, 0, "hola\nque haces"});
}

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

    case Term::ESC:
        return state::exit;

    default:
        break;
    }

    labels[0].str = "(" + std::to_string((int)sprites[0].x) + ", " +
                    std::to_string((int)sprites[0].y) + ", " +
                    std::to_string((int)sprites[0].angle) + ")";
    return state::none;
}

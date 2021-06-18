#include "game.hpp"

int Game::loop()
{
    while (true) {
        current = system_clock::now();
        time_elapsed = current - previous;
        previous = current;
        Term::frames += time_elapsed.count();
        lag += time_elapsed.count();
        std::this_thread::sleep_for(milliseconds(20));
        while (lag >= Term::fps) {
            switch (scene->update(term.read_key0())) {
            case scene_enum::none:
                break;

            case scene_enum::start:
                scene = std::make_unique<Start>();
                break;

            /*case scene_enum::credits:
                scene = std::make_unique<Credits>();
                break;

            case scene_enum::instructions:
                scene = std::make_unique<Instructions>();
                break;*/

            case scene_enum::game:
                scene = std::make_unique<Level1>();
                break;

            default:
                return 0;
            }

            lag -= Term::fps;
        }

        scene->draw(term);
        term.render();
    }
}

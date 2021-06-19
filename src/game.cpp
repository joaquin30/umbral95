#include "game.hpp"

int Game::loop()
{
    while (true) {
        current = system_clock::now();
        time_elapsed = current - previous;
        previous = current;
        lag += time_elapsed.count();
        std::this_thread::sleep_for(milliseconds(20));
        while (lag >= Term::FPS) {
            switch (scene->update(term.read_key0())) {
            case state::none:
                break;

            case state::start:
                scene = std::make_unique<Start>();
                break;

            /*case state::credits:
                scene = std::make_unique<Credits>();
                break;

            case state::instructions:
                scene = std::make_unique<Instructions>();
                break;*/

            case state::game:
                scene = std::make_unique<Level1>();
                break;

            default:
                return 0;
            }

            lag -= Term::FPS;
            scene->time_elapsed += Term::FPS;
        }

        scene->draw(term);
        term.render();
    }
}

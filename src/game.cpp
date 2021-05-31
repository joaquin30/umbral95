#include "game.hpp"

Game::Game() : SCREEN_WIDTH{rend.get_term_width()},
               SCREEN_HEIGHT{rend.get_term_height()}
{
    before = std::chrono::system_clock::now();
    scene = std::make_unique<StartScene>(SCREEN_WIDTH, SCREEN_HEIGHT);
    after = std::chrono::system_clock::now();
    time_elapsed = after - before;
}

int Game::loop()
{
    using namespace std::chrono_literals;
    while (true) {
        before = std::chrono::system_clock::now();
        std::this_thread::sleep_for(20ms);
        s = scene->manage_events(rend.read_key0(), time_elapsed.count());
        switch (s) {
        case state::none:
            break;

        case state::start:
            scene = std::make_unique<StartScene>(SCREEN_WIDTH, SCREEN_HEIGHT);
            break;

        case state::credits:
            scene = std::make_unique<CreditsScene>(SCREEN_WIDTH, SCREEN_HEIGHT);
            break;

        case state::instructions:
            scene = std::make_unique<InstructionsScene>(SCREEN_WIDTH,
                                                        SCREEN_HEIGHT);
            break;

        case state::game:
            scene = std::make_unique<GameScene>(SCREEN_WIDTH, SCREEN_HEIGHT);
            break;

        default:
            return 0;
        }

        for (auto &i : scene->sprites)
            rend.draw_sprite(i);

        for (auto &i : scene->labels)
            rend.draw_label(i);

        rend.render();
        after = std::chrono::system_clock::now();
        time_elapsed = after - before;
    }
}

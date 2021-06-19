#include "scenes/level1.hpp"

Level1::Level1() {}

state Level1::update(int key)
{
    switch (key) {
    case 0:
        break;

    case Term::Key::ARROW_UP:
        player.move_forward();
        break;

    case Term::Key::ARROW_DOWN:
        player.move_backwards();
        break;

    case Term::Key::ARROW_LEFT:
        player.rotate_left();
        break;

    case Term::Key::ARROW_RIGHT:
        player.rotate_right();
        break;

    case 'x':
    case 'X':
        bullets.push_back(player.shoot());
        break;

    case Term::ESC:
        return state::exit;

    default:
        break;
    }

    auto it = std::remove_if(bullets.begin(), bullets.end(),
              [] (Bullet& b) { return !b.in_screen(); });
    bullets.erase(it, bullets.end());

    if (time_elapsed > 5) {
        //orbs.push_back(Orb{{(float)(rnd() % Term::WIDTH),
        //                    (float)(rnd() % Term::HEIGHT)}});
        enemies.push_back(Enemy{{(float)(rnd() % 2 ? 0 : Term::WIDTH),
                                 (float)(rnd() % Term::HEIGHT)}});
        time_elapsed = 0;
    }

    for (auto& i : enemies)
        i.follow(player.get_pos());

    lbl.set_str(std::to_string(bullets.size()));

    /*
    //futuro sistema de colision (da error)

    for (auto& e : enemies) {
        it = std::remove_if(bullets.begin(), bullets.end(),
        [&] (Bullet& b) {
            return abs(b.pos.x - e.pos.x) < 2 && abs(b.pos.y - e.pos.y) < 2;
        });
    }

    decltype(enemies.begin()) it2;

    for (auto& b : bullets) {
        it2 = std::remove_if(enemies.begin(), enemies.end(),
        [&] (Enemy& e) {
            return abs(b.pos.x - e.pos.x) < 2 && abs(b.pos.y - e.pos.y) < 2;
        });
    }

    if (it != bullets.end())
        bullets.erase(it, bullets.end());

    if (it2 != enemies.end())
        enemies.erase(it2, enemies.end());*/
    return state::none;
}

void Level1::draw(Term::Renderer& rend)
{
    for (auto& i : bullets)
        i.draw(rend);

    for (auto& i : enemies)
        i.draw(rend);

    for (auto& i : orbs)
        i.draw(rend);

    player.draw(rend);
    lbl.draw(rend);
}

#include "scenes/level1.hpp"

Level1::Level1() {}

int Level1::random_range(int a, int b) { return a + (int) rnd() % (b+1); }

int Level1::random_range(int n) { return random_range(0, n); }

bool Level1::implosion(int n) { return random_range(99) > n; }

bool Level1::collision(Entity& e1, Entity& e2)
{
    return linalg::distance(e1.get_pos(), e2.get_pos()) < 3.5f;
}

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
        probability--;
        if (implosion(probability))
            return state::gameover;

        break;

    default:
        break;
    }

    //colision y seguimento de jugador y enemigos
    for (auto& e : enemies) {
        if (collision(player, e))
            return state::gameover;

        e.follow(player.get_pos());
    }

    lbl.set_str(std::to_string(probability) + "%");

    //generacion de enemigos
    if ((int) TIME_ELAPSED % 4) {
        if (new_enemy) {
            enemies.push_back(
                Enemy{{(float) (random_range(1) ? 0 : Term::WIDTH),
                       (float) random_range(Term::HEIGHT)}}
            );
            new_enemy = false;
        }
    } else {
        new_enemy = true;
    }

    //colision de orbe y jugador
    if (collision(orb, player)) {
        orb = Orb{{(float) random_range(20, Term::WIDTH - 20),
                   (float) random_range(5, Term::HEIGHT - 5)}};
        probability = 100;
    }

    //colision de balas y enemigos
    decltype(bullets.begin()) it1;
    decltype(enemies.begin()) it2;

    it1 = std::remove_if(bullets.begin(), bullets.end(),
        [&] (Bullet& b) {
            for (auto& e : enemies) {
                if (collision(e, b))
                    return true;
            }

            return !b.in_screen();
        });

    it2 = std::remove_if(enemies.begin(), enemies.end(),
    [&] (Enemy& e) {
        for (auto& b : bullets) {
            if (collision(e, b))
                return true;
        }

        return false;
    });

    bullets.erase(it1, bullets.end());
    enemies.erase(it2, enemies.end());
    return state::none;
}

void Level1::draw(Term::Renderer& rend)
{
    for (auto& i : bullets)
        i.draw(rend);

    for (auto& i : enemies)
        i.draw(rend);

    orb.draw(rend);
    player.draw(rend);
    lbl.draw(rend);
}

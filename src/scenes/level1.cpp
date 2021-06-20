#include "scenes/level1.hpp"

Level1::Level1() {}

unsigned Level1::randrange(unsigned a, unsigned b)
{
    return a + (rnd() % (b-a+1));
}

unsigned Level1::randrange(unsigned n) { return randrange(0, n); }

bool Level1::implosion(unsigned n) { return randrange(99) > n; }

bool Level1::collision(Entity& e1, Entity& e2)
{
    return linalg::distance(e1.pos, e2.pos) < 3.5f;
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

        e.follow(player.pos);
    }

    lbl.set_str(std::to_string(probability) + "%");
    pnts.set_str("Puntos: " + std::to_string(points));

    //generacion de enemigos
    if ((int) time_elapsed % 4) {
        if (new_enemy) {
            enemies.emplace_back(
                float2{(float) (randrange(1) ? 0 : Term::WIDTH),
                       (float) randrange(Term::HEIGHT)}
            );
            new_enemy = false;
        }
    } else {
        new_enemy = true;
    }

    //colision de orbe y jugador
    if (collision(orb, player)) {
        orb.pos = float2{(float) randrange(20, Term::WIDTH - 20),
                         (float) randrange(5, Term::HEIGHT - 5)};
        probability = 100;
        points++;
        if(points == 10)
            return state::win;
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
    pnts.draw(rend);
}

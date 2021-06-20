#include "scenes/instructions.hpp"

Instructions::Instructions()
{
    auto s = R"(    ____           __                       _
   /  _/___  _____/ /________  ____________(_)___  ____  ___  _____
   / // __ \/ ___/ __/ ___/ / / / ___/ ___/ / __ \/ __ \/ _ \/ ___/
 _/ // / / (__  ) /_/ /  / /_/ / /__/ /__/ / /_/ / / / /  __(__  )
/___/_/ /_/____/\__/_/   \__,_/\___/\___/_/\____/_/ /_/\___/____/


- Usa las flechas direccionales para manejar la nave.

- Usa X para disparar.

- El numero de abajo es la probabilidad de no explotar, esta se
  reduce con cada disparo.

- Si explotas o te toca una nave enemiga, pierdes.

- Para restaurar la probabilidad al 100%, coge los diamantes que
  saldran en el mapa. Ademas, te daran 1 punto.

- Consigue 10 puntos para ganar.


            PRESIONA ESC PARA VOLVER AL MENU PRINCIPAL)";

    text.set_str(s);
}

state Instructions::update(int key)
{
    switch (key) {
    case 0:
        break;

    case Term::ESC:
        return state::start;

    default:
        break;
    }

    return state::none;
}

void Instructions::draw(Term::Renderer& rend) { text.draw(rend); }

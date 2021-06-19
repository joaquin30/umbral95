#include "scenes/credits.hpp"

Credits::Credits()
{
    auto s = R"(   ______              ___ __
  / ____/_______  ____/ (_) /_____  _____
 / /   / ___/ _ \/ __  / / __/ __ \/ ___/
/ /___/ /  /  __/ /_/ / / /_/ /_/ (__  )
\____/_/   \___/\__,_/_/\__/\____/____/


     Universidad Catolica San Pablo
        Ciencia de la computacion
                CCOMP2-1

            Profesores:
            - Carlos Atencio
            - Manuel Loaiza

        Librerias:
        - linalg: Algebra lineal
        - cpp-terminal: Terminal

         Hecho por Joaquin Pino

                  2021


PRESIONA ESC PARA VOLVER AL MENU PRINCIPAL)";

    text.set_str(s);
}

state Credits::update(int key)
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

void Credits::draw(Term::Renderer& rend) { text.draw(rend); }

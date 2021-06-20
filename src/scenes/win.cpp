#include "scenes/win.hpp"

Win::Win()
{
    auto s = R"(  ________                               __
 /  _____/_____    ____ _____    _______/  |_  ____
/   \  ___\__  \  /    \\__  \  /  ___/\   __\/ __ \
\    \_\  \/ __ \|   |  \/ __ \_\___ \  |  | \  ___/
 \______  (____  /___|  (____  /____  > |__|  \___  >
        \/     \/     \/     \/     \/            \/


          PRESIONA ENTER IR AL MENU PRINCIPAL)";

    text.set_str(s);
}

state Win::update(int key)
{
    switch (key) {
    case 0:
        break;

    case Term::ENTER:
        return state::start;

    default:
        break;
    }

    return state::none;
}

void Win::draw(Term::Renderer& rend) { text.draw(rend); }

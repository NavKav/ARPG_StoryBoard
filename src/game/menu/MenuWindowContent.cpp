//
// Created by navid on 30/09/2022.
//

#include "game/menu/MenuWindowContent.h"

using namespace std;

void MenuWindowContent::process(Player& player, Window& window) {
    if (player[SDL_SCANCODE_UP].pressed) {
        cout << "start" << endl;
    }

}
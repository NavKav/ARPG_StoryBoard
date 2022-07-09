//
// Created by navid on 11/06/2022.
//

#include "game/GameWindowContent.h"

using namespace std;

void GameWindowContent::process(Player& player, Window& window) {
    static unsigned int a = 0, b = 0;
    static MapGenerator mapGenerator(200, 100, 15);
    static MapView mapView(window, mapGenerator);
    static bool c = true;

    if (c) {
        mapGenerator.generate();
        c = false;
    }

    if (player[SDL_SCANCODE_UP].pressed)
        b > 0 ? b -- : b = b;
    if (player[SDL_SCANCODE_DOWN].pressed)
        b ++;
    if (player[SDL_SCANCODE_LEFT].pressed)
        a > 0 ? a -- : a = a;
    if (player[SDL_SCANCODE_RIGHT].pressed){
        a ++;
    }

    mapView.display(a, b, 22, 22);
    window.refresh();
}
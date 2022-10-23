//
// Created by navid on 11/06/2022.
//

#include "game/GameWindowContent.h"

using namespace std;

void GameWindowContent::process(Player& player, Window& window) {
    static int a = 0, b = 0;
    static MapGenerator mapGenerator(200, 200, 1);
    static MapView mapView(window, mapGenerator);
    static bool c = true;

    if (c) {
        mapGenerator.generate();
        c = false;
    }

    if (player[SDL_SCANCODE_UP].pressed)
        b - 10 >= 0 ? b -= 10 : b = b;
    if (player[SDL_SCANCODE_DOWN].pressed)
        b += 10;
    if (player[SDL_SCANCODE_LEFT].pressed)
        a - 10 >= 0 ? a -= 10 : a = a;
    if (player[SDL_SCANCODE_RIGHT].pressed){
        a += 10;
    }

    mapView.displayGround(a, b, window.getX()/32, window.getY()/32);
    mapView.displayLiquid(a, b, window.getX()/32, window.getY()/32);
    Sleep(50);
    window.refresh();
}
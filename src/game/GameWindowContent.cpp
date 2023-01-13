//
// Created by navid on 11/06/2022.
//

#include "GameWindowContent.h"
#define P 1.1

using namespace std;

void GameWindowContent::process(Player& player, Window& window) {
    //_frameRate.display();

    static double a = 10.5, b = 10.5;
    static MapGenerator mapGenerator( 1);
    static MapView mapView(window, mapGenerator);
    static bool firstTime = true;

    if (firstTime) {
        window.drawOn(BACKGROUND);
        mapView.displayFromCoordinate(a, b);
        firstTime = false;
    }

    window.drawOn(BACKGROUND);
    Pair speed(0, 0);
    if (player[SDL_SCANCODE_UP].pressed) {
        b += P;
        speed += Pair(0, P);
    }
    if (player[SDL_SCANCODE_DOWN].pressed) {
        b += -P;
        speed += Pair(0, -P);
    }
    if (player[SDL_SCANCODE_LEFT].pressed) {
        a -= P;
        speed += Pair(P, 0);
    }
    if (player[SDL_SCANCODE_RIGHT].pressed){
        a += P;
        speed += Pair(-P, 0);
    }

    mapView.shiftMap(a, b, speed);
    window.refresh();
}
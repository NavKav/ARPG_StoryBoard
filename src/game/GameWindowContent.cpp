//
// Created by navid on 11/06/2022.
//

#include "game/GameWindowContent.h"
#define P 3.562

using namespace std;

void GameWindowContent::process(Player& player, Window& window) {
    _frameRate.display();

    static double a = 132.3, b = 210.9;
    static MapGenerator mapGenerator(400, 400, 1);
    static MapView mapView(window, mapGenerator);
    static bool firstTime = true;

    if (firstTime) {
        mapGenerator.generate();
        mapGenerator(a, b) = 17;
        window.drawOn(BACKGROUND);
        mapView.displayFromCoordinate(a, b);
        firstTime = false;
    }

    window.drawOn(BACKGROUND);
    double PAS = P;
    if (player[SDL_SCANCODE_UP].pressed) {
        b -= PAS;
        mapView.shiftMap(a, b, 0, PAS);
    }
    if (player[SDL_SCANCODE_DOWN].pressed) {
        b += PAS;
        mapView.shiftMap(a, b, 0, -PAS);
    }
    if (player[SDL_SCANCODE_LEFT].pressed) {
        a -= PAS;
        mapView.shiftMap(a, b, PAS, 0);
    }
    if (player[SDL_SCANCODE_RIGHT].pressed){
        a += PAS;
        mapView.shiftMap(a, b, -PAS, 0);
    }
    window.refresh();
}
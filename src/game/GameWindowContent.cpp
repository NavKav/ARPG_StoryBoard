//
// Created by navid on 11/06/2022.
//

#include "GameWindowContent.h"
#define P 1.1

using namespace std;

void GameWindowContent::process(Player& player, Window& window) {
    //_frameRate.display();

    static double a = -10, b = -10.1;
    static MapGenerator mapGenerator( 1);
    static MapView mapView(window, mapGenerator);
    static bool firstTime = true;

    if (firstTime) {
        window.drawOn(BACKGROUND);
        mapView.displayFromCoordinate(a, b);
        firstTime = false;
    }

    window.drawOn(BACKGROUND);
    double PAS = P;
    double aBlock = 0, bBlock = 0;
    if (player[SDL_SCANCODE_UP].pressed) {
        b -= PAS;
        aBlock += 0;
        bBlock += PAS;
    }
    if (player[SDL_SCANCODE_DOWN].pressed) {
        b += PAS;
        aBlock += 0;
        bBlock += -PAS;
    }
    if (player[SDL_SCANCODE_LEFT].pressed) {
        a -= PAS;
        aBlock += PAS;
        bBlock += 0;
    }
    if (player[SDL_SCANCODE_RIGHT].pressed){
        a += PAS;
        aBlock += -PAS;
        bBlock += 0;
    }
    if (player[SDL_SCANCODE_SPACE].pressed) {
        cout << a << " " << b << endl;
    }
    mapView.shiftMap(a, b, aBlock, bBlock);
    window.debug();
    window.refresh();
}
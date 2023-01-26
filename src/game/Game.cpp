//
// Created by navid on 23/01/2023.
//

#include "Game.h"

#define P 3.18 //0.18

using namespace std;

void Game::process(Player &player, Window &window) {
    _frameRate.display(window);

    static double x = 0, y = -10;
    static MapView mapView(window, _mapGenerator);

    static bool firstTime = true;
    if (firstTime) {
        window.drawOn(BACKGROUND);
        mapView.displayFromCoordinate(x, y);
        firstTime = false;
    }

    /*************************************************************************/
    /*************************  UNITS TESTS  *********************************/
    /*************************************************************************/
    NPCModel npcModel;
    NPCView npc(window, npcModel);
    npc.display(window.getX()/2, window.getY()/2);
    window.refresh();
}




/*
void Game::process(Player &player, Window &window) {
    _frameRate.display(window);

    static double a = 10.5, b = 10.5;
    static MapModel mapGenerator(1);
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
        speed(0, P);
    }
    if (player[SDL_SCANCODE_DOWN].pressed) {
        b += -P;
        speed(0, -P);
    }
    if (player[SDL_SCANCODE_LEFT].pressed) {
        a -= P;
        speed(P, 0);
    }
    if (player[SDL_SCANCODE_RIGHT].pressed){
        a += P;
        speed(-P, 0);
    }
    if (player[SDL_SCANCODE_SPACE].pressed){
        cout << speed.x() << endl;
        cout << speed.y() << endl << endl;
    }

    mapView.shiftMap(a, b, speed);
    window.refresh();
}
*/
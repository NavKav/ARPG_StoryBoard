//
// Created by navid on 11/06/2022.
//

#include "game/GameWindowContent.h"

using namespace std;

void GameWindowContent::process(Player& player, Window& window) {

    static bool initialized = false;
    if (!initialized) {
        MapGenerator mapGenerator(100, 100, 1);
        mapGenerator(0, 0) = 1;
        mapGenerator(0, 1) = 1;
        mapGenerator(1, 0) = 1;
        mapGenerator(1, 1) = 1;
        mapGenerator(1, 2) = 5;
        mapGenerator(1, 3) = 5;
        MapView mapView(window, mapGenerator);
        mapView.display(0, 0, 22, 22);
        window.refresh();
        initialized = true;
    }
}
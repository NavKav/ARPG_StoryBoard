//
// Created by navid on 23/01/2023.
//

#include "Game.h"

using namespace std;

void Game::process(Player &player, Window &window) {
    /*************************************************************************/
    /*************************  INITIALIZATION  ******************************/
    /*************************************************************************/
    srand(time(NULL));
    _frameRate.display(window);

    static MapView mapView(window, _mapGenerator);
    static double x = 0, y = 0;
    static bool firstTime = true;
    if (firstTime) {
        window.drawOn(BACKGROUND);
        mapView.displayFromCoordinate(x, y);
    }

    /*************************************************************************/
    /*************************  HERO TESTS  **********************************/
    /*************************************************************************/

    static HeroModel heroModel(player, x, y);
    static HeroView _heroView(heroModel, window);

    /*************************************************************************/
    /*************************  UNITS TESTS  *********************************/
    /*************************************************************************/
    static NPCModel npcModel1;
    static NPCView npc1(window, npcModel1);
    static NPCModel npcModel2;
    static NPCView npc2(window, npcModel2);
    static UnitModelHandler unitModelHandler;
    static UnitViewHandler unitViewHandler(window);


    if (firstTime) {
        unitModelHandler.add(&npcModel1);
        unitModelHandler.add(&npcModel2);
        unitModelHandler.add(&heroModel);

        unitViewHandler.add(&npc1);
        unitViewHandler.add(&npc2);
        unitViewHandler.add(&_heroView);

        firstTime = false;
    }

    unitViewHandler.add(&npc1);
    unitViewHandler.add(&npc2);
    unitViewHandler.add(&_heroView);

    unitModelHandler.play();
    mapView.shiftMap(heroModel.getX(), heroModel.getY(), heroModel.getSpeed());
    unitViewHandler.displayAll(heroModel.getX(), heroModel.getY());

    /*************************************************************************/
    /*************************  DISPLAY **************************************/
    /*************************************************************************/

    window.refresh();
}
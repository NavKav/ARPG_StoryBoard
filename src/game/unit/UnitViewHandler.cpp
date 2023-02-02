//
// Created by navid on 28/01/2023.
//

#include "UnitViewHandler.h"

using namespace std;

UnitViewHandler::UnitViewHandler(Window &window) :
_window(window)
{

}


UnitViewHandler::~UnitViewHandler() {
    /*
    for (auto x : _unitViewList) {
        delete x;
    }
     */
}

void UnitViewHandler::add(UnitView *unitView) {
    _unitViewList.insert(unitView);
}

void UnitViewHandler::displayAll(double heroX, double heroY) {
    double aCorner, bCorner;
    cornerFromHero(heroX, heroY, aCorner, bCorner);
    for (auto npc :_unitViewList) {
        if (npc->isInScreen(aCorner, bCorner)) {
            npc->display(aCorner, bCorner);
        }
    }
}

void UnitViewHandler::cornerFromHero(double heroX, double heroY, double &a, double &b) const {
    a = heroX - (double)_window.getX()/(2 * BLOCK_SIZE);
    b = heroY + (double)_window.getY()/(2 * BLOCK_SIZE);
}



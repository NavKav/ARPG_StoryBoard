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
    for (auto x : _unitViewList) {
        if (x == unitView) return;
    }
    _unitViewList.push_front(unitView);
}

void UnitViewHandler::displayAll(double heroX, double heroY) {
    _window.drawOn(DEFAULT);
    double aCorner, bCorner;
    cornerFromHero(heroX, heroY, aCorner, bCorner);
    sortUnitSet();
    for (auto npc :_unitViewList) {
        if (npc->isInScreen(aCorner, bCorner)) {
            npc->display(aCorner, bCorner);
        }
    }
    cout << endl;

}

void UnitViewHandler::cornerFromHero(double heroX, double heroY, double &a, double &b) const {
    a = heroX - (double)_window.getX()/(2 * BLOCK_SIZE);
    b = heroY + (double)_window.getY()/(2 * BLOCK_SIZE);
}

void UnitViewHandler::sortUnitSet() {
    _unitViewList.sort(cmp);

}

//
// Created by navid on 21/01/2023.
//

#include <iostream>
#include "NPCModel.h"

using namespace std;

NPCModel::NPCModel() {
    _health = 0;
    _maxHealth = 0;
    _name = "Golem";
    _x = rand()%10 - 5, _y = rand()%10 - 5;
}

NPCModel::NPCModel(double x, double y) :
NPCModel()
{
    _x = x;
    _y = y;
    cout << _x << " " << _y << endl;
}

UnitModel::UnitDecision NPCModel::play() {
    return MOVE_UP;
}

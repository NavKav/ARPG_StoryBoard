//
// Created by navid on 21/01/2023.
//

#include <iostream>
#include "NPCModel.h"
using namespace std;
void NPCModel::initialize() {
    _health = 0;
    _maxHealth = 0;
    _name = "Golem";
    _x = rand()%10 - 5, _y = rand()%10 - 5;
}

NPCModel::NPCModel() {
    initialize(); //!\\ TO-DO : move out of constructor
}

UnitModel::UnitDecision NPCModel::choice() {
    return UnitModel::MOVE_UP;
}

NPCModel::NPCModel(double x, double y) :
NPCModel()
{
    _x = x;
    _y = y;
    cout << _x << " " << _y << endl;
}

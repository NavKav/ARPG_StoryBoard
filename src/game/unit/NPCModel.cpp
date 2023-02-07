//
// Created by navid on 21/01/2023.
//

#include <iostream>
#include "NPCModel.h"

using namespace std;

NPCModel::NPCModel(HeroModel& heroModel) :
_heroModel(heroModel)
{
    _health = 0;
    _maxHealth = 0;
    _name = "Golem";
    _movementSpeed = 0.18;
    _x = rand()%10 - 5, _y = rand()%10 - 5;
}

NPCModel::NPCModel(double x, double y, HeroModel& heroModel) :
NPCModel(heroModel)
{
    _x = x;
    _y = y;
}

UnitModel::UnitDecision NPCModel::play() {
    return DO_NOTHING;
}

bool NPCModel::isHero() {
    return false;
}

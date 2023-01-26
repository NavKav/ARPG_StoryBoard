//
// Created by navid on 21/01/2023.
//

#include "NPCModel.h"

void NPCModel::initialize() {
    _health = 0;
    _maxHealth = 0;
    _name = "Golem";
    _x = 0, _y = 0;
}

NPCModel::NPCModel() {
    initialize();
}

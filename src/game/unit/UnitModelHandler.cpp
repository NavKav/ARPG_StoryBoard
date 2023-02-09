//
// Created by navid on 02/02/2023.
//

#include "UnitModelHandler.h"

void UnitModelHandler::add(UnitModel *unitModel) {
    _unitModelList.insert(unitModel);
}

void UnitModelHandler::play() {
    for (auto unit : _unitModelList) {
        applyChange(unit);
    }
}

void UnitModelHandler::applyChange(UnitModel* unit) {
    double P = unit->getMovementSpeed();
    unit->play();
    _auxBitset = unit->getDecision();
    unit->_speed = Speed(0, 0);
    if (_auxBitset[MOVE_UP]) {
        unit->_y += P;
        unit->_speed += Speed(0, P);
    } if (_auxBitset[MOVE_DOWN]) {
        unit->_y -= P;
        unit->_speed += Speed(0, -P);
    } if (_auxBitset[MOVE_LEFT]) {
        unit->_x -= P;
        unit->_speed += Speed(-P, 0);
    } if (_auxBitset[MOVE_RIGHT]) {
        unit->_x += P;
        unit->_speed += Speed(P, 0);
    }
    unit->getDecision().reset();
}

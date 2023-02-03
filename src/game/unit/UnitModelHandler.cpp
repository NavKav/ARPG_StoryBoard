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
    switch(unit->play()) {
        case UnitModel::MOVE_UP :
            unit->_y += P;
            unit->_speed = Speed(0, P);
            break;
        case UnitModel::MOVE_DOWN :
            unit->_y -= P;
            unit->_speed = Speed(0, -P);
            break;
        case UnitModel::MOVE_LEFT :
            unit->_x -= P;
            unit->_speed = Speed(-P, 0);
            break;
        case UnitModel::MOVE_RIGHT :
            unit->_x += P;
            unit->_speed = Speed(P, 0);
            break;
        case UnitModel::DO_NOTHING :
            unit->_speed = Speed(0, 0);
        default :
            break;
    }
}

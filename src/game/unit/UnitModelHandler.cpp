//
// Created by navid on 02/02/2023.
//

#include "UnitModelHandler.h"

#define P .18 //0.18

void UnitModelHandler::add(UnitModel *unitModel) {
    _unitModelList.insert(unitModel);
}

void UnitModelHandler::play() {
    for (auto unit : _unitModelList) {
        applyChange(unit);
    }
}

void UnitModelHandler::applyChange(UnitModel* unit) {
    switch(unit->play()) {
        case UnitModel::MOVE_UP :
            unit->_y += P;
            break;
        case UnitModel::MOVE_DOWN :
            unit->_y -= P;
            break;
        case UnitModel::MOVE_LEFT :
            unit->_x -= P;
            break;
        case UnitModel::MOVE_RIGHT :
            unit->_x += P;
            break;
        default :
            break;
    }
}

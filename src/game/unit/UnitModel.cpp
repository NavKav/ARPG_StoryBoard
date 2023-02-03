//
// Created by navid on 03/02/2023.
//

#include "UnitModel.h"

double UnitModel::getX() const {
    return _x;
}

double UnitModel::getY() const {
    return _y;
}

const Speed &UnitModel::getSpeed() const {
    return _speed;
}

double UnitModel::getMovementSpeed() const {
    return _movementSpeed;
}
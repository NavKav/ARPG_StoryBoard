//
// Created by navid on 02/02/2023.
//

#include "UnitModelHandler.h"

void UnitModelHandler::add(UnitModel *unitModel) {
    for (auto unit : _unitModelList) {
        if (unitModel == unit) return;
    }
    _unitModelList.insert(unitModel);
}

void UnitModelHandler::play() {
    _auxVector.clear();
    for (auto unitModel : _unitModelList) {
        _auxVector.insert(
                _auxVector.begin(),
                [unitModel, this] { unitModel->play();this->applyChange(unitModel); });
    }
    for (unsigned int i = _auxVector.size(); i < MAX_NUMBER_MODEL; i++) {
        _auxVector.emplace_back([](){});
    }
    const auto t = create_tuple<MAX_NUMBER_MODEL>(_auxVector);

    Encap x(MAX_NUMBER_MODEL);

    std::apply(x, t);
}

/**
 *
 * @warning must stay thread-safe
 */
void UnitModelHandler::applyChange(UnitModel* unit) {
    double P = unit->getMovementSpeed();
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

void UnitModelHandler::remove(UnitModel *unitModel) {
    auto it = _unitModelList.find(unitModel);
    if (it == _unitModelList.end())
        return;
    _unitModelList.erase(*it);
}

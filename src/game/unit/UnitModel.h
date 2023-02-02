//
// Created by navid on 25/01/2023.
//

#ifndef ARPG_STORYBOARD_UNITMODEL_H
#define ARPG_STORYBOARD_UNITMODEL_H

#include <string>
#include "util/Pair.h"

typedef Pair Speed;

class UnitModel {
    friend class UnitView;
    friend class NPCView;
public:
    virtual void initialize() = 0;
    virtual ~UnitModel() = default;

protected :
    enum UnitDecision {
        MOVE_UP = 1 << 0,
        MOVE_DOWN = 1 << 1,
        MOVE_LEFT = 1 << 2,
        MOVE_RIGHT = 1 << 3
    };

    int _health = 0;
    int _maxHealth = 0;
    std::string _name;
    double _x = 0, _y = 0;
    Speed _speed = Speed(0, 0);
};


#endif //ARPG_STORYBOARD_UNITMODEL_H

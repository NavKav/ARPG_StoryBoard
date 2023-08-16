//
// Created by navid on 25/01/2023.
//

#ifndef ARPG_STORYBOARD_UNITMODEL_H
#define ARPG_STORYBOARD_UNITMODEL_H

#include <string>
#include <bitset>
#include "util/Pair.h"
#include "game/index/UnitIndex.h"

typedef Pair Speed;

enum UnitDecision {
    DO_NOTHING,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
    COUNT
};

class UnitModel {
    friend class UnitView;
    friend class NPCView;
    friend class HeroView;
    friend class UnitModelHandler;
public:
    explicit UnitModel(const UnitIndex::UnitTemplate& unitTemplate);
    virtual void play() = 0;
    virtual bool isHero() = 0;
    virtual ~UnitModel() = default;
    double getX() const;
    double getY() const;
    double getMovementSpeed() const;
    const Speed& getSpeed() const;
    std::bitset<COUNT>& getDecision();
protected :
    unsigned int _health = 0;
    double _x = 0, _y = 0;

    Speed _speed = Speed(0, 0);

    std::bitset<COUNT> _decision;
private :
    UnitIndex::constUnitTemplate* _unitTemplate;
};


#endif //ARPG_STORYBOARD_UNITMODEL_H

//
// Created by navid on 25/01/2023.
//

#ifndef ARPG_STORYBOARD_UNITMODEL_H
#define ARPG_STORYBOARD_UNITMODEL_H

#include <string>

class UnitModel {
public:
    virtual void initialize() = 0;

protected :
    int _health = 0;
    int _maxHealth = 0;
    std::string _name;
    double _x = 0, _y = 0;
};


#endif //ARPG_STORYBOARD_UNITMODEL_H

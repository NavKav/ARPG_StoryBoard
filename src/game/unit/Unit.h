//
// Created by navid on 21/01/2023.
//

#ifndef ARPG_STORYBOARD_UNIT_H
#define ARPG_STORYBOARD_UNIT_H

#include <string>
#include "Displayable.h"

class Unit : private Displayable {
public :
    void display() override = 0;
private :
    int _health = 0;
    int _maxHealth = 0;
    std::string _name;
};


#endif //ARPG_STORYBOARD_UNIT_H

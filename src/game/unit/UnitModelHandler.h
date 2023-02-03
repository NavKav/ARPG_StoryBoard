//
// Created by navid on 02/02/2023.
//

#ifndef ARPG_STORYBOARD_UNITMODELHANDLER_H
#define ARPG_STORYBOARD_UNITMODELHANDLER_H

#include <set>
#include <iostream>
#include "game/unit/UnitModel.h"

class UnitModelHandler {
public :
    void add(UnitModel* unitModel);
    void play();
private :
    void applyChange(UnitModel* unit);

    std::set<UnitModel*> _unitModelList;

};


#endif //ARPG_STORYBOARD_UNITMODELHANDLER_H

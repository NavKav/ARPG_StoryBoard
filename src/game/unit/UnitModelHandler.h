//
// Created by navid on 02/02/2023.
//

#ifndef ARPG_STORYBOARD_UNITMODELHANDLER_H
#define ARPG_STORYBOARD_UNITMODELHANDLER_H

#include <set>
#include <iostream>
#include <vector>
#include <functional>
#include "game/unit/UnitModel.h"
#include "util/ConcurrentRunnerBase.h"

#define MAX_NUMBER_MODEL 100 // maximum number of unit model that can be managed by UnitModelHandler

class UnitModelHandler {
public :
    void add(UnitModel* unitModel);
    void remove (UnitModel* unitModel);
    void play();
private :
    void applyChange(UnitModel* unit);

    std::set<UnitModel*> _unitModelList;
    std::vector<std::function<TYPE>> _auxVector;
    std::bitset<COUNT> _auxBitset;
};


#endif //ARPG_STORYBOARD_UNITMODELHANDLER_H

//
// Created by David on 07/02/2023.
//

#include "game/unit/NPCModel.h"

#ifndef ARPG_STORYBOARD_BLACKBOARD_H
#define ARPG_STORYBOARD_BLACKBOARD_H


class Blackboard {
public:
    Blackboard(HeroModel& heroModel);
    HeroModel& getheromodel();
    // idem for the map
private:
    HeroModel& _heroModel;
    //map
};


#endif //ARPG_STORYBOARD_BLACKBOARD_H

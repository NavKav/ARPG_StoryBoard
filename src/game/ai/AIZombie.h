//
// Created by David on 08/02/2023.
//

#ifndef ARPG_STORYBOARD_AIZOMBIE_H
#define ARPG_STORYBOARD_AIZOMBIE_H
#include "game/unit/NPCModel.h"
#include "AI.h"

class AIZombie: public AI {
public:
    UnitModel::UnitDecision process(NPCModel& npcmodel) override;
    explicit AIZombie(Blackboard& blackboard);
private:
};


#endif //ARPG_STORYBOARD_AIZOMBIE_H

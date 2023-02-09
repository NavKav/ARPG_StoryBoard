//
// Created by David on 08/02/2023.
//

#ifndef ARPG_STORYBOARD_AI_H
#define ARPG_STORYBOARD_AI_H


#include "Blackboard.h"
#include "game/unit/UnitModel.h"

class AI {
public:
    virtual void process(NPCModel& npcmodel) = 0;
    AI(Blackboard& blackboard);
protected:
    Blackboard& _blackboard;
};


#endif //ARPG_STORYBOARD_AI_H

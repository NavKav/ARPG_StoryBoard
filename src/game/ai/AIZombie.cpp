//
// Created by David on 08/02/2023.
//

#include "AIZombie.h"

/**
*  a belongs to [b-n ; b+n]
*/
double in(double a, double b, int n) {
    return a > b - n && a < b + n;
}

void AIZombie::process(NPCModel& npcmodel) {

    double x = _blackboard.getheromodel().getX();
    double y = _blackboard.getheromodel().getY();
    if (!in(npcmodel.getX(), x, 1)) {
        npcmodel.getX() > x ? npcmodel.getDecision().set(MOVE_LEFT) : npcmodel.getDecision().set(MOVE_RIGHT);
    } if (!in(npcmodel.getY(), y, 1)) {
        npcmodel.getY() > y ? npcmodel.getDecision().set(MOVE_DOWN) : npcmodel.getDecision().set(MOVE_UP);
    }
    npcmodel.getDecision().set(DO_NOTHING);
}

AIZombie::AIZombie(Blackboard &blackboard) : AI(blackboard) {

}



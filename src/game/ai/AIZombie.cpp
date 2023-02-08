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

UnitModel::UnitDecision AIZombie::process(NPCModel& npcmodel) {

    double x = _blackboard.getheromodel().getX();
    double y = _blackboard.getheromodel().getY();
    if (!in(npcmodel.getX(), x, 1)) {
        return npcmodel.getX() > x ? UnitModel::MOVE_LEFT : UnitModel::MOVE_RIGHT;
    } else if (!in(npcmodel.getY(), y, 1)) {
        return npcmodel.getY() > y ? UnitModel::MOVE_DOWN : UnitModel::MOVE_UP;
    }
    return UnitModel::DO_NOTHING;
}

AIZombie::AIZombie(Blackboard &blackboard) : AI(blackboard) {

}



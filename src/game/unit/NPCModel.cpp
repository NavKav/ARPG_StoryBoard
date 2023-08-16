//
// Created by navid on 21/01/2023.
//

#include "NPCModel.h"
#include "game/ai/AIZombie.h"
#include <cmath>

using namespace std;

NPCModel::NPCModel(const UnitIndex::UnitTemplate& unitTemplate, HeroModel& heroModel) :
UnitModel(unitTemplate),
_heroModel(heroModel)
{
    _health = 400;
    _x = rand()%10 - 5, _y = rand()%10 - 5;
}

NPCModel::NPCModel(const UnitIndex::UnitTemplate& unitTemplate, double x, double y, HeroModel& heroModel) :
NPCModel(unitTemplate, heroModel)
{
    _x = x;
    _y = y;
}


/**
 *
 * @warning must stay thread-safe
 */
void NPCModel::play(){
    Blackboard blackboard(_heroModel);
    AIZombie ai(blackboard);
    return ai.process(*this);
}

bool NPCModel::isHero() {
    return false;
}

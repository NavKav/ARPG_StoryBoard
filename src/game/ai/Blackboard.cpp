//
// Created by David on 07/02/2023.
//

#include "Blackboard.h"


HeroModel& Blackboard::getheromodel() {
    return _heroModel;
}

Blackboard::Blackboard(HeroModel& heroModel) :
_heroModel(heroModel)
{}

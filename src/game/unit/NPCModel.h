//
// Created by navid on 21/01/2023.
//

#ifndef ARPG_STORYBOARD_NPCMODEL_H
#define ARPG_STORYBOARD_NPCMODEL_H

#include "UnitModel.h"
#include "HeroModel.h"

class NPCModel : public UnitModel {
public :
    NPCModel(HeroModel& heroModel);
    NPCModel(double x, double y, HeroModel& heroModel);
    UnitDecision play() override;
    bool isHero() override;
private :
    HeroModel& _heroModel;
};


#endif //ARPG_STORYBOARD_NPCMODEL_H

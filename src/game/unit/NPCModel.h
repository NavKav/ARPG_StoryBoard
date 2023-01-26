//
// Created by navid on 21/01/2023.
//

#ifndef ARPG_STORYBOARD_NPCMODEL_H
#define ARPG_STORYBOARD_NPCMODEL_H

#include "UnitModel.h"

class NPCModel : private UnitModel {
public :
    NPCModel();
    void initialize() override;
private :
};


#endif //ARPG_STORYBOARD_NPCMODEL_H

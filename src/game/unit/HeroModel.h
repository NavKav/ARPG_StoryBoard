//
// Created by navid on 26/01/2023.
//

#ifndef ARPG_STORYBOARD_HEROMODEL_H
#define ARPG_STORYBOARD_HEROMODEL_H

#include "UnitModel.h"
#include "core/Player.h"

class HeroModel : public UnitModel {
public :
    explicit HeroModel(Player& player);
    HeroModel(Player& player, double x, double y);
    bool isHero() override;
private :
    void play() override;
    Player& _player;
};


#endif //ARPG_STORYBOARD_HEROMODEL_H

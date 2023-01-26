//
// Created by navid on 23/01/2023.
//

#ifndef ARPG_STORYBOARD_GAME_H
#define ARPG_STORYBOARD_GAME_H

#include "core/Player.h"
#include "map/MapView.h"
#include "util/FrameRate.h"
#include "game/unit/NPCView.h"

class Game {
public :
    void process(Player& player, Window& window);
private :
    FrameRate _frameRate;
    MapModel _mapGenerator = MapModel(1);
};


#endif //ARPG_STORYBOARD_GAME_H

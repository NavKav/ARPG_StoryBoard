//
// Created by navid on 11/06/2022.
//

#ifndef ARPG_STORYBOARD_GAMEWINDOWCONTENT_H
#define ARPG_STORYBOARD_GAMEWINDOWCONTENT_H

#include "core/WindowContent.h"
#include "core/Player.h"
#include "game/map/MapView.h"

class GameWindowContent : public WindowContent {
public :
    void process(Player& player, Window& window) override;
private :

};


#endif //ARPG_STORYBOARD_GAMEWINDOWCONTENT_H

//
// Created by navid on 29/08/2021.
//

#ifndef DICE_GAME_PROJECT_WINDOWCONTENT_H
#define DICE_GAME_PROJECT_WINDOWCONTENT_H

#include "requirement.h"
#include "Input.h"

class Player;

class WindowContent {
public :
    virtual void process(Player& player) = 0;
};


#endif //DICE_GAME_PROJECT_WINDOWCONTENT_H

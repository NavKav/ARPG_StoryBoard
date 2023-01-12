//
// Created by navid on 30/09/2022.
//

#ifndef ARPG_STORYBOARD_MENUWINDOWCONTENT_H
#define ARPG_STORYBOARD_MENUWINDOWCONTENT_H

#include "../../core/Window.h"
#include "../../core/Player.h"
#include "../../core/WindowContent.h"
#include "../../core/Player.h"
#include "MenuButton.h"
#include "../option/OptionWindowContent.h"
#include "../GameWindowContent.h"

class MenuWindowContent : public WindowContent{
public :
    void process(Player& player, Window& window);
private :
};


#endif //ARPG_STORYBOARD_MENUWINDOWCONTENT_H
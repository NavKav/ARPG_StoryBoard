//
// Created by david on 21/10/2022.
//

#ifndef ARPG_STORYBOARD_OPTIONWINDOWCONTENT_H
#define ARPG_STORYBOARD_OPTIONWINDOWCONTENT_H

#include "../../core/WindowContent.h"
#include "WindowFrame.h"
#include "OptionLineToCheck.h"
#include "OptionLineMultiChoice.h"

class OptionWindowContent : public WindowContent {
public :
    void process(Player& player, Window& window);
private :
};


#endif //ARPG_STORYBOARD_OPTIONWINDOWCONTENT_H

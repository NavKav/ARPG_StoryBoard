//
// Created by God on 27/11/2022.
//

#ifndef ARPG_STORYBOARD_OPTIONLINETOCHECK_H
#define ARPG_STORYBOARD_OPTIONLINETOCHECK_H

#include "OptionLine.h"

class OptionLineToCheck : private OptionLine {
public:
    void display(int x, int y);
    OptionLineToCheck(std::string name,Window& window);
private:
    bool _checked = false;
};


#endif //ARPG_STORYBOARD_OPTIONLINETOCHECK_H

//
// Created by David on 27/11/2022.
//

#ifndef ARPG_STORYBOARD_OPTIONLINEMULTICHOICE_H
#define ARPG_STORYBOARD_OPTIONLINEMULTICHOICE_H
#define MARGE 1.2

#include <list>
#include <string>
#include "core/Window.h"
#include "OptionLine.h"

class OptionLineMultiChoice : private OptionLine {
public:
    void display(int x, int y);
    void insert(std::string choice);
    OptionLineMultiChoice(std::string name,Window& window);
private:
    std::list<std::string> _choices;
};


#endif //ARPG_STORYBOARD_OPTIONLINEMULTICHOICE_H

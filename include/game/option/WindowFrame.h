//
// Created by David on 23/10/2022.
//

#ifndef ARPG_STORYBOARD_WINDOWFRAME_H
#define ARPG_STORYBOARD_WINDOWFRAME_H

#include <list>
#include "core/WindowContent.h"
#include "OptionLine.h"

#define OPTION_SIZE 100
#define SHIFT 30

class WindowFrame {
public:
    WindowFrame(int number, Window& window);
    void display();
    void insert(OptionLine* ol);

private:
    Window& _window;
    int _numberOption;
    std::list<OptionLine*> _optionList;
};


#endif //ARPG_STORYBOARD_WINDOWFRAME_H

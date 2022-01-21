//
// Created by navid on 21/01/2022.
//

#ifndef ARPG_STORYBOARD_MENUCONTENT_H
#define ARPG_STORYBOARD_MENUCONTENT_H

#include <Window.h>
#include <WindowContent.h>

class MenuContent : public WindowContent{
public :
    MenuContent(Window* window);
    void process();
private :
};


#endif //ARPG_STORYBOARD_MENUCONTENT_H

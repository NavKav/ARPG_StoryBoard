//
// Created by David on 14/10/2022.
//

#ifndef ARPG_STORYBOARD_MENUBUTTON_H
#define ARPG_STORYBOARD_MENUBUTTON_H

#include "core/Window.h"

class MenuButton {
public :

    MenuButton(int xAxis, int yAxis, int width, int length, string path);
    void display(Window& window) const;
    bool isInside(int X, int Y);

private :
    int _abs,_ord,_dimAbs,_dimOrd;
    string _path = "/menu/option.png";
};


#endif //ARPG_STORYBOARD_MENUBUTTON_H

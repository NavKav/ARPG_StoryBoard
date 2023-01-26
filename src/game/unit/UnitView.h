//
// Created by navid on 21/01/2023.
//

#ifndef ARPG_STORYBOARD_UNITVIEW_H
#define ARPG_STORYBOARD_UNITVIEW_H

#include <string>
#include "Displayable.h"

class UnitView : private Displayable {
public :
    void display(int x, int y) override = 0;
protected :
};


#endif //ARPG_STORYBOARD_UNITVIEW_H

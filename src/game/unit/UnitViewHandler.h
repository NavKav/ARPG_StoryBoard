//
// Created by navid on 28/01/2023.
//

#ifndef ARPG_STORYBOARD_UNITVIEWHANDLER_H
#define ARPG_STORYBOARD_UNITVIEWHANDLER_H

#include <list>
#include <algorithm>
#include "game/map/MapView.h"
#include "UnitView.h"
#include "core/Window.h"

class UnitViewHandler {
public :
    UnitViewHandler(Window &window);
    ~UnitViewHandler();
    void add(UnitView* unitView);
    void displayAll(double heroX, double heroY);
private :
    struct {
        bool operator() (UnitView* a, UnitView* b) const {
            return !a->operator>(*b);
        }
    } cmp;

    Window& _window;
    std::list<UnitView*> _unitViewList;

    void cornerFromHero(double heroX, double heroY, double& a, double& b) const;
    void sortUnitSet();
};


#endif //ARPG_STORYBOARD_UNITVIEWHANDLER_H

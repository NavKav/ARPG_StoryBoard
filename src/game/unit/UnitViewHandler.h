//
// Created by navid on 28/01/2023.
//

#ifndef ARPG_STORYBOARD_UNITVIEWHANDLER_H
#define ARPG_STORYBOARD_UNITVIEWHANDLER_H

#include <set>
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
    struct cmp {
        bool operator() (UnitView* a, UnitView* b) const {
            if (a == b) return false;
            return !a->operator>(*b);
        }
    };

    Window& _window;
    std::set<UnitView*, cmp> _unitViewList;

    void cornerFromHero(double heroX, double heroY, double& a, double& b) const;
};


#endif //ARPG_STORYBOARD_UNITVIEWHANDLER_H

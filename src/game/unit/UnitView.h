//
// Created by navid on 21/01/2023.
//

#ifndef ARPG_STORYBOARD_UNITVIEW_H
#define ARPG_STORYBOARD_UNITVIEW_H

#include <string>
#include "Displayable.h"
#include "core/Window.h"
#include "UnitModel.h"
#include "game/map/MapView.h"

class UnitView : private Displayable {
public :
    UnitView(UnitModel& unitModel, Window& window);
    virtual void display(double x, double y) override = 0;
    virtual ~UnitView() = default;
    virtual bool isInScreen(double x, double y);
    bool operator>(const UnitView& aux) const;
    virtual bool isHero() = 0;
    const std::string& getName() const;

protected :
    UnitModel& _unitModel;
    Window& _window;
};

#endif //ARPG_STORYBOARD_UNITVIEW_H

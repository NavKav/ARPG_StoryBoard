//
// Created by navid on 26/01/2023.
//

#ifndef ARPG_STORYBOARD_HEROVIEW_H
#define ARPG_STORYBOARD_HEROVIEW_H

#include "UnitView.h"
#include "HeroModel.h"

class HeroView : public UnitView {
public :
    HeroView(HeroModel& heroModel, Window& window);
    void display(double xCorner, double yCorner) override;
    bool isInScreen(double x, double y) override;
    bool isHero() override;
private :
};


#endif //ARPG_STORYBOARD_HEROVIEW_H

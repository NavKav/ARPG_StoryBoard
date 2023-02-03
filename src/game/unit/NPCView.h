//
// Created by navid on 21/01/2023.
//

#ifndef ARPG_STORYBOARD_NPCVIEW_H
#define ARPG_STORYBOARD_NPCVIEW_H

#include "UnitView.h"
#include "NPCModel.h"
#include "core/Window.h"
#include "game/map/MapView.h"

#define DIST(a, b) ((a - b) < 0 ? b - a : a - b)

class NPCView : public UnitView{
public :
    NPCView(Window& window, UnitModel& unitModel);
    void display(double xCorner, double yCorner) override;
    bool isHero() override;
private :
};

#endif //ARPG_STORYBOARD_NPCVIEW_H

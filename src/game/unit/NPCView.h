//
// Created by navid on 21/01/2023.
//

#ifndef ARPG_STORYBOARD_NPCVIEW_H
#define ARPG_STORYBOARD_NPCVIEW_H

#include "UnitView.h"
#include "NPCModel.h"
#include "core/Window.h"

class NPCView : private UnitView{
public :
    NPCView(Window& window, NPCModel& npcModel);
    void display(int x, int y) override;
private :
    NPCModel& _npcModel;
    Window& _window;
};

#endif //ARPG_STORYBOARD_NPCVIEW_H

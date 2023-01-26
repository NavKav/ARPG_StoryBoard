//
// Created by navid on 21/01/2023.
//

#include "NPCView.h"

NPCView::NPCView(Window &window, NPCModel& npcModel) :
_window(window),
_npcModel(npcModel)
{

}

void NPCView::display(int x, int y) {
    _window.drawOn(DEFAULT);
    _window.drawIMG(x - 72, y - 144, "units/golem.png");
}
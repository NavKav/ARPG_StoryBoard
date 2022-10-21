//
// Created by david on 21/10/2022.
//

#include "game/option/OptionWindowContent.h"

void OptionWindowContent::process(Player& player, Window& window) {
    bool truc = false;
    if (truc == false) {
        window.drawIMG(0, 0, "fond.bmp");
        window.refresh();
        truc = true;
    }
}

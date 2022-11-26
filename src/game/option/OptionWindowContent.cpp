//
// Created by david on 21/10/2022.
//

#include "game/option/OptionWindowContent.h"

void OptionWindowContent::process(Player& player, Window& window) {
    window.clear();
    static int i, j;
    window.scaleIMG(-100, 0, i, j, "fond.bmp");
    i ++; j++;
    window.refresh();
}
